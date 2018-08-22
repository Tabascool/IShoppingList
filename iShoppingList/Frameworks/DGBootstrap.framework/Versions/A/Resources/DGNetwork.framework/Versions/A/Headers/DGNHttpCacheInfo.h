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

#import <Foundation/NSDate.h>
#import "DGNHttpCacheInfoType.h"
#import <DGFoundation/DGFDefines.h>

/**
 * This class allowing to describe information about cache
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date May 2012
 */
@interface DGNHttpCacheInfo : NSObject <NSCoding, NSCopying> {
    @private
    /** Limit date for the cache */
    NSDate* cacheLimitDate_;
    /** Type of the cache : heavy or light */
    DGNHttpCacheInfoType type_;
    /** Specifies if the cache need to be encrypted */
    BOOL secure_;
}

/** Property allowing to retrieve and modify limit date for the cache */
@property (nonatomic, strong) NSDate* cacheLimitDate;

/** Property allowing to retrieve and modify the cache type : heavy or light */
@property (nonatomic, assign) DGNHttpCacheInfoType type;

/** Property allowing to retrieve and modify if the cache need to be encrypted */
@property (nonatomic, assign, getter = isSecure) BOOL secure;

/**
 * Factory method allowing to create an instance of CacheInfo with the cache
 * @param cacheDuration TTL for the cache
 * @return An instance of DGNHttpCacheInfo initialized with the cache and storage duration
 */
+ (DGNHttpCacheInfo*) cacheInfoWithCacheDuration:(NSTimeInterval) cacheDuration;

/**
 * Sets the cache TTL
 * @param cacheDuration TTL for the cache
 */
- (void) setCacheDuration:(NSTimeInterval) cacheDuration;

/**
 * Checks if the current DGNHttpCacheInfo equals the given DGNHttpCacheInfo
 * @param httpCache The given DGNHttpCacheInfo
 * @return YES is the given DGNHttpCacheInfo equals the current, otherwise NO
 */
- (BOOL) isEqualToHttpCacheInfo:(DGNHttpCacheInfo*)httpCacheInfo;

@end
