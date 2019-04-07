//
//  awemeLib.h
//  awemeLib
//
//  Created by Brian.W on 2018/5/9.
//  Copyright © 2018年 Brian.W. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Foundation/NSObject.h>
#import <Mantle/MTLModel.h>

@interface awemeLib : NSObject

@end

@class IESAntiSpamConfig;
@interface IESAntiSpam : NSObject
{
    _Bool _isStarted;
    _Bool _isInitialized;
    id _IESAntiSpamDeviceIDBlock;
    IESAntiSpamConfig *_config;
    long long _serverTime;
    long long _localTime;
}

+ (id)convertDataToHexString:(id)arg1;
+ (id)deviceID;
+ (id)encryptDataWithTimeStamp:(int)arg1 parameters:(id)arg2;
+ (id)sharedInstance;
@property long long localTime; // @synthesize localTime=_localTime;
@property long long serverTime; // @synthesize serverTime=_serverTime;
@property(nonatomic) _Bool isInitialized; // @synthesize isInitialized=_isInitialized;
@property(nonatomic) _Bool isStarted; // @synthesize isStarted=_isStarted;
@property(retain, nonatomic) IESAntiSpamConfig *config; // @synthesize config=_config;
@property(copy, nonatomic) id IESAntiSpamDeviceIDBlock; // @synthesize IESAntiSpamDeviceIDBlock=_IESAntiSpamDeviceIDBlock;
//- (void).cxx_destruct;
- (void)addjustWithServerTime:(long long)arg1;
- (id)encryptURLWithURL:(id)arg1 formData:(id)arg2;
- (id)adjustWithAntiSpamResponse:(id)arg1 previousConfig:(id)arg2;
- (void)fetchSettingsWithConfig:(id)arg1;
- (void)startWithConfig:(id)arg1;
- (id)init;

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




//extern int test(int a, int b);
