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

#import <DGFoundation/DGFTaskResponse.h>

@class NSData;

/**
 * This class is used to contain the response of an HTTP request
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 2.0
 * @date May 2012
 */
@interface DGNHttpTaskResponse : DGFTaskResponse {
    @private
    NSData* rawData_;
}

/** Property allowing to retrieve the raw data */
@property (nonatomic, readonly) NSData* rawData;

/**
 * Initializes an instance of DGNHttpTaskResponse with the given result and a raw result
 * @param result The result to be specified for the instance
 * @param rawData The raw of the response before parsing
 * @return An instance of DGNHttpTaskResponse
 */
- (instancetype) initWithResult:(id) result rawData:(NSData*)rawData;

/**
 * Initializes an instance of DGNHttpTaskResponse with the given error and a raw result
 * @param anError The error to be specified for the instance
 * @param rawData The raw of the response before parsing
 * @return An instance of DGNHttpTaskResponse
 */
- (instancetype) initWithError:(NSError*) anError rawData:(NSData*)rawData;

/**
 * Retrieves the raw string response
 * @return The response in string
 */
- (NSString*) rawString;

@end
