package controllers

import (
	"Corewar_Api/logger"
	"Corewar_Api/models"
	"github.com/gin-gonic/gin"
	"net/http"
)

func DisplayChampions(c *gin.Context) {
	allChamps, err := models.GetAllChamps()
	if err != nil {
		logger.Log.Errorf("Unable to retrieve the list of champions :  %v", err)
		c.AbortWithStatus(http.StatusBadRequest)
		return
	}
	array := make([]struct{
		Name		string
		Victories   int
		Defeats		int
	}, len(allChamps))
	for i, champ := range allChamps {
		array[i].Name = champ.Name
		array[i].Victories = champ.NumberOfVictory
		array[i].Defeats = champ.NumberOfDefeats
	}
	c.JSON(http.StatusOK, array)
}
