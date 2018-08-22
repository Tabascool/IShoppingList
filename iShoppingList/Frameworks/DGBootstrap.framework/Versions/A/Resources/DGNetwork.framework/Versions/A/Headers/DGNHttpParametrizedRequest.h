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

#import "DGNHttpRequest.h"

@protocol DGFIObjectTransformer;
@protocol DGFIMutableList, DGFIList;
@class DGNHttpParameter;

/**
 * Represents a parametrized HTTP request
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date August 2011
 */
@interface DGNHttpParametrizedRequest : DGNHttpRequest {
    @private
    /** Parameters of the request */
    id<DGFIMutableList> parameters_;
}

/** Property allowing to retrieve and modify parameters of the request */
@property (nonatomic, strong) id<DGFIList /** DGNHttpParameter */> parameters;

/**
 * Sets a string to the given field name into the request's parameters
 * @param value The string value to be associated with the field name
 * @param aField The field name into the request
 */
- (void) setStringParameter:(NSString*) value forField:(NSString*) aField;

/**
 * Sets a data to the given field name into the request's parameters
 * @param value The Data to be associated with the field name
 * @param aField The field name into the request
 */
- (void) setDataParameter:(NSData*) value forField:(NSString*) aField;

/**
 * Sets a parameter to the request's parameters
 * @param parameter The parameter to add
 */
- (void) setParameter:(DGNHttpParameter*) parameter;

/**
 * Sets parameters to the request. This method will replace old parameter list
 * @param parameters The parameters hashtable to be associated with the request
 */
- (void) setParametersWithHashtable:(id<DGFIHashTable>) parameters;

/**
 * Retrieves a parameter for the given field name
 * @param aField Field name
 */
- (DGNHttpParameter*) parameterForField:(NSString*) aField;

@end
