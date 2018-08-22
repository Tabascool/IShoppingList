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

#import "DGNIAuthorization.h"
#import <DGFoundation/DGFDefines.h>

@protocol DGFIHashTable;
@class DGNOAuthToken;

/**
 * Represents an OAuth authorization
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNHttpOAuthAuthorization : NSObject <DGNIAuthorization> {
    @private
    /** The Consumer Key of the authorization */
    NSString* consumerKey_;
    /** The Consumer Secret of the authorization */
    NSString* consumerSecret_;
    /** The Realm of the authorization */
    NSString* realm_;
    /** The OAuth token of the authorization */
    DGNOAuthToken* oauthToken_;
}

/** Property allowing to retrieve Consumer Key of the authorization */
@property (nonatomic, readonly) NSString* consumerKey;
/** Property allowing to retrieve Consumer Secret of the authorization */
@property (nonatomic, readonly) NSString* consumerSecret;
/** Property allowing to retrieve and modify the Realm of the authorization */
@property (nonatomic, strong) NSString* realm;
/** Property allowing to retrieve and modify the OAuth token of the authorization */
@property (nonatomic, strong) DGNOAuthToken* oauthToken;

/**
 * Initializes the OAuth authorization using an account
 * @param consumerKey Consumer key for the OAuth Authorization
 * @param consumerSecret Consumer secret for the OAuth Authorization
 * @return An instance of DGNHttpOAuthAuthorization
 */
- (instancetype) initWithConsumerKey:(NSString *)consumerKey consumerSecret:(NSString *)consumerSecret;

/**
 * Checks if the current DGNHttpOAuthAuthorization equals the given DGNHttpOAuthAuthorization
 * @param httpOAuthAuthorization The given DGNHttpOAuthAuthorization
 * @return YES is the given DGNHttpOAuthAuthorization equals the current, otherwise NO
 */
- (BOOL) isEqualToHttpOAuthAuthorization:(DGNHttpOAuthAuthorization*)httpOAuthAuthorization;

@end

/**
 * Category for subclass eyes only
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @copyright 2014 Digipolitan. All rights reserved.
 * @version 1.0
 * @date July 2014
 */
@interface DGNHttpOAuthAuthorization (ForSubclassEyesOnly)

/**
 * Generates an Authorization Header with given parameters
 * @param method Method to be embedded in the Authorization
 * @param url URL to be embedded in the Authorization
 * @param parameters Parameters to be embedded in the Authorization
 * @param nonce Nonce to be embedded in the Authorization
 * @param timestamp Timestamp to be embedded in the Authorization
 * @param otoken OToken to be embedded in the Authorization
 * @return An Authorization header with the given parameters
 */
- (NSString*) _generateAuthorizationHeaderWithMethod:(NSString*) method URL:(NSURL*) url parameters:(id<DGFIHashTable>) parameters nonce:(NSString*) nonce timestamp:(NSString*) timestamp oauthToken:(DGNOAuthToken*) otoken;

@end