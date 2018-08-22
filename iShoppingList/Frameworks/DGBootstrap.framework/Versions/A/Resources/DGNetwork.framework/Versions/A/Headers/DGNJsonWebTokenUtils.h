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
#import "DGNJsonWebTokenAlgorithm.h"

/**
 * Utils class allowing to decode and encode a string using JWT
 * @see DGNJsonWebTokenDecodeTransformer
 * @see DGNJsonWebTokenEncodeTransformer
 * @author Benoit BRIATTE
 * @version 1.0
 * @date December 2012
 */
@interface DGNJsonWebTokenUtils : NSObject

/**
 * Static method used to decode the given string
 * @param jwtString String to be decoded
 * @return Given string decoded
 */
+ (id) decodeJwtString:(NSString*) jwtString;

/**
 * Static method used to decode the given string using the signature key
 * @param jwtString String to be decoded
 * @param signatureKey The signature key to use for decoding the given string
 * @return Given string decoded
 */
+ (id) decodeJwtString:(NSString*) jwtString signatureKey:(NSString*) signatureKey;

/**
 * Static method used to encode the given object using the given signature key and the algorithm
 * @param obj Object to be encoded
 * @param signatureKey Key to use to encode the given string
 * @param alg Algorithm to use to encode the given string
 * @return Given string encoded in JWT
 */
+ (NSString*) encodeJwtObject:(id) obj signatureKey:(NSString*) signatureKey algorithm:(DGNJsonWebTokenAlgorithm)alg;

@end
