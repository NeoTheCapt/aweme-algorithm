package Test

import (
	"testing"
	"net/url"
	"aweme-api/units"
)

func TestJson2B64(t *testing.T) {
	cypherText := "5pe9vb%2F%2B9OnkwvP88Pi%2Fvae9v3sVDXQeIL%2Bxl729v%2B7o%2F%2FD06cLp9PD4v72nvayo%0D%0Arqmkrq2rqKWzpaikq66upJfg"
	cypherText, err := url.QueryUnescape(cypherText)
	if err!=nil{
		t.Error(err.Error())
	}
	units.AwemeJsonB64_decode(cypherText)
	plainText := units.AwemeJsonB64_decode(cypherText)
	println(plainText)
	cypherText = units.AwemeJsonB64_encode(plainText)
	println(cypherText)

	//if val != "hello" {
	//	t.Error("Set Field")
	//}
}