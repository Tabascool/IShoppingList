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

#import <DGFoundation/DGFDateUtils.h>
@class DGNHttpOAuthAuthorization;

/**
 * Represents an OAuthToken
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNOAuthToken : NSObject <NSCoding, NSCopying> {
    @private
    /** The Token of the OAuthToken */
    NSString* token_;
    /** The Token secret of the OAuthToken */
    NSString* tokenSecret_;
}

/** Property allowing to retrieve and modify the Token of the OAuthToken */
@property (nonatomic, strong) NSString* token;
/** Property allowing to retrieve and modify the Token secret of the OAuthToken */
@property (nonatomic, strong) NSString* tokenSecret;

/**
 * Initializes the OAuthToken with the given token
 * @param token Token of the DGNOAuthToken
 * @return An instance of DGNOAuthToken
 */
- (instancetype) initWithToken:(NSString*)token;

/**
 * Initializes the OAuthToken with the given token and token secret
 * @param token Token of the DGNOAuthToken
 * @param tokenSecret Token Secret of the DGNOAuthToken
 * @return An instance of DGNOAuthToken
 */
- (instancetype) initWithToken:(NSString*)token tokenSecret:(NSString*)tokenSecret;

/**
 * Checks if the current DGNOAuthToken equals the given DGNOAuthToken
 * @param oauthToken The given DGNOAuthToken
 * @return YES is the given DGNOAuthToken equals the current, otherwise NO
 */
- (BOOL) isEqualToOAuthToken:(DGNOAuthToken*)oauthToken;

@end
