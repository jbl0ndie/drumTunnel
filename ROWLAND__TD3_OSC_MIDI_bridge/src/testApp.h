/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#pragma once

#include "ofMain.h"

#include "ofxMidi.h"
//#include "ofxOsc.h"
#include "simpleParticleManager.h"
#include "trailShaderAddon.h"
#include "ofxGui.h"

#define HOST "localhost"
#define PORT_OUT 12333
#define PORT_IN  3333

class testApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased();
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	stringstream text;
	
	ofxMidiIn midiIn;
	ofxMidiMessage midiMessage;
	ofxMidiOut midiOut;

    int channel;
	
	unsigned int currentPgm;
	int note, velocity;
	int pan, bend, touch, polytouch;
    
    
    //ofxOscSender sender;
    //ofxOscReceiver receiver;
    
    
    struct input{
        int id_num;
        ofColor colour = ofColor(0);
        ofVec2f pos;
    };
    
    vector<input> inputList;
    
    ofImage bg;
    
    simpleParticleManager pm;
    trailShader ts;
    
    
    bool drawGui;
    ofxGuiGroup gui;
    ofxSlider<float> scale;
    ofxSlider<float> attack;
    ofxSlider<float> decay;
    
    
    
};
