package controllers

import (
	"Corewar_Api/logger"
	"Corewar_Api/models"
	"bytes"
	"github.com/gin-gonic/gin"
	"github.com/gin-gonic/gin/binding"
	"net/http"
	"os"
	"os/exec"
)

func AddingChampion(c *gin.Context) {
	var out bytes.Buffer

	dataImport := models.DataChamps{}
	err := c.ShouldBindBodyWith(&dataImport, binding.JSON)
	if err != nil {
		logger.Log.Errorf("Failed to BindJSON  %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	dataImport.Path = dataImport.Name + ".s"
	status, err := Exists(dataImport.Path)
	if status == true {
		logger.Log.Errorf("The name of the champion already exists : %v", err)
		c.String(http.StatusBadRequest, "The name of the champion you have chosen already exists, please change the name")
		return
	}
	file, err := os.OpenFile(dataImport.Name + ".s", os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0600)
	defer file.Close()
	if err != nil {
		logger.Log.Errorf("Unable to open the file request :  %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	_, err = file.WriteString(dataImport.DataCode)
	if err != nil {
		logger.Log.Errorf("Unable to write the file request :  %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	command := exec.Command(os.Getenv("BINARY_ASM"), dataImport.Path)
	command.Stdout = &out
	err = command.Run()
	if err != nil {
		logger.Log.Errorf("Unable to run the program :  %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	dataImport.Path = dataImport.Name + ".cor"
	newChamp, err := models.CreateChamps(dataImport)
	if err != nil {
		logger.Log.Errorf("Impossible to create a new champion :  %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	c.String(http.StatusOK, "Your champion is now part of the network!\nWe welcome %s", newChamp.Name)
}