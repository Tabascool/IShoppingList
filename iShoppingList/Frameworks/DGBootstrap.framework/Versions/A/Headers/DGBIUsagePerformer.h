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

@protocol DGFICounter, DGFIRepository;
@protocol DGBIUsagePerformer;
@class DGBUsage, DGBLockingUsage;

typedef NSInteger (^DGBUsagePerformerExecuteBlock)();
typedef void (^DGBUsagePerformerExecuteAsyncBlock)(id<DGBIUsagePerformer> usagePerformer);
typedef DGBLockingUsage* (^DGBUsagePerformerLockingBlock)(NSInteger resultCode);

@protocol DGBIUsagePerformer <NSObject>
@required

@property (nonatomic, strong) id<DGFIRepository> repository;

@property (nonatomic, strong) id<DGFICounter> counter;

/**
 * Méthode permettant de savoir si un app usage est valide.
 * Un app usage valide doit matcher avec le compteur.
 * Ex :
 * - start : 5
 * - every : 2
 * - end = 14
 * counter value : out
 * 3 : NO  | 5 : YES | 6 : NO
 * 7 : YES | 9 : YES | 13 : YES
 * 14 : NO | 15 : NO
 * @param anAppUsage L'app usage à tester.
 * @return YES si l'app usage est valide, NO sinon.
 */
- (BOOL) isValidUsage:(DGBUsage*) anUsage;

/**
 * Méthode permettant de savoir si l'app usage passé en paramètre est bloqué.
 * @param anAppUsage L'app usage à tester.
 * @return YES si l'app usage est bloqué, NO sinon.
 */
- (BOOL) isLockedUsage:(DGBUsage*) anUsage;

- (BOOL) executeBlock:(DGBUsagePerformerExecuteBlock) anExecuteBlock
             forUsage:(DGBUsage*) anUsage;

- (BOOL) executeBlock:(DGBUsagePerformerExecuteBlock) anExecuteBlock
             forUsage:(DGBUsage*) anUsage
         lockingBlock:(DGBUsagePerformerLockingBlock) aBlock;

- (void) asyncBlockFinishWithResultCode:(NSInteger) aResultCode;

- (BOOL) executeAsyncBlock:(DGBUsagePerformerExecuteAsyncBlock) anAsyncExecuteBlock
                  forUsage:(DGBUsage*) anUsage;

- (BOOL) executeAsyncBlock:(DGBUsagePerformerExecuteAsyncBlock)anAsyncExecuteBlock
                  forUsage:(DGBUsage*)anUsage
              lockingBlock:(DGBUsagePerformerLockingBlock) aBlock;

@end
