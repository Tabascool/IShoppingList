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

#import <Foundation/NSString.h>
#import <DGFoundation/DGFDefines.h>
#import <Foundation/NSDate.h>

@protocol DGFIHashTable, DGFIObjectTransformer, DGNIAuthorization;
@class DGNHttpBodyParameter, DGNHttpCacheInfo;
@class NSMutableData, NSURLRequest, NSMutableURLRequest;

/** Represents the default timeout for the http request */
DGFExtern NSTimeInterval const kDGNHttpRequestDefaultTimeout;

/**
 * Represents the default HTTP request
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date August 2011
 */
@interface DGNHttpRequest : NSObject <NSCoding, NSCopying> {
    @private
    /** The request on which the DGNHttpRequest is based. It also will contain the body */
    NSMutableURLRequest* request_;
    /** Temporary body for the request creation */
    NSMutableData* body_;
    /** The cache info describing how to cache the request */
    DGNHttpCacheInfo* cacheInfo_;
    /** The authorization of the request */
    id<DGNIAuthorization> authorization_;
    /** Transformer generating the request body from an undefined object */
    id<DGFIObjectTransformer> bodyTransformer_;
}

/**
 * Initializes an instance of DGNHttpRequest with the given URL
 * @param url The URL to associate to the request
 * @return An instance of DGNHttpRequest initialized with the given URL
 */
- (instancetype) initWithURL:(NSURL*) url;

/**
 * Initializes an instance of DGNHttpRequest with the given URL and method
 * @param url The URL to associate to the request
 * @param method The method of the request (POST, GET, ...) @see DGNHttpMethod.h
 * @return An instance of DGNHttpRequest initialized with the given URL and method
 */
- (instancetype) initWithURL:(NSURL*) url method:(NSString*) method;

/** Property allowing to retrieve and modify the cache info describing how to cache the request */
@property (nonatomic, strong) DGNHttpCacheInfo* cacheInfo;
/** Property allowing to retrieve and modify the URL associated to the request */
@property (nonatomic, strong) NSURL* URL;
/** Property allowing to retrieve and modify the timeout of the request */
@property (nonatomic, assign) NSTimeInterval timeout;
/** Property allowing to retrieve and modify the HTTP method of the request @see DGNHttpMethod.h */
@property (nonatomic, strong) NSString* httpMethod;
/** Property allowing to retrieve and modify the authorization of the request */
@property (nonatomic, strong) id<DGNIAuthorization> authorization;
/** Property allowing to retrieve and modify the transformer generating the request body from an undefined object */
@property (nonatomic, strong) id<DGFIObjectTransformer> bodyTransformer;

/**
 * Retrieves all HTTP header fields
 * @return An instance of DGFIHashTable containing all HTTP header fields
 */
- (id<DGFIHashTable>) allHttpHeaderFields;

/**
 * Changes all HTTP header fields with the given fields
 * @param httpHeaderFields New header fields to associate to the request
 */
- (void) setAllHttpHeaderFields:(id<DGFIHashTable>) httpHeaderFields;

/**
 * Retrieves the value associated to the given field
 * @param field The header field
 * @return The value associated to the given field
 */
- (NSString*) httpHeaderForField:(NSString*) field;

/**
 * Sets the given value for the given field in HTTP header
 * If another value exists it will replace it
 * @param value New value fields to associate to the request
 * @param field New header fields to associate to the request
 */
- (void) setValue:(NSString*) value forHttpHeaderField:(NSString*) field;

/**
 * Adds the given value for the given field in http header
 * @param value New value fields to associate to the request
 * @param field header fields to associate to the request
 */
- (void) addValue:(NSString*) value forHttpHeaderField:(NSString*) field;

#pragma mark -
#pragma mark Méthodes de modifcation du Body (POST)

/**
 * Retrieves the current body
 * @return The body of the request
 */
- (NSData*) httpBody;

/** Clears the HTTP body */
- (void) clearHttpBody;

/**
 * Adds the given String to the HTTP body
 * @param aBody UTF-8 String to add to the request
 */
- (void) addHttpBodyString:(NSString*) aBody;

/**
 * Adds the given String to the HTTP body with the given encoding
 * @param aBody String to add to the request
 * @param anEncoding The encoding of the body
 */
- (void) addHttpBodyString:(NSString*) aBody usingEncoding:(NSStringEncoding) anEncoding;

/**
 * Adds the given Data to the HTTP body
 * @param aBody Data to add to the request
 */
- (void) addHttpBody:(NSData*) aBody;

/**
 * Sets the given object to the HTTP body
 * Uses the body transformer to transform this obj on String or Data
 * @param obj The object to bind into the request
 */
- (void) setHttpBodyObject:(id) obj;

@end

/**
 * Category for connection eyes only
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @copyright 2014 Digipolitan. All rights reserved.
 * @version 1.0
 * @date August 2011
 */
@interface DGNHttpRequest (ForConnectionEyesOnly)
/**
 * Builds the current request by associating its body
 * It clears the body after associating
 * @return An instance of NSURLRequest associated with the body
 */
- (NSURLRequest*) buildRequest;
@end

#pragma mark -
