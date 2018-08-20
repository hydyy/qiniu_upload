//
//  QiniuUploader.h
//  QiniuUploadDemo
//
//  Created by 胡 桓铭 on 14-5-17.
//  Copyright (c) 2014年 hu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QiniuToken.h"
#import "QiniuFile.h"
#import "QiniuInputStream.h"

@interface QiniuUploader : NSObject <NSURLSessionTaskDelegate, NSURLSessionDataDelegate>

@property (assign, atomic) NSInteger maxConcurrentNumber;
@property (assign, atomic, readonly) Boolean isRunning;
@property (retain, atomic) NSArray * _Nonnull files;
/// 域名选择 0:https://upload.qbox.me,1:https://upload-z1.qbox.me 默认为0
@property (nonatomic, assign) int domainIndex;


+ (id _Nullable)sharedUploader;

/**
 *  start upload files to qiniu cloud storage.
 *  @return Boolean if files were nil, it will return NO.
 */
- (Boolean)startUpload:(nonnull NSString* (^)(NSInteger index))tokenHandle
  uploadOneFileSucceededHandler: (nullable void (^)(NSInteger index, NSDictionary * _Nonnull info)) successHandler
  uploadOneFileFailedHandler: (nullable void (^)(NSInteger index, NSError * _Nullable error)) failHandler
  uploadOneFileProgressHandler: (nullable void (^)(NSInteger index, int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend)) progressHandler
  uploadAllFilesComplete: (nullable void (^)()) completeHandler;

/**
 *  cancel uploading task at once.
 */
- (Boolean)cancelAllUploadTask;


@end
