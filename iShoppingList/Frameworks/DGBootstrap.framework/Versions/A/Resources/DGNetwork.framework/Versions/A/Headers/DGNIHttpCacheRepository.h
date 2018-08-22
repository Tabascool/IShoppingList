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

#import <DGFoundation/DGFIRepository.h>
#import <DGFoundation/DGFDefines.h>

@class DGNHttpCache, DGNHttpCacheCriteria;

/**
 * Interface allowing to store and retrieve HTTP cache objects
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date June 2012
 */
@protocol DGNIHttpCacheRepository <DGFIRepository>
@required

/**
 * Must store an HTTP cache
 * @param cache The cache to be stored
 */
- (void) addObject:(DGNHttpCache*) cache;

/**
 * Must remove an HTTP cache
 * @param cache The cache to be removed
 */
- (void) removeObject:(DGNHttpCache*) cache;

/** Must remove all out of date HTTP cache. An out of date cache is a cache with the limit date before now */
- (void) removeOutOfDate;

/**
 * Must find only one result with an HTTP cache criteria
 * @param searchCriteria The search criteria
 * @param aResultBlock The result block containing the found cache
 */
- (void) find:(DGNHttpCacheCriteria*) searchCriteria resultBlock:(DGFTaskResultBlock /** DGNHttpCache */) aResultBlock;

/**
 * Must search results with an HTTP cache criteria
 * @param searchCriteria The search criteria
 * @param aResultBlock The result block containing found caches
 */
- (void) search:(DGNHttpCacheCriteria*) searchCriteria resultBlock:(DGFTaskResultBlock /** List<DGNHttpCache> */) aResultBlock;

/**
 * Must retrieve all out of date HTTP cache
 * @param aResultBlock The result block containing out of date caches
 */
- (void) getOutOfDateWithResultBlock:(DGFTaskResultBlock /** List<DGNHttpCache> */) aResultBlock;

@end
