package controllers

import (
	"github.com/gin-gonic/gin"
	"net/http"
)

func Welcome(c *gin.Context) {
	c.String(http.StatusOK, "Welcome !")
}
