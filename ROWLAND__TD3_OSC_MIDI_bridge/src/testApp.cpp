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
#include "testApp.h"

#define NUM_INPUTS 13
#define NUM_P 10000
#define LIFE 2000

int timeF=0;
int prevTime=0;
int dist = 730;

ofVec2f vel = ofVec2f(0,-3);

int inputs[NUM_INPUTS] = {36,38,22,42,26,46,44,48,41,55,49,51,53};
//--------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	ofBackground(22);
    ofSetFrameRate(60);
    
    
    bg.loadImage("DrumTunnel_BG_RS.jpg");
    
    
    gui.setup();
    gui.setPosition(20,20);
    gui.add(scale.setup("Scale", 1.0, 0.0, 1.0));
    gui.add(attack.setup("Attack", 1.0, 0.0, 1.0));
    gui.add(decay.setup("Decay", 1.0, 0, 1));
    
    //bg.loadImage("/Users/Adam/Downloads/of_v0.8.0_osx_release/apps/drumTunnel/ROWLAND__TD3_OSC_MIDI_bridge/data/DrumTunnel_BG_RS.jpg");
    
    
    pm.setCount(NUM_P);
    
    ts.init();
    //../data/DrumTunnel_BG_RS.jpg
    
    
    
	//ofSetLogLevel(OF_LOG_VERBOSE);
	
    // -------------------------- Output
    
    
	// print input ports to console
	midiIn.listPorts(); // via instance
	//ofxMidiIn::listPorts(); // via static as well
	
	// open port by number (you may need to change this)
	midiIn.openPort(0);
	//midiIn.openPort("IAC Pure Data In");	// by name
	//midiIn.openVirtualPort("ofxMidiIn Input"); // open a virtual port
	
	// don't ignore sysex, timing, & active sense messages,
	// these are ignored by default
	midiIn.ignoreTypes(false, false, false);
	
	// add testApp as a listener
	midiIn.addListener(this);
	
	// print received messages to the console
	midiIn.setVerbose(true);
    

    
    
    
    // ---------------------------- INPUT
    
    
    // print the available output ports to the console
	//midiOut.listPorts(); // via instance
	//ofxMidiOut::listPorts(); // via static too
	
	// connect
	//midiOut.openPort(0); // by number
	//midiOut.openPort("IAC Driver Pure Data In"); // by name
	//midiOut.openVirtualPort("ofxMidiOut"); // open a virtual port
	
//	channel = 1;
//	currentPgm = 0;
//	note = 0;
//	velocity = 0;
//	pan = 0;
//	bend = 0;
//	touch = 0;
//	polytouch = 0;
    
    
    //receiver.setup(PORT_IN);
    
    
    for (int i=0; i<NUM_INPUTS; i++) {
        input in;
        in.id_num = inputs[i];
        in.pos    = ofVec2f(i*40,0);
        inputList.push_back(in);

    }
}

//--------------------------------------------------------------
void testApp::update() {
    
    pm.setCount(NUM_P);
    pm.setLife(LIFE);
    pm.update();
    

    

    /*

    while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        
        ofLog() << " --> " << m.getAddress();
        
		// check for mouse moved message
		if(m.getAddress() == "/1/backFade0"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(1, 7, mapped);
		}
		if(m.getAddress() == "/1/backFade1"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(2, 7, mapped);
		}
		if(m.getAddress() == "/1/backFade2"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(3, 7, mapped);
		}
		if(m.getAddress() == "/1/backFade3"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(4, 7, mapped);
		}
		if(m.getAddress() == "/1/backFade4"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(5, 7, mapped);
		}
		if(m.getAddress() == "/1/backFade5"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(6, 7, mapped);
		}
		if(m.getAddress() == "/1/backFade6"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(7, 7, mapped);
		}
		if(m.getAddress() == "/1/backFade7"){
			// both the arguments are int32's
            int mapped = ofMap(m.getArgAsFloat(0), 0, 1, 0, 127);
            midiOut.sendControlChange(8, 7, mapped);
		}
        
    }
     */

}

//--------------------------------------------------------------
void testApp::draw() {
    
    ofSetColor(255);
    
    bg.draw(0, 0);
    
    
    
    
	ofSetColor(255,0,175);
    
    /*
	
	// draw the last recieved message contents to the screen
	text << "Received: " << ofxMidiMessage::getStatusString(midiMessage.status);
	ofDrawBitmapString(text.str(), 20, 20);
	text.str(""); // clear
	
	text << "channel: " << midiMessage.channel;
	ofDrawBitmapString(text.str(), 20, 34);
	text.str(""); // clear
	
	text << "pitch: " << midiMessage.pitch;
	ofDrawBitmapString(text.str(), 20, 48);
	text.str(""); // clear
	ofRect(20, 58, ofMap(midiMessage.pitch, 0, 127, 0, ofGetWidth()-40), 20);
	
	text << "velocity: " << midiMessage.velocity;
	ofDrawBitmapString(text.str(), 20, 96);
	text.str(""); // clear
	ofRect(20, 105, ofMap(midiMessage.velocity, 0, 127, 0, ofGetWidth()-40), 20);
	
	text << "control: " << midiMessage.control;
	ofDrawBitmapString(text.str(), 20, 144);
	text.str(""); // clear
	ofRect(20, 154, ofMap(midiMessage.control, 0, 127, 0, ofGetWidth()-40), 20);
	
	text << "value: " << midiMessage.value;
	ofDrawBitmapString(text.str(), 20, 192);
	text.str(""); // clear
	if(midiMessage.status == MIDI_PITCH_BEND) {
		ofRect(20, 202, ofMap(midiMessage.value, 0, MIDI_MAX_BEND, 0, ofGetWidth()-40), 20);
	}
	else {
		ofRect(20, 202, ofMap(midiMessage.value, 0, 127, 0, ofGetWidth()-40), 20);
	}
	
	text << "delta: " << midiMessage.deltatime;
	ofDrawBitmapString(text.str(), 20, 240);
	text.str(""); // clear
    
     */
    


    for (int i=0; i<NUM_INPUTS; i++) {
        
        input &drum = inputList[i];
        ofFill();
        
        ofSetColor(drum.colour);
        ofCircle(((ofGetWidth()/NUM_INPUTS)*i)+20, 757, 15);
        
        ofSetColor(255);
        ofNoFill();
        ofCircle(((ofGetWidth()/NUM_INPUTS)*i)+20, 757, 16);
        
        
        drum.colour = ofColor(0);
        
    }
    
    
    ts.begin();
    ofFill();
    ofSetColor(255);
    for (int i=0; i<NUM_P; i++) {
        if ( pm.getActive(i) == true){
            ofVec2f pos = pm.getPosition(i);
            ofSetColor(pm.getColour(i));
            ofRect(pos.x, (pos.y*scale)+dist, 40,5);
        }
    }
    ts.end(attack,decay);
    
    ofSetColor(255);
    ofStyle style;
    style.blendingMode = OF_BLENDMODE_ADD;
    ofPushStyle();
    ofSetStyle(style);
    ts.draw(0,0);
    ofPopStyle();
    
    if (drawGui){
        gui.draw();
    }
    
    ofDrawBitmapString("Press 'g' for gui", 20, 15);
    
    
//    //	stringstream text;
//	text << "connected to port " << midiOut.getPort()
//    << " \"" << midiOut.getName() << "\"" << endl
//    << "is virtual?: " << midiOut.isVirtual() << endl << endl
//    << "sending to channel " << channel << endl << endl
//    << "current program: " << currentPgm << endl << endl
//    << "note: " << note << endl
//    << "velocity: " << velocity << endl
//    << "pan: " << pan << endl
//    << "bend: " << bend << endl
//    << "touch: " << touch << endl
//    << "polytouch: " << polytouch;
//	ofDrawBitmapString(text.str(), 20, 300);
}

//--------------------------------------------------------------
void testApp::exit() {
	
	// clean up
	midiIn.closePort();
	midiIn.removeListener(this);
	midiOut.closePort();
}

//--------------------------------------------------------------
void testApp::newMidiMessage(ofxMidiMessage& msg) {

	// make a copy of the latest message
	midiMessage = msg;
    

    if (midiMessage.channel == 10) {
        

        cout << midiMessage.pitch << endl;
        
        int pitch = midiMessage.pitch;
        
        for (int i=0; i<NUM_INPUTS; i++) {
            
            input &drum = inputList[i];
            
            if (drum.id_num == pitch) {
                drum.colour = ofColor(255,0,100);
                pm.emit(drum.colour, drum.pos, vel);
            }
        }
    }
    
    
//    if (midiMessage.channel == 11){
//        
//        string msgAdd;
//        msgAdd = "/1/button";
//        msgAdd += ofToString(midiMessage.value);
//        
//        ofxOscMessage m;
//        m.setAddress(msgAdd);
//        m.addIntArg(1);
//        sender.sendMessage(m);
//        cout << midiMessage.value << endl;
//        
//
//    }
//    
//
//    if (midiMessage.control == 10){
//        if (midiMessage.channel == 1) {
//            if      (midiMessage.value == 0 )  { timeF = 0;}
//            else if (midiMessage.value == 127) { timeF = 1;}
//            else if (midiMessage.value < prevTime) {timeF = 0;}
//            else if (midiMessage.value > prevTime) {timeF = 1;}
//
//            prevTime = midiMessage.value;
//            ofxOscMessage m;
//            m.setAddress("/1/encoder1");
//            m.addIntArg(timeF);
//            sender.sendMessage(m);
//            cout << timeF << endl;
//            cout << midiMessage.value << endl;
//        }
//        if (midiMessage.channel == 2) {
//            if      (midiMessage.value == 0 )  { timeF = 10;}
//            else if (midiMessage.value == 127) { timeF = 20;}
//            else if (midiMessage.value < prevTime) {timeF = 10;}
//            else if (midiMessage.value > prevTime) {timeF = 20;}
//            
//            prevTime = midiMessage.value;
//            ofxOscMessage m;
//            m.setAddress("/1/encoder2");
//            m.addIntArg(timeF);
//            sender.sendMessage(m);
//            cout << timeF << endl;
//            cout << midiMessage.value << endl;
//        
//        
//        }
//    }
//    
//    
//    if (midiMessage.control == 7){
//        if (midiMessage.channel == 1) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader1");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        
//        if (midiMessage.channel == 2) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader2");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        
//        if (midiMessage.channel == 3) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader3");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        if (midiMessage.channel == 4) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader4");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        if (midiMessage.channel == 5) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader5");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        if (midiMessage.channel == 6) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader6");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        if (midiMessage.channel == 7) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader7");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        if (midiMessage.channel == 8) {
//            
//            ofxOscMessage m;
//            m.setAddress("/1/fader8");
//            m.addFloatArg(ofMap(midiMessage.value, 0, 127, 0, 1));
//            sender.sendMessage(m);
//        }
//        
//    }
    //cout << ofToString(msg) << endl;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
    
    if (key == 'g') {
        drawGui = !drawGui;
    }
    /*
	if(key == 'a' || key == 'A'){
		ofxOscMessage m;
		m.setAddress("/1/fader1");
		m.addIntArg(1);
        //		m.addFloatArg(3.5f);
        //		m.addStringArg("hello");
        //		m.addFloatArg(ofGetElapsedTimef());
		sender.sendMessage(m);
	}
     */
    
    
    ofVec2f p1;
    ofColor col;

	switch(key) {

		case '1':
            p1 = ofVec2f(0,0);
            col = ofColor(255,0,100);
            pm.emit(col, p1, vel);
            break;
            

        case '2':
            p1 = ofVec2f(40,0);
            col = ofColor(255,0,100);
            pm.emit(col, p1, vel);
            break;
		
        case '3':
            p1 = ofVec2f(80,0);
            col = ofColor(255,0,100);
            pm.emit(col, p1, vel);
            break;
            
            
        case '4':
            p1 = ofVec2f(120,0);
            col = ofColor(255,0,100);
            pm.emit(col, p1, vel);
            break;
	}
    

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
    

}

//--------------------------------------------------------------
void testApp::mouseReleased() {
}
