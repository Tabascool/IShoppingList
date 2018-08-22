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

#import "DGNIOAuth2Service.h"

@protocol DGNIHttpWebService;
@class DGFModelFactory;
@class DGNHttpBasicAuthorization, DGNOAuth2TokenProxy;

/**
 * Represents an OAuth2 webservice
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNOAuth2WebService : NSObject <DGNIOAuth2Service> {
    @private
    /** The OAuth2 service to use for retrieving an access token using client credentials */
    id<DGNIHttpWebService> oauth2ClientCredentialsAccessTokenWebService_;
    /** The OAuth2 service to use for retrieving an access token using an account */
    id<DGNIHttpWebService> oauth2AccountAccessTokenWebService_;
    /** The OAuth2 service to use for retrieving an access token using a code */
    id<DGNIHttpWebService> oauth2CodeAccessTokenWebService_;
    /** The OAuth2 service to use for refreshing an access token */
    id<DGNIHttpWebService> oauth2RefreshAccessTokenWebService_;
    /** The OAuth2 configuration */
    id<DGNIOAuth2Configuration> configuration_;
    /** The OAuth2 authorization used to obtain limited access to an HTTP service */
    DGNHttpBasicAuthorization* authorization_;
}

/**
 * Initializes an OAuth2 webservice with the configuration
 * @param configuration Configuration of the webservice
 * @return An instance of DGNOAuth2WebService
 */
- (instancetype) initWithConfiguration:(id<DGNIOAuth2Configuration>) configuration;

/**
 * @return The authorization of OAuth2 webservice
 */
- (DGNHttpBasicAuthorization*) authorization;

/**
 * @return The token proxy of OAuth2 webservice
 */
- (DGNOAuth2TokenProxy*) tokenProxy;

@end
