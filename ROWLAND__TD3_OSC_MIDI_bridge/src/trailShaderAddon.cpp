//
//  trailShaderAddon.cpp
//  trailShaderAddon
//
//  Created by Adam Heslop on 24/12/2014.
//
//

#include "trailShaderAddon.h"

void trailShader::init(int w, int h){

    ping.allocate(w, h, GL_RGB);
    pong.allocate(w, h, GL_RGB);
    
    raster.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    
    trailShader.load("shaders/trailShader");
    
    ping.begin();
    ofClear(0);
    ping.end();
   
    pong.begin();
    ofClear(0);
    pong.end();
    
}

void trailShader::begin(){
    
    raster.begin();
    ofClear(0);
    raster.end();
    
    raster.begin();
    

}

void trailShader::end(float attack, float decay){
    
    
    raster.end();
    
    ping.begin();
    trailShader.begin();
    trailShader.setUniform1f("attack", attack);
    trailShader.setUniform1f("decay", decay);
    trailShader.setUniformTexture("lastTex", pong.getTextureReference(), 1);
    trailShader.setUniform1f("thrsh", thresh);
    
    
    raster.draw(0, 0);
    trailShader.end();
    ping.end();
    
}

void trailShader::draw(int px, int py, int w, int h){
    
    ping.draw(px, py, w, h);
    
    ofSetColor(255);
    
    pong.begin();
    ofClear(0);
    pong.end();
    
    pong.begin();
    ping.draw(0,0);
    pong.end();
    
    
    ping.begin();
    ofClear(0);
    ping.end();
    
}
