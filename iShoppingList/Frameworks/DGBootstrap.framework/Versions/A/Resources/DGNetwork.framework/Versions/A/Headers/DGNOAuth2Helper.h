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

#import <DGFoundation/DGFTaskResultBlock.h>
#import "DGNCallbackWebViewController.h"

@protocol DGNIOAuth2Service;
@class UIViewController;

/**
 * Default helper for OAuth2 protocol
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNOAuth2Helper : NSObject <DGNCallbackWebViewControllerDelegate> {
    @private
    /** The OAuth2 service */
    id<DGNIOAuth2Service> service_;
    /** The callback URL */
    NSURL* callbackURL_;
    /** The given result block for the login modal */
    DGFTaskResultBlock modallyResultBlock_;
    /** Specifies if the login modal is animated */
    BOOL modallyAnimated_;
    /** The platform is the name of the OAuth Service */
    NSString* platform_;
}

/** Property allowing to retrieve the service associated to the helper */
@property (nonatomic, readonly) id<DGNIOAuth2Service> service;
/** Property allowing to retrieve the callback URL */
@property (nonatomic, readonly) NSURL* callbackURL;
/** Property allowing to retrieve and modify the platform of the OAuth Service */
@property (nonatomic, readonly) NSString* platform;

/**
 * Initializes an OAuth2Helper with the given service
 * @param service The OAuth2 service
 * @param platform The platform of the service such as Twitter
 * @return An instance of DGNOAuth2Helper
 */
- (instancetype) initWithService:(id<DGNIOAuth2Service>) service platform:(NSString*)platform;

/**
 * Initializes an OAuth2Helper with the given service
 * @param service The OAuth service
 * @param platform The platform of the service such as Twitter
 * @param context The context to add to the default callback URL
 * @return An instance of DGNOAuth2Helper
 */
- (instancetype) initWithService:(id<DGNIOAuth2Service>) service platform:(NSString*)platform callbackContext:(NSString*)context;

/**
 * Initializes an OAuth2Helper with the given service
 * @param service The OAuth service
 * @param platform The platform of the service such as Twitter
 * @param callbackURL The callback URL
 * @return An instance of DGNOAuth2Helper
 */
- (instancetype) initWithService:(id<DGNIOAuth2Service>) service platform:(NSString*)platform callbackURL:(NSURL*)callbackURL;

/**
 * Presents the login modal for the OAuth2
 * @param viewController The OAuth2 service
 * @param animated The context to add to the specified callback URL
 * @param resultBlock The callback URL
 */
- (void) presentModallyLoginViewControllerFromViewController:(UIViewController*)viewController animated:(BOOL) animated resultBlock:(DGFTaskResultBlock /** DGNOAuth2Token* */)resultBlock;

/**
 * @return An instance of the callback webviewcontroller
 */
- (DGNCallbackWebViewController*) createCallbackWebViewController;

@end
