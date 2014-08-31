//
//  SISinusWaveView.h
//
//  Created by Raffael Hannemann on 12/28/13.
//  Copyright (c) 2013 Raffael Hannemann. All rights reserved.
//

#import <Cocoa/Cocoa.h>

// Make sure to add EZAudio to your project!
#import "EZAudio.h"

/** This NSView subclass can be used in conjunction with EZAudio to visualize the microphone input similar to an effect used in Apple's Siri. */
@interface SISinusWaveViewGL : NSOpenGLView <EZMicrophoneDelegate> {
	int tick; // Can be used to control the drawing FPS
}

/// The EZAudio microphone object, whose delegate is this view.
@property (nonatomic,strong) EZMicrophone *microphone;

/// The amplitude that is used when the incoming microphone amplitude is near zero. Setting a value greater 0 provides a more vivid visualization.
@property (assign) float idleAmplitude;

/// The phase of the sinus wave. Default: 0.
@property (assign) float phase;

/// The frequency of the sinus wave. The higher the value, the more sinus wave peaks you will have. Default: 1.5
@property (assign) float frequency;

/// The damping factor that is used to calm the wave down after a sound level peak. Default: 0.86
@property (assign) float dampingFactor;

/// The number of additional waves in the background. The more waves, to more CPU power is needed. Default: 4.
@property (assign) float waves;

/// The actual amplitude the view is visualizing. This amplitude is based on the microphone's amplitude
@property (assign,readonly) float amplitude;

/// The damped amplitude.
@property (assign,readonly) float dampingAmplitude;

/// The lines are joined stepwise, the more dense you draw, the more CPU power is used. Default: 5.
@property (assign) float density;

/// The phase shift that will be applied with each delivering of the microphone's value. A higher value will make the waves look more nervous. Default: -0.15.
@property (assign) float phaseShift;

/// The color to draw the waves with. Default: black.
@property (strong) NSColor *waveColor;

/// The color to draw the background with. Default: white.
@property (strong) NSColor *backgroundColor;

/// Set to NO, if you want to stop the view to oscillate. If an idleAmplitude is set, it will be used to keep the waves moving.
@property (assign,nonatomic) BOOL oscillating;

/// The width of the line to draw the waves with. Background lines will have half the width. Default: 2.
@property (assign) float lineWidth;

/// Set to NO, if you want the microphone to stop listening. Default: YES.
@property (assign,nonatomic) BOOL listen;

/// The left and right margin between view bounds and the wave oscillation beginning. Default: 0.
@property (assign) float marginLeft;
@property (assign) float marginRight;

@end