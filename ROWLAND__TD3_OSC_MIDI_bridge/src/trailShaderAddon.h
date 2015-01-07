//
//  trailShaderAddon.h
//  trailShaderAddon
//
//  Created by Adam Heslop on 24/12/2014.
//
//

#ifndef __trailShaderAddon__trailShaderAddon__
#define __trailShaderAddon__trailShaderAddon__

#include <iostream>
#include "ofMain.h"

class trailShader{
    
public:
    
    void init(int w = ofGetWidth(), int h = ofGetHeight());
    
    void begin();
    
    void end(float attack, float decay);

    void draw(int px, int py, int w = ofGetWidth(), int h = ofGetHeight());
    
    float thresh = 0.2;
    
private:
    
    ofFbo ping;
    ofFbo pong;
    
    ofFbo raster;
    
    ofShader trailShader;
    

};

#endif /* defined(__trailShaderAddon__trailShaderAddon__) */
