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

#import <Foundation/NSObject.h>

@protocol DGNIAuthorization;
@protocol DGFIHashTable;
@class NSURL;
@class DGNHttpRequestBuilder;
@class DGNHttpRequest;

/**
 * Represents a request factory. Allows to create a request in different ways.
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date August 2011
 */
@interface DGNHttpRequestFactory : NSObject {
    @private
    /** Authorization to associate with all created requests */
    id<DGNIAuthorization> authorization_;
}

/** Property allowing to retrieve the Authorization to associate with all created requests */
@property (nonatomic, readonly) id<DGNIAuthorization> authorization;

/**
 * Static method allowing to retrieve an instance of request factory
 * @return An instance of DGNHttpRequestFactory
 */
+ (DGNHttpRequestFactory*) defaultRequestFactory;

/**
 * Static method allowing to retrieve an instance of request factory with the given authorization
 * @param authorization Authorization value to associate to all requests that the factory will create
 * @return An instance of DGNHttpRequestFactory
 */
+ (DGNHttpRequestFactory*) requestFactoryWithAuthorization:(id<DGNIAuthorization>)authorization;

/**
 * This method allows to create an instance of DGNHttpRequest with the given parameters
 * @param method Method of the request
 * @param URL URL of the request
 * @param parameters Parameter's hashtable of the request
 * @return An instance of DGNHttpRequest
 */
- (DGNHttpRequest*) requestWithMethod:(NSString*)method url:(NSURL*)URL parameters:(id<DGFIHashTable>)parameters;

/**
 * This method allows to create an instance of DGNHttpRequest with the given parameters
 * @param method Method of the request
 * @param URL URL of the request
 * @param parameters Parameter's hashtable of the request
 * @param mimeType Mime-type of the request
 * @return An instance of DGNHttpRequest
 */
- (DGNHttpRequest*) requestWithMethod:(NSString*)method url:(NSURL*)URL parameters:(id<DGFIHashTable>)parameters mimeType:(NSString*)mimeType;

@end
