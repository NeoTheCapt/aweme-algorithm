//  weibo: http://weibo.com/xiaoqing28
//  blog:  http://www.alonemonkey.com
//
//  usual_awemeDylib.h
//  usual.awemeDylib
//
//  Created by Brian.W on 2018/3/24.
//  Copyright (c) 2018年 Brian.W. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Mantle/MTLModel.h>
#import "GCDWebServer.h"
#import "GCDWebServerDataResponse.h"
#import "GCDWebServerURLEncodedFormRequest.h"

#define INSERT_SUCCESS_WELCOME @"\n               🎉!!！congratulations!!！🎉\n👍----------------insert dylib success----------------👍"

@interface CustomViewController

@property (nonatomic, copy) NSString* newProperty;

+ (void)classMethod;

- (NSString*)getMyName;

- (void)newMethod:(NSString*) output;

@end

@interface TTDefaultHTTPRequestSerializer
{
    NSString *_defaultUserAgent;
}

- (void)testMethod:(NSString*) output;
+ (id)serializer;
@property(copy, nonatomic) NSString *defaultUserAgent; // @synthesize defaultUserAgent=_defaultUserAgent;
//- (void).cxx_destruct;
- (void)applyCookieHeaderFrom:(id)arg1 toRequest:(id)arg2;
- (void)applyCookieHeader:(id)arg1;
- (id)defaultUserAgentString;
- (void)buildRequestHeaders:(id)arg1 parameters:(id)arg2;
- (void)buildRequestHeaders:(id)arg1;
- (id)_transferedURL:(id)arg1;
- (id)URLRequestWithRequestModel:(id)arg1 commonParams:(id)arg2;
- (id)URLRequestWithURL:(id)arg1 headerField:(id)arg2 params:(id)arg3 method:(id)arg4 constructingBodyBlock:(int)arg5 commonParams:(id)arg6;
- (id)URLRequestWithURL:(id)arg1 params:(id)arg2 method:(id)arg3 constructingBodyBlock:(int)arg4 commonParams:(id)arg5;

@end

@interface TTTInstallIDPostDataHttpRequestSerializer: TTDefaultHTTPRequestSerializer
- (id)URLRequestWithURL:(id)arg1 params:(id)arg2 method:(id)arg3 constructingBodyBlock:(int)arg4 commonParams:(id)arg5;
@end

@interface IESAntiSpam : NSObject
{
    struct _opaque_pthread_rwlock_t rwlock;
    _Bool _isInitialized;
    id _NWY2ZjI3Y2ZiYjQzNTA5YjRjNDA2NTQ0ZDU3MjVmMWYgIC0K;
    long long _MWIyMDgyNjM1YmRlZWY3YzFjMDAyODllYmE2ZTJiYzYgIC0K;
    long long _MWM3YjBlMDZmZmFhZGQ0NzBhNzdmOGEzODcwZDRhYzcgIC0K;
}

+ (id)convertDataToHexString:(id)arg1;
+ (id)deviceID;
+ (id)encryptDataWithTimeStamp:(long long)arg1 parameters:(id)arg2;
+ (id)sharedInstance;
@property(nonatomic) _Bool isInitialized; // @synthesize isInitialized=_isInitialized;
@property long long MWM3YjBlMDZmZmFhZGQ0NzBhNzdmOGEzODcwZDRhYzcgIC0K; // @synthesize MWM3YjBlMDZmZmFhZGQ0NzBhNzdmOGEzODcwZDRhYzcgIC0K=_MWM3YjBlMDZmZmFhZGQ0NzBhNzdmOGEzODcwZDRhYzcgIC0K;
@property long long MWIyMDgyNjM1YmRlZWY3YzFjMDAyODllYmE2ZTJiYzYgIC0K; // @synthesize MWIyMDgyNjM1YmRlZWY3YzFjMDAyODllYmE2ZTJiYzYgIC0K=_MWIyMDgyNjM1YmRlZWY3YzFjMDAyODllYmE2ZTJiYzYgIC0K;
@property(copy, nonatomic) id NWY2ZjI3Y2ZiYjQzNTA5YjRjNDA2NTQ0ZDU3MjVmMWYgIC0K; // @synthesize NWY2ZjI3Y2ZiYjQzNTA5YjRjNDA2NTQ0ZDU3MjVmMWYgIC0K=_NWY2ZjI3Y2ZiYjQzNTA5YjRjNDA2NTQ0ZDU3MjVmMWYgIC0K;
- (id)Y2MxYWIwMTRlN2E1NWE1OWU3ZDVjZDAwMjJlNzc2ZDYgIC0K:(id)arg1 formData:(id)arg2;
- (void)adjustWithServerTime:(long long)arg1;
- (void)startConfig;
- (id)init;

@end


//@class IESAntiSpamConfig;
//@interface IESAntiSpam : NSObject
//{
//    _Bool _isStarted;
//    _Bool _isInitialized;
//    id _IESAntiSpamDeviceIDBlock;
//    IESAntiSpamConfig *_config;
//    long long _serverTime;
//    long long _localTime;
//}
//
//+ (id)convertDataToHexString:(id)arg1;
//+ (id)deviceID;
//+ (id)encryptDataWithTimeStamp:(int)arg1 parameters:(id)arg2;
//+ (id)sharedInstance;
//@property long long localTime; // @synthesize localTime=_localTime;
//@property long long serverTime; // @synthesize serverTime=_serverTime;
//@property(nonatomic) _Bool isInitialized; // @synthesize isInitialized=_isInitialized;
//@property(nonatomic) _Bool isStarted; // @synthesize isStarted=_isStarted;
//@property(retain, nonatomic) IESAntiSpamConfig *config; // @synthesize config=_config;
//@property(copy, nonatomic) id IESAntiSpamDeviceIDBlock; // @synthesize IESAntiSpamDeviceIDBlock=_IESAntiSpamDeviceIDBlock;
////- (void).cxx_destruct;
//- (void)addjustWithServerTime:(long long)arg1;
//- (id)encryptURLWithURL:(id)arg1 formData:(id)arg2;
//- (id)adjustWithAntiSpamResponse:(id)arg1 previousConfig:(id)arg2;
//- (void)fetchSettingsWithConfig:(id)arg1;
//- (void)startWithConfig:(id)arg1;
//- (id)init;
//
//@end

@interface N2ZlMDU0MThkYTEwYTcwNzM4NDViOWNiZTE2ZTQwMGQgIC0K : NSObject
{
    _Bool _enabledLocated;
    _Bool _requestSettings;
    unsigned long long _platform;
    Class _delegate;
    NSThread *_workerThread;
    //SGMSensorManager *_timerSensor;
    //SGMSensorManager *_manualSensor;
    //NTJjMDRlZThlYzNiYjMzZWU4MjQ3MWNhODIzNWZjNmEgIC0K *_logManager;
    NSTimer *_timer;
    //CLLocationManager *_locationManager;
    NSObject<OS_dispatch_semaphore> *_lock;
    NSString *_scene;
    //SGMSafeGuardSettingModel *_settings;
    //struct CLLocationCoordinate2D _currentCoordinate;
}

+ (id)sharedManager;
@property(nonatomic) _Bool requestSettings; // @synthesize requestSettings=_requestSettings;
//@property(retain, nonatomic) SGMSafeGuardSettingModel *settings; // @synthesize settings=_settings;
@property(copy, nonatomic) NSString *scene; // @synthesize scene=_scene;
@property(retain, nonatomic) NSObject<OS_dispatch_semaphore> *lock; // @synthesize lock=_lock;
@property(nonatomic) _Bool enabledLocated; // @synthesize enabledLocated=_enabledLocated;
@property(nonatomic) struct CLLocationCoordinate2D currentCoordinate; // @synthesize currentCoordinate=_currentCoordinate;
//@property(retain, nonatomic) CLLocationManager *locationManager; // @synthesize locationManager=_locationManager;
@property(retain, nonatomic) NSTimer *timer; // @synthesize timer=_timer;
//@property(retain, nonatomic) NTJjMDRlZThlYzNiYjMzZWU4MjQ3MWNhODIzNWZjNmEgIC0K *logManager; // @synthesize logManager=_logManager;
//@property(retain, nonatomic) SGMSensorManager *manualSensor; // @synthesize manualSensor=_manualSensor;
//@property(retain, nonatomic) SGMSensorManager *timerSensor; // @synthesize timerSensor=_timerSensor;
@property(retain, nonatomic) NSThread *workerThread; // @synthesize workerThread=_workerThread;
@property(nonatomic) __weak Class delegate; // @synthesize delegate=_delegate;
@property(nonatomic) unsigned long long platform; // @synthesize platform=_platform;
//- (void).cxx_destruct;
- (id)getStringTypeInfoFromDelegateSelector:(SEL)arg1;
- (id)safeString:(id)arg1;
- (void)p_asyncPerformSelector:(SEL)arg1 withObject:(id)arg2;
- (void)threadRun;
- (id)dataUploadURLOfPlatform:(unsigned long long)arg1;
- (id)settingsURLOfPlatform:(unsigned long long)arg1;
- (id)modelOfJSON:(id)arg1;
- (void)p_stopScheduledTask;
- (void)p_updateSensorInterval:(id)arg1;
- (void)updateSettings:(id)arg1;
- (double)timestampForDate:(id)arg1;
- (_Bool)isLocationServiceOpen;
- (id)getCurrentCoordinateOfUser;
- (id)p_fetchSecSDKInfo;
- (id)p_fetchDeviceInfo;
- (id)p_fetchSensorInfo;
- (id)p_fetchUploadDataForScene:(id)arg1;
- (id)preprocessDataForScene:(id)arg1;
- (void)p_uploadDataForScene:(id)arg1;
- (void)p_schedulSGUpload;
- (void)p_stop;
- (void)p_startForScene:(id)arg1;
- (void)p_schedulSafeGuard;
- (void)p_requestSettingsWithCompletion:(id)arg1;
- (void)p_saveAccelerometerData:(id)arg1;
- (void)p_saveGyroData:(id)arg1;
- (void)locationManager:(id)arg1 didFailWithError:(id)arg2;
- (void)locationManager:(id)arg1 didUpdateLocations:(id)arg2;
- (void)MmY2YWEzYjI0YzdkYmU4OGUwM2UyM2U2YTNkYmJjODAgIC0K:(id)arg1 updateAccelerometerData:(id)arg2;
- (void)MmY2YWEzYjI0YzdkYmU4OGUwM2UyM2U2YTNkYmJjODAgIC0K:(id)arg1 updateGyroData:(id)arg2;
- (void)p_innerScheduleSafeGuard;
- (id)ODU2M2Y2Y2EzZmU4ZWZkZDJmYzA3MzAwYzEyZmM2MzcgIC0K:(id)arg1;
- (void)N2VhMzY3MTA2YWJiOGEzNDgwMTdlYzRmNmFkMDI1NWYgIC0K;
- (void)NTgxNWY4YTI5MWI4YmUzOGJiNjU4NjkyMzM1NDA0ZjkgIC0K:(id)arg1;
- (void)NjNkZDA0ZTYxYThiZWRlNGQyM2YwM2NhNDlhMWQ1MmQgIC0K;
- (void)ZjBkYzVlNTJhMTZjOTg0YmI2NmYwOGE0OWYzMjQ5MWEgIC0K:(Class)arg1;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@class NSString;

@interface IESAntiSpamConfig : MTLModel
{
    NSString *_appID;
    NSString *_spname;
    NSString *_secretKey;
    NSString *_configURL;
}

+ (id)configWithAppID:(id)arg1 spname:(id)arg2 secretKey:(id)arg3;
@property(copy, nonatomic) NSString *configURL; // @synthesize configURL=_configURL;
@property(copy, nonatomic) NSString *secretKey; // @synthesize secretKey=_secretKey;
@property(copy, nonatomic) NSString *spname; // @synthesize spname=_spname;
@property(copy, nonatomic) NSString *appID; // @synthesize appID=_appID;
//- (void).cxx_destruct;
- (id)init;

@end

@interface TTInstallOpenUDID : NSObject
{
}

+ (id)valueWithError:(id *)arg1;
+ (id)value;
+ (id)_getOpenUDID;
+ (id)_getDictFromPasteboard:(id)arg1;
+ (void)_setDict:(id)arg1 forPasteboard:(id)arg2;

@end


@interface AWELocationService : NSObject
{
}

+ (id)sharedInstance;
+ (id)base64StringWithDictionary:(id)arg1;
+ (id)districtForPlacemark:(id)arg1;
+ (id)cityForPlacemark:(id)arg1;
+ (void)uploadLocationWithName:(id)arg1 completion:(id)arg2;
+ (void)_uploadLocation:(id)arg1 placemark:(id)arg2 completion:(id)arg3;
+ (void)uploadLocation:(id)arg1 completion:(id)arg2;
- (void)setSystemLocationAlertShowned;
- (_Bool)isSystemLocationAlertShowned;
- (_Bool)clearLocation;
- (_Bool)persistLocation:(id)arg1;
- (void)requestCurrentLocationWithAccuracy:(long long)arg1 completionBlock:(id)arg2;
- (void)requestCurrentLocation:(id)arg1;
- (void)requestPermission:(id)arg1;
- (id)currentLocation;
- (_Bool)hasPermission;

@end


@class NSString;

@interface AWESecurityLaunchTask : NSObject
{
}

+ (id)sharedInstance;
+ (void)onAppLaunch;
- (void)awes_showAppStoreDownloadAlert:(id)arg1;
- (_Bool)awes_isUseTTNet;
- (id)awes_currentLocation;
- (id)awes_installChannel;
- (id)awes_sessionID;
- (id)awes_installID;
- (id)awes_customDeviceID;
- (void)didReceiveApiResponse:(id)arg1 URL:(id)arg2;
- (void)startLoader;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

@interface Utils : NSObject
- (NSString *)convertToJsonData:(NSDictionary *)dict
@end
