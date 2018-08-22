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

@class DGBUsage;

/**
 * Classe permettant de bloquer un usage
 * @author Benoit BRIATTE http://www.kazbaprod.com
 * @version 1.0
 * @date Octobre 2012
 */
@interface DGBLockingUsage : NSObject <NSCoding, NSCopying> {
    /** L'usage bloqué. */
    DGBUsage* usage_;
}

/** Property permettant de recuperer et bloquer l'usage. */
@property (nonatomic, strong) DGBUsage* usage;

+ (DGBLockingUsage*) newInstance;

/**
 * Méthode renvoyant YES si le locked app usage bloque toujours l'app usage.
 * Cette methode peut être redefini par des classes filles afin de modifier 
 * le comportement.
 * Par default renvois toujours YES.
 * @return YES si l'app usage est bloqué, NO sinon
 */
- (BOOL) isLocked;

@end
