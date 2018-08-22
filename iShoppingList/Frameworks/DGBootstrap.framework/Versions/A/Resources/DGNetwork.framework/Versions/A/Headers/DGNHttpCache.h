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

#import "DGNHttpCacheInfo.h"
#import <DGFoundation/DGFDefines.h>

@class NSURL, NSData;

/**
 * Represents the HTTP cache
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date May 2012
 */
@interface DGNHttpCache : NSObject <NSCoding, NSCopying> {
    @private
    /** Response data of the cache */
    NSData* response_;
    /** The URL of the cache */
    NSString* URL_;
    /** All information about the cache */
    DGNHttpCacheInfo* info_;
}

/** Property allowing to retrieve and modify the response */
@property (nonatomic, strong) NSData* response;
/** Property allowing to retrieve and modify the URL */
@property (nonatomic, strong) NSString* URL;
/** Property allowing to retrieve and modify information about this cache */
@property (nonatomic, strong) DGNHttpCacheInfo* info;

/**
 * Checks if the current DGNHttpCache equals the given DGNHttpCache
 * @param httpCache The given DGNHttpCache
 * @return YES is the given DGNHttpCache equals the current, otherwise NO
 */
- (BOOL) isEqualToHttpCache:(DGNHttpCache*)httpCache;

@end
