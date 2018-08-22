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

#ifndef _DGNETWORK_H
#define _DGNETWORK_H

/** Standards */
#import <DGSQL/DGSQL.h>
#import "DGNConst.h"
#import "DGNetworkDependencyModule.h"

/** Connections */
#import "DGNHttpConnection.h"

/** Requests */
#import "DGNHttpMethod.h"
#import "DGNHttpRequestMimeTypeManager.h"
#import "DGNHttpRequestFactory.h"
#import "DGNHttpJsonRequest.h"
#import "DGNHttpMultiPartRequest.h"
#import "DGNHttpURLEncodedRequest.h"

/** Builders */
#import "DGNURLBuilder.h"

/** Parameters */
#import "DGNHttpParameter.h"
#import "DGNHttpFileParameter.h"

/** Network informations */
#import "DGNInformation.h"

/** Transformers */
#import "DGNURLTransformer.h"
#import "DGNJsonWebTokenDecodeTransformer.h"
#import "DGNJsonWebTokenEncodeTransformer.h"

/** Caches */
#import "DGNHttpCache.h"
#import "DGNHttpCacheInfo.h"
#import "DGNIHttpCacheRepository.h"

/** Webservices */
#import "DGNHttpModelTransformerWebService.h"
#import "DGNHttpTaskResponse.h"

/** Parsers */
#import "DGNQueryStringParser.h"

/** Auth */
#import "DGNHttpBasicAuthorization.h"

#import "DGNIOAuthConfiguration.h"
#import "DGNHttpOAuthAuthorization.h"
#import "DGNOAuthToken.h"
#import "DGNOAuthTokenProxy.h"
#import "DGNOAuthWebService.h"
#import "DGNOAuthHelper.h"

#import "DGNIOAuth2Configuration.h"
#import "DGNHttpOAuth2Authorization.h"
#import "DGNOAuth2Token.h"
#import "DGNOAuth2TokenProxy.h"
#import "DGNOAuth2WebService.h"
#import "DGNOAuth2Helper.h"

/** Callbacks */
#import "DGNCallbackManager.h"
#import "DGNCallbackWebViewController.h"

/** Utils */
#import "DGNURLBase64Utils.h"
#import "DGNJsonWebTokenUtils.h"
#import "DGNStringUtils.h"
#import "DGNErrorUtils.h"

#endif /** _DGNETWORK_H */