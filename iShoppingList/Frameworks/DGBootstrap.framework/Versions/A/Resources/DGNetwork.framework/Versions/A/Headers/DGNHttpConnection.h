/*
 Copyright 2014 Digipolitan. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 3. Neither the name of the owner nor the names of its contributors may be used
 to endorse or promote products derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY DIGIPOLITAN ''AS IS'' AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL DIGIPOLITAN BE LIABLE FOR ANY DIRECT,
 INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <DGFoundation/DGFDefines.h>
#import <DGFoundation/DGFICancelableTask.h>
#import <Foundation/NSURLConnection.h>
#import <Foundation/NSDate.h>
#import "DGNIHttpConnectionListener.h"
#import "DGNIHttpConnectionAuthentication.h"

@protocol DGNIHttpCacheRepository;
@protocol DGFIHashTable;
@class NSMutableData;
@class DGNHttpRequest, DGNHttpCacheInfo;

/** Key using when the connection inject (options for injection) a cache repository, the value for this key is an instance of DGNHttpCacheInfo */
DGFExtern NSString* const kDGNDependencyCacheInfoOption;

/**
 * Class performing asynchronous loads of a http request
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date August 2011
 */
@interface DGNHttpConnection : NSObject <NSURLConnectionDelegate, DGFICancelableTask> {
    @private
    /** Listener of this connection */
    __weak id<DGNIHttpConnectionListener> listener_;
    /** Authentication system implemetation */
    __weak id<DGNIHttpConnectionAuthentication> authentication_;
    
    /** Apple connection, use for performing the request */
    NSURLConnection* connection_;
    /** The specific request */
    DGNHttpRequest* request_;
    
    /** A specified or injected cache system */
    id<DGNIHttpCacheRepository> cacheRepository_;
    /** Current cache info*/
    DGNHttpCacheInfo* cacheInfo_;
    
    /** Total bytes to send */
    NSInteger totalBytesToUpload_;
    /** Bytes sent */
    NSInteger bytesUploaded_;
    /** The response length */
    long long responseLength_;
    /** Buffer for the received data */
    NSMutableData* receivedData_;
    /** The server response code */
    NSUInteger responseCode_;
    /* Response headers */
    id<DGFIHashTable> responseHeaders_;

    struct {
        /** YES if the conneciton is in progress, otherwise NO */
        BOOL isStarted;
        /** YES if a cache is found, otherwise NO */
        BOOL cacheFound;
    } connectionFlags_;
}

/** Property allowing to retrieve and modify the connection listener */
@property (nonatomic, weak) id<DGNIHttpConnectionListener> listener;

/** Property allowing to retrieve and modify the connection authentication */
@property (nonatomic, weak) id<DGNIHttpConnectionAuthentication> authentication;

/** Property allowing to retrieve and modify the request */
@property (nonatomic, strong) DGNHttpRequest* request;

/** Property allowing to retrieve and modify a cache repository */
@property (nonatomic, strong) id<DGNIHttpCacheRepository> cacheRepository;

/** Property allowing to retrieve received data form the web */
@property (nonatomic, readonly) NSData* receivedData;

/** Property allowing to retrieve the current upload progress */
@property (nonatomic, readonly) float uploadProgress;

/** Property allowing to retrieve the current download progress */
@property (nonatomic, readonly) float downloadProgress;

/** Property allowing to retrieve the server response code */
@property (nonatomic, readonly) NSUInteger responseCode;

/** Property allowing to retrieve the response headers */
@property (nonatomic, readonly) id<DGFIHashTable> responseHeaders;

/**
 * Factory method, create, initialize and launch an asynchronous connection
 * @param aStringURL The string URL of the request
 * @param aListener The listener of this connection
 * @return A launched connection
 */
+ (instancetype) connectionSendAsynchronous:(NSString*) aStringURL listener:(id<DGNIHttpConnectionListener>) aListener;

/**
 * Factory method, create, initialize and launch an asynchronous connection
 * @param aStringURL The string URL of the request
 * @param aListener The listener of this connection
 * @param body The body request data
 * @return A launched connection
 */
+ (instancetype) connectionSendAsynchronous:(NSString *) aStringURL listener:(id<DGNIHttpConnectionListener>) aListener body:(NSData*) aBody;

/**
 * Factory method, create, initialize and launch an asynchronous connection
 * @param aRequest The request to send
 * @param aListener The listener of this connection
 * @return A launched connection
 */
+ (instancetype) connectionSendAsynchronousRequest:(DGNHttpRequest*) aRequest listener:(id<DGNIHttpConnectionListener>) aListener;

/**
 * Initializes the connection
 * @param aRequest The request of the connection
 * @param aListener The listener for the connection
 * @return An initialized connection with default params
 */
- (instancetype) initWithRequest:(DGNHttpRequest*) aRequest listener:(id<DGNIHttpConnectionListener>) aListener;

/** Starts asynchronously the request */
- (void) startAsynchronous;

@end
