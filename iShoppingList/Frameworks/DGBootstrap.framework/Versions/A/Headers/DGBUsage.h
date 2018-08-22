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

/**
 * Classe permettant de checker des events en fonction d'un compteur.
 * @author Benoit BRIATTE http://www.kazbaprod.com
 * @version 1.0
 * @date Octobre 2012
 */
@interface DGBUsage : NSObject <NSCoding, NSCopying> {
    NSString* name_;
    /** Valeur de demarrage de l'event. */
    NSInteger starting_;
    /** L'event sera lancé tous les n every à partir de la valeur de départ. */
    NSInteger every_;
    /** Valeur de fin des events, -1 pour infini. */
    NSInteger ending_;
}

@property (nonatomic, strong) NSString* name;

/** Property permettant de recuperer et modifier la valeur de démarrage de l'event. */
@property (nonatomic, assign) NSInteger starting;

/** Property permettant de recuperer et modifier la valeur de récurrence de l'event. */
@property (nonatomic, assign) NSInteger every;

/** Property permettant de recuperer et modifier la valeur de fin de l'event. */
@property (nonatomic, assign) NSInteger ending;

@end
