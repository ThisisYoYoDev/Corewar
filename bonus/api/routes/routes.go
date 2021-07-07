package routes

import (
	"Corewar_Api/controllers"
	"github.com/gin-gonic/gin"
)

func Apply(r *gin.Engine)  {
	r.GET("/welcome", controllers.Welcome)

	r.POST("/addingChamps", controllers.AddingChampion)

	r.GET("/getChamps", controllers.DisplayChampions)
	r.POST("/runChamps", controllers.RunFight)
}