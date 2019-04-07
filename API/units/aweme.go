package units

/*
#cgo LDFLAGS: -ldl
#include <stdlib.h>
#include <dlfcn.h>
int test(char* lib_path){
       char* func_name="test";
       void* libc;
       int (*test_call)();
       int rst;
       if(libc = dlopen(lib_path,RTLD_LAZY))
       {
               test_call = dlsym(libc, func_name);
               rst = (*test_call)(6,2);
               dlclose(libc);
       }
       return rst;
}

char* testchar(char* lib_path, char* paramaJsonStr){
       char* func_name="testchar";
       void* libc;
       char* (*testchar)();
       char* rst;
       if(libc = dlopen(lib_path,RTLD_LAZY))
       {
               testchar = dlsym(libc, func_name);
               rst = (*testchar)(paramaJsonStr);
               dlclose(libc);
       }
       return rst;
}

char* encryptDataWithTimeStamp(char* lib_path, char* paramaJsonStr, int timeStamp, char *deviceIDStr, char *libPath){
       char* func_name="encryptDataWithTimeStamp";
       void* libc;
       char* (*encryptDataWithTimeStamp)();
       char* rst;
       if(libc = dlopen(lib_path,RTLD_LAZY))
       {
               encryptDataWithTimeStamp = dlsym(libc, func_name);
               rst = (*encryptDataWithTimeStamp)(paramaJsonStr, timeStamp, deviceIDStr, libPath);
               dlclose(libc);
       }
       return rst;
}
*/
//import "C"

//func EncryptDataWithTimeStamp(paramStr string, ts int, deviceIDStr string) model.Json_masas{
//	var EXTENSION_DIR string = "./lib/"
//	var OIDB_API string = "libawemeLib.dylib"
//	libPathC := C.CString(EXTENSION_DIR+OIDB_API)
//	defer C.free(unsafe.Pointer(libPathC))
//	cstr := C.CString(paramStr)
////	cstr := C.CString(`{
////   "iid":"31498571605",
////   "aid":"1128",
////   "ts":"1524622784",
////   "os_api":"18",
////   "build_number":"17805",
////   "channel":"App Store",
////   "device_platform":"iphone",
////   "app_version":"1.7.8",
////   "app_name":"aweme",
////   "vid":"612E0CAA-4C70-4E21-B6D7-8C386F862C6D",
////   "openudid":"2222222222222222222222222222222222222222",
////   "device_type":"iPhone7,2",
////   "idfa":"5A8CD0BE-EF7E-45C1-9056-094CA9FB51CC",
////   "device_id":"51737442652",
////   "ac":"WIFI",
////   "version_code":"1.7.8",
////   "os_version":"9.3.3",
////   "screen_width":"750"
////
////}`)
//	deviceID := C.CString(deviceIDStr)
//	libPath := C.CString("/lib/Awemex64_1.8.0.dylib")
//	defer C.free(unsafe.Pointer(cstr))
//	defer C.free(unsafe.Pointer(deviceID))
//	defer C.free(unsafe.Pointer(libPath))
//	OCStr := C.encryptDataWithTimeStamp(libPathC, cstr, C.int(ts), deviceID, libPath)
//	//defer C.free(unsafe.Pointer(rst2))
//	GOStr := C.GoString(OCStr)
//
//	var Json_masas model.Json_masas
//	err := json.Unmarshal([]byte(GOStr), &Json_masas)
//	if err != nil{
//		logs.Error("C function encryptDataWithTimeStamp return: ", GOStr)
//		panic(err.Error())
//	}
//	return Json_masas
//
//}