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

#import "DGNIHttpWebService.h"

/**
 * Class allowing webservice to use HTTP protocol
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 2.0
 * @date May 2012
 */
@interface DGNHttpWebService : NSObject <DGNIHttpWebService> {
    @private
    /** Parser used to transform network data into object */
    id<DGFIParser> parser_;
    /** Webservice request */
    DGNHttpRequest* request_;
    /** Webservice connection */
    DGNHttpConnection* connection_;
    /** Result block for the webservice */
    DGFTaskResultBlock resultBlock_;
}

/**
 * Initializes the HTTP web service
 * @param anURL The request URL
 * @return An http webservice
 */
- (instancetype) initWithURL:(NSURL*) anURL;

/**
 * Initializes the HTTP web service with a specific parser
 * @param anURL The request URL
 * @param aParser Parser required to transform network data into object
 * @return An HTTP webservice
 */
- (instancetype) initWithURL:(NSURL*) anURL parser:(id<DGFIParser>) aParser;

/**
 * Initializes the HTTP web service with a custom request
 * @param request The custom request
 * @return An HTTP webservice
 */
- (instancetype) initWithRequest:(DGNHttpRequest*) request;

/**
 * Initializes the HTTP web service with a custom request and a specific parser
 * @param request The custom request
 * @param aParser Parser required to transform network data into object
 * @return An HTTP webservice
 */
- (instancetype) initWithRequest:(DGNHttpRequest*) request parser:(id<DGFIParser>) aParser;

@end

/**
 * Category use for subclasses only
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 2.0
 * @date May 2012
 */
@interface DGNHttpWebService (ForSubclassEyesOnly)

/**
 * Prepares the current request, subclasses can override this method to customize the request
 * Default implementation does nothing 
 * @param request The request to prepare
 */
- (void) _prepareRequest:(DGNHttpRequest*) request;

/**
 * Handle method when network data is received
 * @param data Network data
 * @param error Pointer to the instance of error, if an error occurred this variable is set
 */
- (id) _handleReceivedData:(NSData*) data error:(NSError*__autoreleasing*) error;

@end
