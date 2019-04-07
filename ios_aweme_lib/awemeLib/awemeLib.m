//
//  awemeLib.m
//  awemeLib
//
//  Created by Brian.W on 2018/5/9.
//  Copyright © 2018年 Brian.W. All rights reserved.
//
#import <objc/runtime.h>
#import <objc/message.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
//#import <UIKit/UIKit.h>
#import <dlfcn.h>

#import <mach/mach.h>
#import <mach-o/loader.h>
#import <mach-o/dyld.h>
#import "awemeLib.h"

@implementation awemeLib

@end

int test(int a, int b){
    return a + b;
}

const char* testchar(char *paramaJsonStr){
    NSString *paramaJsonN = [NSString stringWithUTF8String:paramaJsonStr];
    //NSLog(@"paramaJsonN = %@", paramaJsonN);
    NSData *paramaJsonD = [paramaJsonN dataUsingEncoding:NSUTF8StringEncoding];
    NSDictionary *paramaJson = [NSJSONSerialization JSONObjectWithData:paramaJsonD options:0 error:nil];
    NSError *parseError = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:paramaJson options:NSJSONWritingPrettyPrinted error:&parseError];
    NSString *str= [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    const char* c = [str UTF8String];
    return c;
}

const char* encryptDataWithTimeStamp(char *paramaJsonStr, int timeStamp, char *deviceIDStr, char *libPath) {
    NSString *paramaJsonN = [NSString stringWithUTF8String:paramaJsonStr];
    //NSLog(@"paramaJsonN = %@", paramaJsonN);
    NSData *paramaJsonD = [paramaJsonN dataUsingEncoding:NSUTF8StringEncoding];
    id paramaJson = [NSJSONSerialization JSONObjectWithData:paramaJsonD options:0 error:nil];
    //NSString * dylibName = @"Awemex64";
    //NSString * path = [[NSBundle mainBundle] pathForResource:dylibName ofType:@"dylib"];
    NSFileManager *filemgr;
    NSString *currentpath;
    filemgr = [[NSFileManager alloc] init];
    currentpath = [filemgr currentDirectoryPath];
    NSString * path = [NSString stringWithFormat:@"%@%s", currentpath, libPath ];
    //NSLog(@"dlopen path=%@", path);
    if (dlopen(path.UTF8String, RTLD_NOW) == NULL){
        NSLog(@"dlopen failed ，error %s", dlerror());
        return 0;
    };
    uint32_t dylib_count = _dyld_image_count();
    uint64_t slide = 0;
    for (int i = 0; i < dylib_count; i ++) {
        const char * name = _dyld_get_image_name(i);
        if ([[NSString stringWithUTF8String:name] isEqualToString:path]) {
            slide = _dyld_get_image_vmaddr_slide(i);
        }
        //NSLog(@"dylib path =  %@", [NSString stringWithUTF8String:name]);
    }
    assert(slide != 0);
    int arg1 = timeStamp;
    NSString * deviceID = [NSString stringWithCString:deviceIDStr encoding:NSUTF8StringEncoding];
    Class IESAntiSpamConfigClass = NSClassFromString(@"IESAntiSpamConfig");
    IESAntiSpamConfig *IESAntiSpamConfigInstance = [[IESAntiSpamConfigClass alloc]init];
    [IESAntiSpamConfigInstance setConfigURL:@"https://hotsoon.snssdk.com/hotsoon/sp/"];
    [IESAntiSpamConfigInstance setSecretKey:@"a3668f0afac72ca3f6c1697d29e0e1bb1fef4ab0285319b95ac39fa42c38d05f"];
    [IESAntiSpamConfigInstance setSpname:@"aweme"];
    [IESAntiSpamConfigInstance setAppID:@"1128"];
    Class IESAntiSpamClass = NSClassFromString(@"IESAntiSpam");
    IESAntiSpam *instance = [IESAntiSpamClass sharedInstance];
    //    id (^callBack)() = ^id(){
    //        return nil;
    //    };
    //    callBack = [instance IESAntiSpamDeviceIDBlock];
    [instance startWithConfig:IESAntiSpamConfigInstance];
    [instance setIESAntiSpamDeviceIDBlock:^id(){
        //return nil;
        return [NSString stringWithString:deviceID];
    }];
    //id deviceID_id = [IESAntiSpamClass deviceID];
    id arg2 = paramaJson;
    //    [instance setLocalTime:arg1];
    //    [instance setServerTime:arg1];
    //    long long LocalTime = [instance localTime];
    //    long long ServerTime = [instance serverTime];
    //    [instance setIsInitialized:true];
    //    [instance setIsStarted:true];
    //NSDictionary *rst = [IESAntiSpamClass performSelector:NSSelectorFromString(@"encryptDataWithTimeStamp:parameters:") withObject:arg1 withObject:dict];
    //NSLog(@"test");
    NSDictionary *rst = [IESAntiSpamClass encryptDataWithTimeStamp:arg1 parameters: arg2];
    NSError *parseError = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:rst options:NSJSONWritingPrettyPrinted error:&parseError];
    NSString *str= [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    const char* c = [str UTF8String];
    return c;
}
