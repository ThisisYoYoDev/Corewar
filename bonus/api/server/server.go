package server

import "github.com/gin-gonic/gin"

type Server struct {
	Def *gin.Engine
}

func NewServer() Server {
	server := Server{Def: gin.Default()}
	return server
}