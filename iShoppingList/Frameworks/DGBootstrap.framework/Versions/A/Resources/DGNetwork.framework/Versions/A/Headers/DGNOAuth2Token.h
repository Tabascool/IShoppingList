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
#import <DGFoundation/DGFDefines.h>

@class NSDate;

/**
 * Represents an OAuth2Token
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNOAuth2Token : NSObject <NSCoding, NSCopying> {
    @private
    /** The access token of the OAuth2Token */
    NSString* accessToken_;
    /** The refresh token of the OAuth2Token */
    NSString* refreshToken_;
    /** The type of the OAuth2Token such as "bearer", "mac", ... */
    NSString* type_;
    /** The expiration date of the OAuth2Token */
    NSDate* expirationDate_;
}

/** Property allowing to retrieve and modify the access token of the OAuth2Token */
@property (nonatomic, strong) NSString* accessToken;
/** Property allowing to retrieve and modify the refresh token of the OAuth2Token */
@property (nonatomic, strong) NSString* refreshToken;
/** Property allowing to retrieve and modify the type ("bearer", "mac", ...) of the OAuth2Token. */
@property (nonatomic, strong) NSString* type;
/** Property allowing to retrieve and modify the expiration date of the OAuth2Token */
@property (nonatomic, strong) NSDate* expirationDate;

/**
 * Initializes the OAuth2Token with the given token and type
 * @param accessToken Access token of the DGNOAuth2Token
 * @param type Type of the DGNOAuth2Token such as "bearer", "mac", ...
 * @return An instance of DGNOAuth2Token
 */
- (instancetype) initWithAccessToken:(NSString*)accessToken type:(NSString*)type;

/**
 * Checks if the current DGNOAuth2Token equals the given DGNOAuth2Token
 * @param oauth2Token The given DGNOAuth2Token
 * @return YES is the given DGNOAuth2Token equals the current, otherwise NO
 */
- (BOOL) isEqualToOAuth2Token:(DGNOAuth2Token*)oauth2Token;

@end

