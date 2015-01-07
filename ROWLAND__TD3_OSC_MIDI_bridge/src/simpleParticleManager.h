//
//  simpleParticleManager.h
//  
//
//  Created by Adam Heslop on 23/12/2014.
//
//

#ifndef ____simpleParticleManager__
#define ____simpleParticleManager__

#include <stdio.h>
#include "ofMain.h"
#include "simpleParticle.h"


class simpleParticleManager{
    
public:

    simpleParticleManager();
    
    void emit(ofColor pCol = ofColor(0), ofVec2f pPos = ofVec2f(-1,-1), ofVec2f pVelocity = ofVec2f(0,0));
    void update();
    void setCount(int pCnt);
    void setLife( int pLife);

    void setActive(int p, bool active);
    void setColour(int p, ofColor pCol);
    void setPosition(int p, ofVec2f pPos);
    void setVelocity(int p, ofVec2f pVel);
    
    int     getCount();
    int     getLife();
    bool    getActive(int p);
    ofVec2f getPosition(int p);
    ofColor getColour(int p);
    ofVec2f getVelocity(int p);
    
    
private:
    
    int count;
    int life;
    vector<simpleParticle> particles;
    vector<simpleParticle*> inactive;

};



#endif /* defined(____simpleParticleManager__) */
