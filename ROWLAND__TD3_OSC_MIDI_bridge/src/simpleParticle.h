//
//  simpleParticle.h
//  
//
//  Created by Adam Heslop on 23/12/2014.
//
//

#ifndef ____simpleParticle__
#define ____simpleParticle__

#include <stdio.h>
#include "ofMain.h"

class simpleParticle{
    
public:
    
    simpleParticle();
    void reset();
    
    bool    active;
    int     age;
    ofColor colour;
    ofVec2f position;
    ofVec2f velocity;


private:

    int life;	
};

#endif /* defined(____simpleParticle__) */
