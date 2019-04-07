package main

import (
	"github.com/gin-gonic/gin"
	"aweme-api/units"
)

func main() {
	r := gin.Default()
	units.R(r)
	// Listen and serve on 0.0.0.0:8080
	r.Run(":9999")
}
