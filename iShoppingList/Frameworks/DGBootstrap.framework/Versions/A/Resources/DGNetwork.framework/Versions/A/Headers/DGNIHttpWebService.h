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
#import <DGFoundation/DGFTaskResultBlock.h>
#import <DGFoundation/DGFICancelableTask.h>

@class NSURL;
@class DGNHttpRequest, DGNHttpConnection;
@protocol DGFIParser;

/**
 * Interface describing a webservice
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date May 2012
 */
@protocol DGNIHttpWebService <DGFICancelableTask>
@required

/** Property allowing to retrieve the Web Service URL */
@property (nonatomic, readonly) NSURL* URL;

/** Property allowing to retrieve and modify the Web Service request */
@property (nonatomic, strong) DGNHttpRequest* request;

/** Property allowing to retrieve the Web Service connection */
@property (nonatomic, readonly) DGNHttpConnection* connection;

/** Property allowing to retrieve and modify the parser which transforms the Web Service result */
@property (nonatomic, strong) id<DGFIParser> parser;

/**
 * Must start asynchronously the Web Service
 * @param aResultBlock The result block to trigger when the Web Service has returned a result
 */
- (void) startWithResultBlock:(DGFTaskResultBlock) aResultBlock;

@end
