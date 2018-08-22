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

#import <DGFoundation/DGFICancelableTask.h>
#import <DGFoundation/DGFTaskResultBlock.h>

@protocol DGNIOAuth2Configuration;
@class DGNOAuth2Token;
@class DGFAccount;
@class NSURL;

/**
 * Interface describing an OAuth2 service
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@protocol DGNIOAuth2Service <DGFICancelableTask>
@required

/**
 * Return the configuration
 * @return The OAuth configuration of the service
 */
- (id<DGNIOAuth2Configuration>) configuration;

/**
 * Return the authorize URL
 * @return An authorize URL for the end-user
 */
- (NSURL*) authorizeURL;

/**
 * Return the authorize URL using a specific callback URL
 * @param callbackURL The callback URL @see DGNCallbackManager
 * @return An authorize URL for the end-user
 */
- (NSURL*) authorizeURLWithCallbackURL:(NSURL*)callbackURL;

/**
 * Generate the access token using the given response URL
 * @param responseURL The responseURL come from an user action in the authorize URL (in a webview).
 * @param resultBlock The result block
 */
- (void) tokenWithAuthorizeResponseURL:(NSURL*)responseURL resultBlock:(DGFTaskResultBlock /** DGNOAuth2Token */) resultBlock;

/**
 * Generate the access token with the grant type : client credentials
 * @param resultBlock The result block
 */
- (void) tokenClientCredentialsWithResultBlock:(DGFTaskResultBlock /** DGNOAuth2Token */) resultBlock;

/**
 * Generate the access token using the given account
 * @param account The account to connect
 * @param resultBlock The result block
 */
- (void) tokenWithAccount:(DGFAccount*)account resultBlock:(DGFTaskResultBlock /** DGNOAuth2Token */) resultBlock;

/**
 * Refresh the given token
 * @param token The Oauth2 token to refresh
 * @param resultBlock The result block
 */
- (void) refreshToken:(DGNOAuth2Token*) token resultBlock:(DGFTaskResultBlock /** DGNOAuth2Token */) resultBlock;

@end
