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
#import <DGFoundation/DGFDefines.h>

/**
 * Network information as IP address, MAC address..
 * @author Benoit BRIATTE http://www.digipolitan.com
 * @version 1.0
 * @date October 2012
 */
@interface DGNInformation : NSObject <DGFISingleton> {
    @private
    /** The mac address of the current user */
    NSString* macAddress_;
}

/**
 * Checks if network is available
 * @return YES if the network is available, otherwise NO
 */
- (BOOL) networkAvailable;

/**
 * Checks if an hostname is reachable
 * @return YES if the host is available, otherwise NO
 */
- (BOOL) hostAvailable:(NSString*) anHost;

/**
 * Checks if an IP address is available
 * @return YES if the IP address is available, otherwise NO
 */
- (BOOL) ipAddressAvailable:(NSString*) anIpAddress;

/**
 * Checks if the WIFI is available
 * @return YES if the wifi is available, otherwise NO
 */
- (BOOL) isActiveWLAN;

/**
 * Checks if the 3G/4G is available
 * @return YES if the 3G/4G is available, otherwise NO
 */
- (BOOL) isActiveWWAN;

/**
 * Retrieves an IP address using an hostname
 * @param anHost The hostname, exemple : "apple.com"
 * @return An IP address if the host is reachable, otherwise nil
 */
- (NSString*) ipAddressFromHost:(NSString*) anHost;

/**
 * Retrieves the name of the current device
 * @return The network device name
 */
- (NSString*) hostName;

/**
 * Retrieves the current IP address
 * @return The current IP address
 */
- (NSString*) ipAddress;

/**
 * Retrieves the current WIFI IP address
 * @return The current wifi IP address
 */
- (NSString*) wifiIpAddress;

/**
 * Retrieves the device MAC address
 * @return The device MAC address
 */
- (NSString*) macAddress;

@end
