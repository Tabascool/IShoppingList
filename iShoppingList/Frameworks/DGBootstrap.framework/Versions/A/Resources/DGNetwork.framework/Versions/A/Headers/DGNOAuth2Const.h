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

#ifndef _DGNOAUTH2CONST_H
#define _DGNOAUTH2CONST_H

/** Digipolitan default callback URL for OAuth2 */
static NSString* const kDGNOAuth2CallbackBaseURL = @"http://localhost/oauth2";

/** Constant for Response type */
static NSString* const kDGNOAuth2ResponseType = @"response_type";
/** Constant for ClientId */
static NSString* const kDGNOAuth2ClientId = @"client_id";
/** Constant for Client secret */
static NSString* const kDGNOAuth2ClientSecret = @"client_secret";
/** Constant for OAuth2 code */
static NSString* const kDGNOAuth2Code = @"code";
/** Constant for Redirect uri */
static NSString* const kDGNOAuth2RedirectURI = @"redirect_uri";
/** Constant for State */
static NSString* const kDGNOAuth2State = @"state";
/** Constant for Grant type */
static NSString* const kDGNOAuth2GrantType = @"grant_type";
/** Constant for Scope */
static NSString* const kDGNOAuth2Scope = @"scope";
/** Constant for Token type */
static NSString* const kDGNOAuth2TokenType = @"token_type";
/** Constant for Access token */
static NSString* const kDGNOAuth2AccessToken = @"access_token";
/** Constant for Refresh token */
static NSString* const kDGNOAuth2RefreshToken = @"refresh_token";
/** Constant for ExpiresIn */
static NSString* const kDGNOAuth2ExpiresIn = @"expires_in";
/** Constant for Username */
static NSString* const kDGNOAuth2Username = @"username";
/** Constant for Password */
static NSString* const kDGNOAuth2Password = @"password";

/** Constant for Grant type client credentials */
static NSString* const kDGNOAuth2GrantTypeClientCredentials = @"client_credentials";
/** Constant for Grant type password */
static NSString* const kDGNOAuth2GrantTypePassword = @"password";
/** Constant for Grant type refresh token */
static NSString* const kDGNOAuth2GrantTypeRefreshToken = @"refresh_token";
/** Constant for Grant type authorization code */
static NSString* const kDGNOAuth2GrantTypeAuthorizationCode = @"authorization_code";

// Errors
/** Constant for OAuth2 Error */
static NSString* const kDGNOAuth2Error = @"error";
/** Constant for OAuth2 error description */
static NSString* const kDGNOAuth2ErrorDescription = @"error_description";
/** Constant for OAuth2 Error URI */
static NSString* const kDGNOAuth2ErrorURI = @"error_uri";
/** Constant for OAuth2 Error state */
static NSString* const kDGNOAuth2ErrorState = @"state";
/** Constant for OAuth2 State error key to be used in userInfo */
static NSString* const kDGNOAuth2StateErrorKey = @"state"; // NSError userInfo Key

/** Constant for OAuth2 Invalid request */
static NSString* const kDGNOAuth2InvalidRequest = @"invalid_request";
/** Constant for OAuth2 Unauthorized client */
static NSString* const kDGNOAuth2InvalidUnauthorizedClient = @"unauthorized_client";
/** Constant for OAuth2 Access denied */
static NSString* const kDGNOAuth2AccessDenied = @"access_denied";
/** Constant for OAuth2 Unsupported response type */
static NSString* const kDGNOAuth2UnsupportedResponseType = @"unsupported_response_type";
/** Constant for OAuth2 Invalid scope */
static NSString* const kDGNOAuth2InvalidScope = @"invalid_scope";
/** Constant for OAuth2 Server error */
static NSString* const kDGNOAuth2ServerError = @"server_error";
/** Constant for OAuth2 Temporarily unavailable */
static NSString* const kDGNOAuth2TemporarilyUnavailable = @"temporarily_unavailable";

#endif /** _DGNOAUTH2CONST_H */

