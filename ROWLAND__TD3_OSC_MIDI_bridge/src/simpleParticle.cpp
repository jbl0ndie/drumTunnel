//
//  simpleParticle.cpp
//  
//
//  Created by Adam Heslop on 23/12/2014.
//
//

#include "simpleParticle.h"

simpleParticle::simpleParticle(){
    
    reset();
}

void simpleParticle::reset(){
    
    active      = false;
    colour      = ofColor(0);
    position    = ofVec2f(-1,-1);
    age         = 0;
    velocity    = ofVec2f(0,1);
}