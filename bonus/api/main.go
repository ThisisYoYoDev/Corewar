package main

import (
	"Corewar_Api/database"
	"Corewar_Api/logger"
	"Corewar_Api/routes"
	"Corewar_Api/server"
	"github.com/gin-gonic/gin"
	"log"

	_ "github.com/joho/godotenv/autoload"
	_ "github.com/lib/pq"
)

func CORS() gin.HandlerFunc {
	return func(c *gin.Context) {
		c.Writer.Header().Set("Access-Control-Allow-Origin", "*")
		c.Writer.Header().Set("Access-Control-Allow-Credentials", "true")
		c.Writer.Header().Set("Access-Control-Allow-Headers", "Content-Type, Content-Length, Accept-Encoding, X-CSRF-Token, Authorization, accept, origin, Cache-Control, X-Requested-With")
		c.Writer.Header().Set("Access-Control-Allow-Methods", "POST, OPTIONS, GET, PUT, DELETE")

		if c.Request.Method == "OPTIONS" {
			c.AbortWithStatus(204)
			return
		}
		c.Next()
	}
}

func main() {
	err := logger.CreateNewLogger()
	if err != nil {
		log.Fatalf("Failed to Create Logger: %v", err)
	}
	client, err := database.NewDatabase()
	if err != nil {
		logger.Log.Errorf("Failed to Create DB : %v", err)
	}
	defer client.Def.Close()
	myServer := server.NewServer()
	myServer.Def.Use(CORS())
	routes.Apply(myServer.Def)
	myServer.Def.Run()
}
