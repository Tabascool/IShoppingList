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

#import <UIKit/UIViewController.h>
#import <UIKit/UIWebView.h>

@class UIWebView;

/**
 * ViewController allows the DGNetwork framework to display a webview. For example it's used by the OAuth connection
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 2.0
 * @date May 2012
 */
@interface DGNWebViewController : UIViewController <UIWebViewDelegate> {
    @private
    NSURL* requestURL_;
    UIBarButtonItem* previousBarButton_;
    UIBarButtonItem* nextBarButton_;
}

/** Property allowing to retrieve and modify the webview */
@property (nonatomic, strong) IBOutlet UIWebView* webView;

/** Property allowing to retrieve and modify the request URL to be displayed by the webview */
@property (nonatomic, strong) NSURL* requestURL;

/**
 * Display the previous page on the pile of pages WebView
 * @param sender The action's sender
 */
- (void) goBack:(id) sender;

/**
 * Display the next page on the pile of pages WebView
 * @param sender The action's sender
 */
- (void) goForward:(id) sender;

/**
 * Reload the current page of the webview
 * @param sender The action's sender
 */
- (void) reload:(id) sender;

@end