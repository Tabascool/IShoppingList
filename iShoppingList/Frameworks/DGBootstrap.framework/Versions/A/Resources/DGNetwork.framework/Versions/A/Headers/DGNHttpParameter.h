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

@class NSData;

/**
 * Represents a request parameter in a request
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date November 2012
 */
@interface DGNHttpParameter : NSObject <NSCoding, NSCopying> {
    @private
    /** Parameter name */
    NSString* name_;
    /** Parameter value */
    NSString* value_;
    /** Parameter data */
    NSData* data_;
}

/**
 * Initializes an instance of HTTP parameter with a name and a value
 * @param name The parameter value
 * @param value The parameter value
 * @return An initialized HTTP parameter with the given parameters
 */
- (instancetype) initWithName:(NSString*) name value:(NSString*) value;

/**
 * Initializes an instance of HTTP parameter with a name and a value
 * @param name The parameter value
 * @param value The parameter value
 * @return An initialized HTTP parameter with the given parameters
 */
- (instancetype) initWithName:(NSString*) name data:(NSData *)aData;

/**
 * Checks if the current DGNHttpParameter equals the given DGNHttpParameter
 * @param parameter The given DGNHttpParameter
 * @return YES is the given DGNHttpParameter equals the current, otherwise NO
 */
- (BOOL) isEqualToHttpParameter:(DGNHttpParameter*)parameter;

/** Property allowing to retrieve and modify the parameter name */
@property (nonatomic, strong) NSString* name;

/** Property allowing to retrieve and modify the parameter value */
@property (nonatomic, strong) NSString* value;

/** Property allowing to retrieve and modify the parameter data */
@property (nonatomic, strong) NSData* data;

@end
