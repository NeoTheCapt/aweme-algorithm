package units

/*
#cgo CFLAGS: -I/Users/SomePath/dev/C++/aweme_aes/
#cgo LDFLAGS: -lstdc++
//#cgo LDFLAGS: -L/Users/SomePath/dev/C++/aweme_aes/cmake-build-debug -llibaweme_aes
//#include "main.h"
#cgo LDFLAGS: -ldl
#include "bridge.h"
*/
import "C"
import (
	"encoding/hex"
	"unsafe"
	"bytes"
	"compress/gzip"
	"io"
	"encoding/json"
	"fmt"
	"github.com/axgle/mahonia"
	"crypto/md5"
	"math/rand"
	"time"
	"github.com/satori/go.uuid"
	"aweme-api/model"
	"encoding/base64"
)

//var EXTENSION_DIR string = "/Users/SomePath/dev/C++/aweme_aes/cmake-build-debug/"
var EXTENSION_DIR string = "/root/dev/aweme_aes/"
var OIDB_API string = "libaweme_aes.so"
//来自抖音函数 mixStringWithString
func MixStringWithString(plainStr string) string {
	var rst string = ""
	var cryptStr string = ""
	for _, v := range plainStr {
		char := byte(v) ^ 5
		cryptStr += hex.EncodeToString([]byte{char})
	}
	rst = cryptStr
	return rst
}

func IIDEncrypt(plainStr []byte) []byte {
	CplainStr := C.CString(string(plainStr))
	defer C.free(unsafe.Pointer(CplainStr))
	plainlength := len(plainStr)
	libPathC := C.CString(EXTENSION_DIR + OIDB_API)
	defer C.free(unsafe.Pointer(libPathC))
	encryptedLength := plainlength + 4 + (16 - plainlength%16)
	CKeyStr := C.CString("!*ss!_defaul%t54K&EY")
	defer C.free(unsafe.Pointer(CKeyStr))
	CEncryptedStr := C.encode(libPathC, CplainStr, C.int(encryptedLength), CKeyStr, C.int(20))
	defer C.free(unsafe.Pointer(CEncryptedStr))
	encryptedStr := C.GoBytes(unsafe.Pointer(CEncryptedStr), C.int(encryptedLength))
	//encryptedHexStr := hex.EncodeToString(encryptedStr)
	return encryptedStr
}

func Test(plainStr string) int {
	libPathC := C.CString(EXTENSION_DIR + OIDB_API)
	defer C.free(unsafe.Pointer(libPathC))
	return int(C.test(libPathC))
	//C.test1()
}

func GUnzipData(data []byte) (resData []byte, err error) {
	b := bytes.NewBuffer(data)

	var r io.Reader
	r, err = gzip.NewReader(b)
	if err != nil {
		return
	}

	var resB bytes.Buffer
	_, err = resB.ReadFrom(r)
	if err != nil {
		return
	}

	resData = resB.Bytes()

	return
}

func GZipData(data []byte) (compressedData []byte, err error) {
	var b bytes.Buffer
	gz := gzip.NewWriter(&b)

	_, err = gz.Write(data)
	if err != nil {
		return
	}

	if err = gz.Flush(); err != nil {
		return
	}

	if err = gz.Close(); err != nil {
		return
	}

	compressedData = b.Bytes()

	return
}

func JsonStr2Getparam(jsonStr []byte) string {
	var getParamStr string
	var data map[string][]map[string]interface{}
	err := json.Unmarshal(jsonStr, &data)
	if err != nil {
		panic(err.Error())
	}
	for k, v := range data {
		getParamStr += fmt.Sprintf("%s=%s&", k, v)
	}
	return getParamStr
}

func Utf82GBK(utf8Str string) string {
	enc := mahonia.NewEncoder("GBK")
	output := enc.ConvertString(utf8Str)
	return output
}

func GBK2Utf8(gbkStr string) string {
	enc := mahonia.NewDecoder("GBK")
	output := enc.ConvertString(gbkStr)
	return output
}

// 生成32位MD5
func MD5(text string) string {
	ctx := md5.New()
	ctx.Write([]byte(text))
	return hex.EncodeToString(ctx.Sum(nil))
}

// return len=8  salt
func GetRandomSalt() string {
	return GetRandomString(8)
}

//生成随机字符串
func GetRandomString(length int) string {
	str := "0123456789abcdef"
	bytes := []byte(str)
	result := []byte{}
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < length; i++ {
		result = append(result, bytes[r.Intn(len(bytes))])
	}
	return string(result)
}

func GenUUID() string {
	u4 := uuid.NewV5(uuid.NewV4(), "aweme")
	return u4.String()
}

func GenOpenUDID() string {
	//return fmt.Sprintf("%s%s", MD5(globallyUniqueString), GetRandomString(8))
	return fmt.Sprintf("%s%s%s", "222ae7d", GetRandomString(25), "11222222")
}

func GenIDFA() string {
	//return fmt.Sprintf("%s%s", MD5(globallyUniqueString), GetRandomString(8))
	return fmt.Sprintf("%s%s", "DFCF4ABE-ECEB-4FCC-87D6-", GetRandomString(12))
}

func Serialize(paramStr model.Json_iid) []byte {
	iidStr, err := json.Marshal(&paramStr)
	if err != nil{
		panic(err.Error())
	}
	gzipedIIDStr, err := GZipData(iidStr)
	if err != nil {
		panic(err.Error())
	}
	encryptedIIDStr := IIDEncrypt(gzipedIIDStr)
	return encryptedIIDStr
}

func AwemeJsonB64_encode(jsonStr string) (string){
	jsonBytes := []byte(jsonStr)
	var cypherBytes []byte
	for _, v :=range jsonBytes{
		cypherBytes = append(cypherBytes, v ^ 0x9d)
	}
	return string(base64.StdEncoding.EncodeToString(cypherBytes))
}

func AwemeJsonB64_decode(b64Str string) (string){
	cypherBytes, err := base64.StdEncoding.DecodeString(b64Str)
	if err != nil{
		panic(err)
	}

	var newBytes []byte
	for _, v :=range cypherBytes{
		newBytes = append(newBytes, v ^ 0x9d)
	}
	return string(newBytes)
}
//const (
//	base64Table = "123QRSTUabcdVWXYZHijKLAWDCABDstEFGuvwxyzGHIJklmnopqr234560178912"
//)
//
//var coder = base64.NewEncoding(base64Table)
//
//func base64Encode(src string) string {
//	return coder.EncodeToString([]byte(src))
//}
//
//func base64Decode(src string) ([]byte, error) {
//	return coder.DecodeString(src)
//}