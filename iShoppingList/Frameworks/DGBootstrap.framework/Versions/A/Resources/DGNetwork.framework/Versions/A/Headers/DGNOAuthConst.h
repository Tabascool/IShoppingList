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

#ifndef _DGNOAUTHCONST_H
#define _DGNOAUTHCONST_H

/**
 * @file DGNOAuthConst.h
 * @project DGNetwork
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @copyright 2014 Digipolitan. All rights reserved.
 * @version 1.0
 * @date October 2014
 */

#import <Foundation/NSString.h>

/** Digipolitan callback URL for OAuth */
static NSString* const kDGNOAuthCallbackBaseURL = @"https://oauth.digipolitan.com";

/** Constant for Nonce */
static NSString* const kDGNOAuthNonce = @"oauth_nonce";
/** Constant for Timestamp */
static NSString* const kDGNOAuthTimestamp = @"oauth_timestamp";
/** Constant for Signature method */
static NSString* const kDGNOAuthSignatureMethod = @"oauth_signature_method";
/** Constant for the Version */
static NSString* const kDGNOAuthVersion = @"oauth_version";
/** Constant for the Consumer key */
static NSString* const kDGNOAuthConsumerKey = @"oauth_consumer_key";
/** Constant for Callback  */
static NSString* const kDGNOAuthCallback = @"oauth_callback";
/** Constant for Token */
static NSString* const kDGNOAuthToken = @"oauth_token";
/** Constant for Token secret */
static NSString* const kDGNOAuthTokenSecret = @"oauth_token_secret";
/** Constant for Signature */
static NSString* const kDGNOAuthSignature = @"oauth_signature";
/** Constant for Verifier */
static NSString* const kDGNOAuthVerifier = @"oauth_verifier";
/** Constant for Realm */
static NSString* const kDGNOAuthRealm = @"realm";

#endif /** _DGNOAUTHCONST_H */
