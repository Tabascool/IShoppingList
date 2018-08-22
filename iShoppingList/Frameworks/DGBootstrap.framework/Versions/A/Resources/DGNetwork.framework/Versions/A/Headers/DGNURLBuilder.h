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
#import <DGFoundation/DGFDefines.h>

@class NSURL;
@class DGFAccount;
@protocol DGFIMutableList, DGFIList, DGFIHashTable;
@class DGNHttpParameter;

/**
 * Class allowing to build an URL step by step
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date November 2012
 */
@interface DGNURLBuilder : NSObject {
    @private
    /** URL Scheme (HTTP, FTP, SSH) */
    NSString* scheme_;
    /** The account to use in case of authentication */
    DGFAccount* account_;
    /** The server */
    NSString* host_;
    /** The port number including values between 0 and 65535 */
    NSUInteger port_;
    /** The path in the server */
    NSString* path_;
    /** List containing URL parameters */
    id<DGFIMutableList> queryParameters_;
    /** The URL fragment (#...) */
    NSString* fragment_;
}

/** Property allowing to retrieve and modify the URL Scheme (HTTP, FTP, SSH) */
@property (nonatomic, strong) NSString* scheme;
/** Property allowing to retrieve and modify the account to use in case of authentication */
@property (nonatomic, strong) DGFAccount* account;
/** Property allowing to retrieve and modify the server */
@property (nonatomic, strong) NSString* host;
/** Property allowing to retrieve and modify the port number including values between 0 and 65535 */
@property (nonatomic, assign) NSUInteger port;
/** Property allowing to retrieve and modify the path in the server */
@property (nonatomic, strong) NSString* path;
/** Property allowing to retrieve and modify the list containing URL parameters */
@property (nonatomic, readonly) id<DGFIList> queryParameters;
/** Property allowing to retrieve and modify the URL fragment (#...) */
@property (nonatomic, strong) NSString* fragment;

/**
 * Initializes an instance of URL builder with a string representing an URL
 * @param aStringURL String representation of a valid URL
 * @return An initialized URL builder with the given String
 */
- (instancetype) initWithString:(NSString*) aStringURL;

/**
 * Initializes an instance of URL builder with an URL
 * @param anURL URL to bind into the URL builder
 * @return An initialized URL builder with the given URL
 */
- (instancetype) initWithURL:(NSURL*) anURL;

/**
 * Changes the current URL with the given string. All builder informations will reset
 * @param anURLString String representation of a valid URL
 */
- (void) setString:(NSString*) anURLString;

/**
 * Changes the current URL with the given URL. All builder informations will reset
 * @param anURL URL to bind into the URL builder
 */
- (void) setURL:(NSURL*) anURL;

/**
 * Builds the current URL with all its parameters
 * @return An URL initialized with all its parameters or nil if an error occurred
 */
- (NSURL*) buildURL;

/**
 * Changes the query of the current Builder
 * @param query A string representation of a query. Example : "a1=2&a2=AB"
 */
- (void) setQueryString:(NSString*) query;

/**
 * Adds a query parameter to the builder
 * @param parameter The query parameter to add
 */
- (void) setQueryParameter:(DGNHttpParameter*) parameter;

/**
 * Adds a parameter to the builder
 * @param aValue The parameter value
 * @param aName The parameter name
 */
- (void) setQueryParameter:(NSString*) aValue forName:(NSString*) aName;

/**
 * Adds the given map to the builder
 * @param queryParameters New parameters to bind in the builder
 */
- (void) setQueryParametersWithHashTable:(id<DGFIHashTable>)queryParameters;

/**
 * Retrieves the parameter corresponding to the given name from the builder's query parameters
 * @param aName The name of the query parameter
 * @return The corresponding parameter or nil
 */
- (DGNHttpParameter*) queryParameterForName:(NSString*)aName;

/**
 * Removes the parameter corresponding to the given name from the builder's query parameters
 * @param aName The name of the query parameter
 */
- (void) removeQueryParameterForName:(NSString*) aName;

/**
 * Removes all query parameters
 */
- (void) removeAllQueryParameters;

@end
