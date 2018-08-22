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

#ifndef _DGNHTTPMETHOD_H
#define _DGNHTTPMETHOD_H

#import <Foundation/NSString.h>

/** Constant for GET HTTP method */
static NSString* const kDGNHttpMethodGet = @"GET";
/** Constant for POST HTTP method */
static NSString* const kDGNHttpMethodPost = @"POST";
/** Constant for PUT HTTP method */
static NSString* const kDGNHttpMethodPut = @"PUT";
/** Constant for DELETE HTTP method */
static NSString* const kDGNHttpMethodDelete = @"DELETE";
/** Constant for HEAD HTTP method */
static NSString* const kDGNHttpMethodHead = @"HEAD";
/** Constant for OPTIONS HTTP method */
static NSString* const kDGNHttpMethodOptions = @"OPTIONS";
/** Constant for TRACE HTTP method */
static NSString* const kDGNHttpMethodTrace = @"TRACE";
/** Constant for CONNECT HTTP method */
static NSString* const kDGNHttpMethodConnect = @"CONNECT";
/** Constant for PATCH HTTP method */
static NSString* const kDGNHttpMethodPatch = @"PATCH";

#endif /** _DGNHTTPMETHOD_H */
