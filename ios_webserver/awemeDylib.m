//  weibo: http://weibo.com/xiaoqing28
//  blog:  http://www.alonemonkey.com
//
//  usual_awemeDylib.m
//  usual.awemeDylib
//
//  Created by Brian.W on 2018/3/24.
//  Copyright (c) 2018年 Brian.W. All rights reserved.
//

#import "awemeDylib.h"
#import <CaptainHook/CaptainHook.h>
#import <UIKit/UIKit.h>
#import <Cycript/Cycript.h>
#import <objc/message.h>

CHConstructor{
    NSLog(INSERT_SUCCESS_WELCOME);
    
    [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidFinishLaunchingNotification object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * _Nonnull note) {
        
#ifndef __OPTIMIZE__
        CYListenServer(6666);
#endif
        
    }];
}



CHDeclareClass(CustomViewController)
CHDeclareClass(TTDefaultHTTPRequestSerializer)
CHDeclareClass(TTTInstallIDPostDataHttpRequestSerializer)
CHDeclareClass(NSData)
CHDeclareClass(NSMutableDictionary)
CHDeclareClass(IESAntiSpam)
CHDeclareClass(N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K)
CHDeclareClass(TTInstallOpenUDID)
CHDeclareClass(AWELocationService)
CHDeclareClass(AWESecurityLaunchTask)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

//add new method
CHDeclareMethod1(void, CustomViewController, newMethod, NSString*, output){
    NSLog(@"This is a new method : %@", output);
}

CHDeclareMethod1(void, TTDefaultHTTPRequestSerializer, testMethod, NSString*, output){
    NSLog(@"This is a new method : %@", output);
}



#pragma clang diagnostic pop

CHOptimizedClassMethod0(self, void, CustomViewController, classMethod){
    NSLog(@"hook class method");
    CHSuper0(CustomViewController, classMethod);
}

//CHOptimizedClassMethod1(optimization, return_type, class_type, name1, type1, arg1)
CHOptimizedClassMethod2(self, id, NSData, dataWithBytesNoCopy, void *, arg_bytes, length, NSUInteger, arg_length){
    //    if (arg_length == 596) {
    //      NSLog(@"hook class dataWithBytesNoCopy");
    //    }
    return CHSuper2(NSData, dataWithBytesNoCopy, arg_bytes, length, arg_length);
}



//CHOptimizedMethod1(optimization, return_type, class_type, name1, type1, arg1)
//CHMethod1(return_type, class_type, name1, type1, arg1)
CHOptimizedClassMethod0(self, id, TTDefaultHTTPRequestSerializer, serializer){
    NSLog(@"hook class TTDefaultHTTPRequestSerializer:serializer");
    //get property
    //    NSString* UA = CHIvar(self,defaultUserAgent,__strong NSString*);
    //    NSLog(@"hook :defaultUserAgent is %@",UA);
    return CHSuper0(TTDefaultHTTPRequestSerializer, serializer);
}

CHOptimizedClassMethod1(self, id, AWELocationService, base64StringWithDictionary, id, arg1){
    NSLog(@"hook class AWELocationService:base64StringWithDictionary");
    id rst = CHSuper1(AWELocationService, base64StringWithDictionary, arg1);
    return rst;
}

CHOptimizedMethod1(self, id, AWESecurityLaunchTask, awes_showAppStoreDownloadAlert,id,arg1){
    NSLog(@"hook class AWESecurityLaunchTask:awes_showAppStoreDownloadAlert");
    return nil;
    
}

//CHOptimizedClassMethod2(optimization, return_type, class_type, name1, type1, arg1, name2, type2, arg2)
CHOptimizedClassMethod2(self, id, IESAntiSpam, encryptDataWithTimeStamp, int, arg1, parameters, id, arg2){
    NSLog(@"hook class IESAntiSpam:encryptDataWithTimeStamp");
    //[Utils]
    GCDWebServer* _webServer;
    _webServer = [[GCDWebServer alloc] init];

    // Add a handler to respond to GET requests on any URL
    [_webServer addDefaultHandlerForMethod:@"GET"
                              requestClass:[GCDWebServerRequest class]
                              processBlock:^GCDWebServerResponse *(GCDWebServerRequest* request) {


                                  return [GCDWebServerDataResponse responseWithHTML:@"<html><body><p>Hello World</p></body></html>"];

                              }];
    [_webServer addHandlerForMethod:@"POST"
                               path:@"/encryptDataWithTimeStamp"
                       requestClass:[GCDWebServerURLEncodedFormRequest class]
                       processBlock:^GCDWebServerResponse *(GCDWebServerRequest* request) {
                           NSString* paramaJson_str = [[(GCDWebServerURLEncodedFormRequest*)request arguments] objectForKey:@"paramaJson"];
                           NSString* timeStamp_str = [[(GCDWebServerURLEncodedFormRequest*)request arguments] objectForKey:@"timeStamp"];
                           int timeStamp_int = timeStamp_str.intValue;
                           NSError *jsonError;
                           NSData *objectData = [paramaJson_str dataUsingEncoding:NSUTF8StringEncoding];
                           NSDictionary *paramaJson_dict = [NSJSONSerialization JSONObjectWithData:objectData
                                                                                options:NSJSONReadingMutableContainers
                                                                                  error:&jsonError];
                           NSString* deviceID = [paramaJson_dict objectForKey:@"device_id"];
                           IESAntiSpam *instance = [self sharedInstance];
                           bool is_inited = [instance isInitialized];
                           id deviceID_id = [self deviceID];
                           //id IESAntiSpamDeviceIDBlock = [instance NWY2ZjI3Y2ZiYjQzNTA5YjRjNDA2NTQ0ZDU3MjVmMWYgIC0K];
                           [instance setNWY2ZjI3Y2ZiYjQzNTA5YjRjNDA2NTQ0ZDU3MjVmMWYgIC0K:^id(){
                               //return nil;
                               return [NSString stringWithString:deviceID];
                           }];
                           NSDictionary *rst = CHSuper2(IESAntiSpam, encryptDataWithTimeStamp, timeStamp_int, parameters, paramaJson_dict);
                           NSString *rst_str = [NSString stringWithFormat:@"%@", rst];
                           NSString* html = [NSString stringWithFormat:@"%@", rst_str];
                           return [GCDWebServerDataResponse responseWithHTML:html];

                       }];
    // Start server on port 8080
    [_webServer startWithPort:8080 bonjourName:nil];
    NSLog(@"Visit %@ in your web browser", _webServer.serverURL);
    do {
        sleep(99999);
    }while(1);
    
    return nil;
}

CHOptimizedClassMethod0(self, id, TTTInstallIDPostDataHttpRequestSerializer, serializer){
    NSLog(@"hook class TTTInstallIDPostDataHttpRequestSerializer:serializer");
    //get property
    //    NSString* UA = CHIvar(self,defaultUserAgent,__strong NSString*);
    //    NSLog(@"hook :defaultUserAgent is %@",UA);
    return CHSuper0(TTTInstallIDPostDataHttpRequestSerializer, serializer);
}

CHOptimizedClassMethod0(self, id, TTInstallOpenUDID, _getOpenUDID){
    NSLog(@"hook class OpenUDID:_getOpenUDID");
    id rst = CHSuper0(TTInstallOpenUDID, _getOpenUDID);
    return rst;
}

CHOptimizedClassMethod1(self, id, TTInstallOpenUDID, valueWithError, id*, arg1){
    NSLog(@"hook class OpenUDID:valueWithError");
    id rst = CHSuper1(TTInstallOpenUDID, valueWithError, arg1);
    return rst;
}

//CHOptimizedClassMethod5(optimization, return_type, class_type, name1, type1, arg1, name2, type2, arg2, name3, type3, arg3, name4, type4, arg4, name5, type5, arg5)
//CHOptimizedMethod5(optimization, return_type, class_type, name1, type1, arg1, name2, type2, arg2, name3, type3, arg3, name4, type4, arg4, name5, type5, arg5)
CHOptimizedMethod5(self, id, TTTInstallIDPostDataHttpRequestSerializer, URLRequestWithURL,id,arg1, params, id, arg2, method, id, arg3, constructingBodyBlock, id, arg4, commonParams, id, arg5){
    NSLog(@"hook class TTTInstallIDPostDataHttpRequestSerializer:URLRequestWithURL");
    //CHSuper5(class_type, name1, val1, name2, val2, name3, val3, name4, val4, name5, val5)
    return CHSuper5(TTTInstallIDPostDataHttpRequestSerializer, URLRequestWithURL, arg1, params, arg2, method, arg3, constructingBodyBlock, arg4, commonParams, arg5);
}

CHOptimizedMethod2(self, id, IESAntiSpam, encryptURLWithURL,id,arg1, formData, id, arg2){
    NSLog(@"hook class IESAntiSpam:encryptURLWithURL");
//    //id deviceID = [self deviceID];
//    long long localTime = [self localTime];
//    long long serverTime = [self serverTime];
//    IESAntiSpamConfig *config = [self config];
//    NSDictionary *dict = @{
//                           @"type" : @"34"  ,
//                           @"mobile" : @"2e3d333436373737323c33363330" ,
//                           @"mix_mode" : @1
//                           };
//    arg2 = dict;
//    NSURL *url = [NSURL URLWithString:@"https://lf.snssdk.com/passport/mobile/send_code/?iid=38131214263&ac=WIFI&os_api=18&app_name=aweme&channel=App%20Store&idfa=DFCF4ABE-ECEB-4FCC-87D6-710CB1C2A9C2&device_platform=iphone&build_number=17909&vid=FF7C3882-1526-4062-B137-4DB562DE72B5&openudid=f2c0da6bb76719cb83d4eebf57cb5c8ad3a1c810&device_type=iPhone7,2&app_version=1.7.9&device_id=54728286568&version_code=1.7.9&os_version=9.2.1&screen_width=750&aid=1128&mix_mode=1&mobile=2e3d333436373737323c33363330&type=34"];
//    arg1 = url;
    id rst =  CHSuper2(IESAntiSpam, encryptURLWithURL, arg1, formData, arg2);
    return rst;
    
}
CHOptimizedMethod2(self, void, NSMutableDictionary, setObject, id, obj, forKeyedSubscript, id<NSCopying>, key){
    
//    NSLog(@"hook class NSMutableDictionary:setObject");
//    if (key==CFSTR("as")){
//        printf("test");
//    }
    CHSuper2(NSMutableDictionary, setObject, obj, forKeyedSubscript, key);
}
CHOptimizedMethod0(self, NSString*, CustomViewController, getMyName){
    //get origin value
    NSString* originName = CHSuper(0, CustomViewController, getMyName);
    
    NSLog(@"origin name is:%@",originName);
    
    //get property
    NSString* password = CHIvar(self,_password,__strong NSString*);
    
    NSLog(@"password is %@",password);
    
    [self newMethod:@"output"];
    
    //set new property
    self.newProperty = @"newProperty";
    
    NSLog(@"newProperty : %@", self.newProperty);
    
    //change the value
    return @"AloneMonkey";
    
}
//CHOptimizedMethod1(optimization, return_type, class_type, name1, type1, arg1)
CHOptimizedMethod1(self, id, N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K, ODU2M2Y2Y2EzZmU4ZWZkZDJmYzA3MzAwYzEyZmM2MzcgIC0K,id,arg1){
    NSLog(@"hook class N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K:ODU2M2Y2Y2EzZmU4ZWZkZDJmYzA3MzAwYzEyZmM2MzcgIC0K");
    //    v5 = ((unsigned __int64 (__cdecl *)(N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K *, SEL))objc_msgSend)(
    //                                                                                                               v3,
    //                                                                                                               "platform");
    
    unsigned long long v12 = [self platform];
    return CHSuper1(N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K, ODU2M2Y2Y2EzZmU4ZWZkZDJmYzA3MzAwYzEyZmM2MzcgIC0K, arg1);
}

//add new property
//CHPropertyRetainNonatomic(TTTInstallIDPostDataHttpRequestSerializer, NSString*, newProperty, setNewProperty);
CHPropertyRetainNonatomic(CustomViewController, NSString*, newProperty, setNewProperty);

CHConstructor{
//    CHLoadLateClass(CustomViewController);
//    CHLoadLateClass(TTDefaultHTTPRequestSerializer);
//    CHLoadLateClass(TTTInstallIDPostDataHttpRequestSerializer);
//    CHLoadLateClass(NSData);
//    CHLoadLateClass(NSMutableDictionary);
    CHLoadLateClass(IESAntiSpam);
    CHLoadLateClass(AWESecurityLaunchTask);
//    CHLoadLateClass(N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K);
//    CHLoadLateClass(TTInstallOpenUDID);
    //CHLoadLateClass(AWELocationService);
    
//    CHClassHook0(TTDefaultHTTPRequestSerializer, serializer);
//    CHClassHook0(TTTInstallIDPostDataHttpRequestSerializer, serializer);
//    //CHClassHook5(class, name1, name2, name3, name4, name5) CHHook_(class, name1 ## $ ## name2 ## $ ## name3 ## $ ## name4 ## $ ## name5 ## $)
//    CHClassHook5(TTTInstallIDPostDataHttpRequestSerializer, URLRequestWithURL, params, method, constructingBodyBlock, commonParams);
//    CHClassHook0(CustomViewController, getMyName);
//    CHClassHook0(CustomViewController, classMethod);
//    CHClassHook2(NSData, dataWithBytesNoCopy, length);
//    CHClassHook2(NSMutableDictionary, setObject, forKeyedSubscript);
    CHClassHook2(IESAntiSpam, encryptDataWithTimeStamp, parameters);
    CHClassHook1(AWESecurityLaunchTask, awes_showAppStoreDownloadAlert);
//    CHClassHook2(IESAntiSpam, encryptURLWithURL, formData);
//    CHClassHook1(N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K, ODU2M2Y2Y2EzZmU4ZWZkZDJmYzA3MzAwYzEyZmM2MzcgIC0K);
//    CHClassHook0(TTInstallOpenUDID, _getOpenUDID);
//    CHClassHook1(TTInstallOpenUDID, valueWithError);
    //CHClassHook1(AWELocationService, base64StringWithDictionary);
//
//
//    CHHook0(CustomViewController, newProperty);
//    CHHook1(CustomViewController, setNewProperty);
    
    //CHHook0(TTTInstallIDPostDataHttpRequestSerializer, URLRequestWithURL);
}

