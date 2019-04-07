package units

import (
	"aweme-api/model"
	"crypto/tls"
	"encoding/base64"
	"encoding/json"
	"fmt"
	"github.com/gin-gonic/gin"
	"io/ioutil"
	"net/http"
	"strings"
)

func R(r *gin.Engine) {
	r.POST("/encryptDataWithTimeStamp_tran", r_encryptDataWithTimeStamp_tran)
	r.POST("/genHardInfo", r_genHardInfo)
	r.POST("/deviceReg", r_deviceReg)
	r.POST("/mixStringWithString", r_mixStringWithString)
	r.POST("/awemeJsonB64_decode_pri", r_awemeJsonB64_decode)
	r.POST("/awemeJsonB64_encode", r_awemeJsonB64_encode)
}



func r_encryptDataWithTimeStamp_tran(c *gin.Context) {
	loginUrl := fmt.Sprintf("http://192.168.31.206:8080/encryptDataWithTimeStamp")
	//proxy := func(_ *http.Request) (*url.URL, error) {
	//	return url.Parse("http://127.0.0.1:8080")
	//}
	transport := &http.Transport{
		//Proxy:           proxy,
		TLSClientConfig: &tls.Config{InsecureSkipVerify: true},
	}
	client := &http.Client{Transport: transport}
	//client := &http.Client{}
	paramaJson := c.PostForm("paramaJson")
	timeStamp := c.PostForm("timeStamp")

	postData := fmt.Sprintf("paramaJson=%s&timeStamp=%s", paramaJson, timeStamp)
	req, err := http.NewRequest("POST", loginUrl, strings.NewReader(postData))

	//req, err = http.NewRequest("POST", loginUrl, strings.NewReader(string("123123")))
	if err != nil {
		panic(err.Error())
	}
	//req.Header.Set("Content-Type", "application/octet-stream;tt-data=a")
	resp, err := client.Do(req)
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		panic(err)
	}
	c.String(http.StatusOK, string(body))
}

func r_genHardInfo(c *gin.Context) {
	var jIID model.Json_iid
	var carrier string
	sp := c.PostForm("sp")
	switch sp{
	case "0":
		carrier = GBK2Utf8("中国联通")
		break
	case "1":
		carrier = GBK2Utf8("中国移动")
		break
	default:
		c.JSON(http.StatusBadRequest, nil)
		return
	}
	json.Unmarshal([]byte(Json_IDD_Str_38), &jIID)
	//jIID.Header.Carrier = base64.StdEncoding.EncodeToString([]byte(GBK2Utf8("中国联通")))
	jIID.Header.Carrier = base64.StdEncoding.EncodeToString([]byte(carrier))
	jIID.Header.DisplayName = base64.StdEncoding.EncodeToString([]byte(jIID.Header.DisplayName))
	jIID.Header.Idfa = GenIDFA()
	jIID.Header.VendorID = GenUUID()
	jIID.Header.Openudid = GenOpenUDID()
	//jStr, err := json.Marshal(jIID)
	//if err != nil {
	//	panic(err.Error())
	//}
	c.JSON(http.StatusOK, jIID)
}

func r_mixStringWithString(c *gin.Context) {
	plainStr := c.PostForm("plainStr")
	c.String(http.StatusOK, MixStringWithString(plainStr))
}

func r_deviceReg(c *gin.Context) {
	//loginUrl := fmt.Sprintf("https://log.snssdk.com/service/2/device_register/?")
	hardInfo := c.PostForm("hardInfo")
	var jIID model.Json_iid
	json.Unmarshal([]byte(hardInfo), &jIID)
	displayName, err := base64.StdEncoding.DecodeString(jIID.Header.DisplayName)
	if err != nil {
		panic(err)
	}
	jIID.Header.DisplayName = string(displayName)
	carrier, err := base64.StdEncoding.DecodeString(jIID.Header.Carrier)
	if err != nil {
		panic(err)
	}
	jIID.Header.Carrier = string(carrier)
	c.String(http.StatusOK, base64.StdEncoding.EncodeToString(Serialize(jIID)))
}

func r_awemeJsonB64_decode(c *gin.Context) {
	cypherText := c.PostForm("cypherText")
	c.String(http.StatusOK, AwemeJsonB64_decode(cypherText))
}

func r_awemeJsonB64_encode(c *gin.Context) {
	plainText := c.PostForm("plainText")
	c.String(http.StatusOK, AwemeJsonB64_encode(plainText))
}
