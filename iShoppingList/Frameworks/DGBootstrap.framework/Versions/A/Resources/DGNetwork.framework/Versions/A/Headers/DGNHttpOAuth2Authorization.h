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

@class DGNOAuth2Token;

/**
 * Represents an OAuth2 authorization
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNHttpOAuth2Authorization : NSObject <DGNIAuthorization> {
    @private
    /** The OAuth token of the authorization */
    DGNOAuth2Token* oauth2Token_;
}

/** Property allowing to retrieve and modify the OAuth2 token of the authorization */
@property (nonatomic, strong) DGNOAuth2Token* oauth2Token;

/**
 * Initializes the Auth2 authorization using an account
 * @param oauthToken Token for the OAuth2 Authorization
 * @return An instance of DGNHttpOAuth2Authorization
 */
- (instancetype) initWithToken:(DGNOAuth2Token*)oauthToken;

/**
 * Checks if the current DGNHttpOAuth2Authorization equals the given DGNHttpOAuth2Authorization
 * @param httpOAuthAuthorization The given DGNHttpOAuth2Authorization
 * @return YES is the given DGNHttpOAuth2Authorization equals the current, otherwise NO
 */
- (BOOL) isEqualToHttpOAuth2Authorization:(DGNHttpOAuth2Authorization*)httpOAuth2Authorization;

@end
