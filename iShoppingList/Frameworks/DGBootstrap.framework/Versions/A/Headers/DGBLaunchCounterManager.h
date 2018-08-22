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

#import <DGFoundation/DGFISingleton.h>
#import <DGFoundation/DGFICounter.h>

@class DGFFile;

/**
 * Classe permettant de compter le nombre de lancement de l'application.
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date Octobre 2012
 */
@interface DGBLaunchCounterManager : NSObject <DGFICounter, DGFISingleton> {
    @private
    /** Le fichier de sauvegarde. */
    DGFFile* file_;
    /** Le nombre de lancement. */
    NSInteger currentUsage_;
    /** Structure contenant les flags de la classe. */
    @package
    struct {
        /** Boolean permettant de savoir si l'incrémentation du compteur déjà été fait. */
        BOOL disabledUsage;
    } appLaunchCounterFlags_;
}

/** Property permettant de récupérer et modifier le fichier de sauvegarde. */
@property (nonatomic, readonly) DGFFile* file;

/**
 * Méthode permettant d'incrémenter le compteur, le compteur est par la suite bloqué.
 */
- (void) increaseUsage;

@end
