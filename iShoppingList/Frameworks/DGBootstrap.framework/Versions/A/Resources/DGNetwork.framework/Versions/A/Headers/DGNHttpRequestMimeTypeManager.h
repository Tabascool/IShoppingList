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

#import <DGFoundation/DGFISingleton.h>

@protocol DGFIMutableHashTable;

/**
 * Singleton class allowing to define a specific request class for a Mime-type
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date August 2011
 */
@interface DGNHttpRequestMimeTypeManager : NSObject <DGFISingleton> {
    @private
    /** Registry which contains all specified request class for Mime-type */
    id<DGFIMutableHashTable> requestRegistry_;
}

/**
 * Registers a request class for the specified Mime-type
 * @param requestClass The request class to be registred
 * @param mimeType The Mime-type of the request to be registred
 */
- (void) registerRequest:(Class/** DGNHttpRequest */)requestClass forMimeType:(NSString*)mimeType;

/**
 * Remove the request class for the given Mime-type
 * @param mimeType The Mime-type of the request to be removed
 */
- (void) removeRequestForMimeType:(NSString*)mimeType;

/**
 * Retrieves the request class associated to the specified Mime-Type
 * @param mimeType The Mime-type of the request
 * @return The registred request class. Often it's DGNHttpRequest
 */
- (Class) requestForMimeType:(NSString*)mimeType;

@end
