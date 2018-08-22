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

#ifndef _DGNJSONWEBTOKENALGORITHM_H
#define _DGNJSONWEBTOKENALGORITHM_H

#import <Foundation/NSString.h>

static NSString* const kDGNJsonWebTokenHS256 = @"HS256";
static NSString* const kDGNJsonWebTokenHS384 = @"HS384";
static NSString* const kDGNJsonWebTokenHS512 = @"HS512";

/** List of available algorithms for JWT */
typedef enum {
    DGNJsonWebTokenAlgorithmNone,
    DGNJsonWebTokenAlgorithmHS256,
    DGNJsonWebTokenAlgorithmHS384,
    DGNJsonWebTokenAlgorithmHS512
} DGNJsonWebTokenAlgorithm;

/**
 * Determines the JWT algorithm corresponding to the given string
 * @param str A string representing the algorithm
 * @return The corresponding value of DGNJsonWebTokenAlgorithm
 */
static inline DGNJsonWebTokenAlgorithm DGNJsonWebTokenAlgorithmFromString(NSString* str) {
    if([str isEqualToString:kDGNJsonWebTokenHS256]) {
        return DGNJsonWebTokenAlgorithmHS256;
    } else if([str isEqualToString:kDGNJsonWebTokenHS384]) {
        return DGNJsonWebTokenAlgorithmHS384;
    } else if([str isEqualToString:kDGNJsonWebTokenHS512]) {
        return DGNJsonWebTokenAlgorithmHS512;
    }
    return DGNJsonWebTokenAlgorithmNone;
}

/**
 * Returns a string value matching to the given JWT algorithm
 * @param alg The JWT algorithm
 * @return A string value matching to the given JWT algorithm
 */
static inline NSString* NSStringFromJsonWebTokenAlgorithm(DGNJsonWebTokenAlgorithm alg) {
    switch (alg) {
        case DGNJsonWebTokenAlgorithmHS256:
            return kDGNJsonWebTokenHS256;
        case DGNJsonWebTokenAlgorithmHS384:
            return kDGNJsonWebTokenHS384;
        case DGNJsonWebTokenAlgorithmHS512:
            return kDGNJsonWebTokenHS512;
        default:
            return nil;
    }
}

#endif /** _DGNJSONWEBTOKENALGORITHM_H */