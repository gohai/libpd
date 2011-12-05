//
//  PdAudioUnit.h
//  libpd
//
//  Created on 29/09/11.
//
//  For information on usage and redistribution, and for a DISCLAIMER OF ALL
//  WARRANTIES, see the file, "LICENSE.txt," in this distribution.
//

#import <Foundation/Foundation.h>
#import "AudioUnit/AudioUnit.h"

typedef enum PdAudioStatus {
	PdAudioOK = 0,				// success
	PdAudioError = -1,			// unrecoverable error
	PdAudioPropertyChanged = 1  // some properties have changed to run correctly (not fatal)
} PdAudioStatus;

/* PdAudioUnit: object that operates pd's audio input and
 * output through an Audio Unit. The parameters can be changed
 * after it has been instatiated with its configure method,
 * which will cause the underlying audio unit to be reconstructed.
 *
 * For debugging, AU_DEBUG_VERBOSE can be defined to print extra information.
 */
@interface PdAudioUnit : NSObject {
@private
	int blockSizeAsLog_;
}

// A reference to the audio unit, which can be used to query or set other properties
@property (nonatomic, readonly) AudioUnit audioUnit;

// Check or set the active status of the audio unit
@property (nonatomic, getter = isActive) BOOL active;

// The configure method sets all parameters of the audio unit that may require it to be
// recreated at the same time.  This is an expensive process and will stop the audio unit
// before any reconstruction, causing a momentary pause in audio and UI if
// run from the main thread.
- (PdAudioStatus)configureWithNumberChannels:(int)numChannels inputEnabled:(BOOL)inputEnabled;

// Print info on the audio unit settings to the console
- (void)print;

@end