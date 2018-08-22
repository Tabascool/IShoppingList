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

#import "DGNWebViewController.h"
#import <DGFoundation/DGFDefines.h>


@protocol DGNCallbackWebViewControllerDelegate;

/**
 * WebViewController which triggers an event when user click on an URL matching the callback URL
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNCallbackWebViewController : DGNWebViewController {
    @private
    __weak id<DGNCallbackWebViewControllerDelegate> delegate_;
    NSString* callbackURLString_;
}

/** Property allowing to retrieve and modify the delegate */
@property (nonatomic, weak) id<DGNCallbackWebViewControllerDelegate> delegate;

/** Property allowing to retrieve and modify the callback URL */
@property (nonatomic, strong) NSURL* callbackURL;

/**
 * Cancels the current request and triggers the event callbackWebViewControllerDidCancel
 * @param sender The sender of the action
 * @return A callback URL which contains the given baseURL
 */
- (void) cancel:(id)sender;

@end

/**
 * Delegate of the DGNCallbackWebViewController
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @copyright 2014 Digipolitan. All rights reserved.
 * @version 1.0
 * @date May 2014
 */
@protocol DGNCallbackWebViewControllerDelegate <NSObject>
@optional
/**
 * Event called when the webview did finish loading an URL and received a response
 * @param callbackWebViewController The callback WebViewController
 * @param responseURL The URL which finished loading
 */
- (void) callbackWebViewController:(DGNCallbackWebViewController*)callbackWebViewController didReceiveResponseURL:(NSURL*)responseURL;
/**
 * Event called when the user has canceled the current request
 * @param callbackWebViewController The callback WebViewController
 */
- (void) callbackWebViewControllerDidCancel:(DGNCallbackWebViewController*)callbackWebViewController;
@end