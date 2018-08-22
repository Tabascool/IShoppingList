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

@class NSURLConnection;
@class DGNHttpConnection;

/**
 * Interface for caching connection events
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date August 2011
 */
@protocol DGNIHttpConnectionListener <NSObject>
@optional

/**
 * Event triggered before starting the connection
 * @param aConnection The HTTP connection that raise the event
 * @param nsConnection The native connection
 */
- (void) connection:(DGNHttpConnection*) aConnection willStartConnection:(NSURLConnection*) nsConnection;

/**
 * Event triggered when an error occurred
 * @param aConnection The HTTP connection which triggered the event
 * @param anError The occurred error
 */
- (void) connection:(DGNHttpConnection *) aConnection didFailWithError:(NSError *) anError;

/**
 * Event triggered when the connection did finish loading
 * @param aConnection The HTTP connection which triggered the event
 */
- (void) connectionDidFinishLoading:(DGNHttpConnection *) aConnection;

/**
 * Event triggered when the upload is in progress
 * @param aConnection The HTTP connection which triggered the event
 * @param aPercentComplete The current percent completed
 */
- (void) connection:(DGNHttpConnection*) aConnection uploadWithPercentComplete:(float) aPercentComplete;

/**
 * Event triggered when the download is in progress
 * @param aConnection The HTTP connection raising the event
 * @param aPercentComplete The current percent completed
 */
- (void) connection:(DGNHttpConnection*) aConnection downloadWithPercentComplete:(float) aPercentComplete;

@end