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

#import "DGNIAuthorization.h"
#import <DGFoundation/DGFDefines.h>

@class DGFAccount;

/**
 * Represents a basic authorization such as login/password credential
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2014
 */
@interface DGNHttpBasicAuthorization : NSObject <DGNIAuthorization> {
    @private
    /** The account */
    DGFAccount* account_;
    /** The header of the authorization */
    NSString* header_;
}

/** Property allowing to retrieve the account */
@property (nonatomic, readonly) DGFAccount* account;

/**
 * Initializes the basic authorization using an account
 * @param account Account to include on the header
 * @return An instance of DGNHttpBasicAuthorization
 */
- (instancetype) initWithAccount:(DGFAccount*)account;

/**
 * Checks if the current DGNHttpBasicAuthorization equals the given DGNHttpBasicAuthorization
 * @param httpBasicAuthorization The given DGNHttpBasicAuthorization
 * @return YES is the given DGNHttpBasicAuthorization equals the current, otherwise NO
 */
- (BOOL) isEqualToHttpBasicAuthorization:(DGNHttpBasicAuthorization*) httpBasicAuthorization;

@end
