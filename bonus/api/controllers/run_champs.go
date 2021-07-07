package controllers

import (
	"Corewar_Api/logger"
	"Corewar_Api/models"
	"bytes"
	"fmt"
	"net/http"
	"os"
	"os/exec"
	"strings"

	"github.com/gin-gonic/gin"
	"github.com/gin-gonic/gin/binding"
)

func RunFight(c *gin.Context) {
	var out bytes.Buffer
	var championInList []models.DataChamps
	var args string

	err := c.ShouldBindBodyWith(&championInList, binding.JSON)
	if err != nil {
		logger.Log.Errorf("Failed to BindJSON  %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	originalLen := len(championInList)
	if originalLen > 4 {
		c.String(http.StatusBadRequest, "Too many champions you should not exceed 4 champions.")
		return
	}
	args = os.Getenv("BINARY_COREWAR")
	for i := 0; i < originalLen; i += 1 {
		temp, err := models.GetOneChamps(championInList[i].Name)
		if err != nil {
			logger.Log.Errorf("Champion's name not found  %v", err)
			c.String(http.StatusBadRequest, "The Champion : %s Not in the given database", championInList[i].Name)
			return
		}
		championInList[i].Path = temp.Path
		championInList[i].Defeats = temp.NumberOfDefeats
		championInList[i].Victory = temp.NumberOfVictory
		championInList[i].Id = temp.ID
		args = args + " " + os.Getenv("PATH_CHAMPS") + championInList[i].Path
	}
	fmt.Println(args)
	command := exec.Command("bash", "-c", args)
	command.Stdout = &out
	err = command.Run()
	if err != nil {
		logger.Log.Errorf("Unable to run the program : %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	temp := strings.Split(out.String(), "The player ")
	temp = strings.Split(temp[len(temp)-1], "(")
	temp = strings.Split(temp[1], ")")
	winnerName := temp[0]
	for i := 0; i < originalLen; i += 1 {
		if winnerName == championInList[i].Name {
			err = models.AddVictory(championInList[i].Victory, championInList[i].Id)
			if err != nil {
				logger.Log.Errorf("Unable to add point : %v", err)
				c.AbortWithStatus(http.StatusBadRequest)
				return
			}
		} else {
			err = models.AddDefeats(championInList[i].Defeats, championInList[i].Id)
			if err != nil {
				logger.Log.Errorf("Unable to lost point : %v", err)
				c.AbortWithStatus(http.StatusBadRequest)
				return
			}
		}
	}
	c.String(http.StatusOK, "The champion %s to win !", winnerName)
}
