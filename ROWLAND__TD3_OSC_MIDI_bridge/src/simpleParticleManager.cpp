//
//  simpleParticleManager.cpp
//  
//
//  Created by Adam Heslop on 23/12/2014.
//
//

#include "simpleParticleManager.h"

//INIT ---------------------------------------------------------------------------------------------
simpleParticleManager::simpleParticleManager(){
 
    count = 1000;
    life  = 500;
    
    for (int i = 0; i<count; i++) {
        particles.push_back(simpleParticle());
    }
    
}

// UPDATE -----------------------------------------------------------------------------------------

void simpleParticleManager::update(){

    
    inactive.clear();
    for (int i=0; i<particles.size(); i++) {
        simpleParticle* p = &particles[i];
        if (p->active == true) {
            p->position += p->velocity;
            p->age +=1;
            //xcout << "AGE : " << p->age << endl;
        }
        
        else{
            inactive.push_back(p);
        }

        if (p->age >= life) {
            p->active = false;
            p->reset();

        }

    }
    //cout << "Size of inactive : " << inactive.size() << endl;
}


void simpleParticleManager::emit(ofColor pColour, ofVec2f pPosition, ofVec2f pVelocity){

    if (inactive.size() > 0) {
        int last = inactive.size()-1;
        inactive[last]->active   = true;
        inactive[last]->colour   = pColour;
        inactive[last]->position = pPosition;
        inactive[last]->velocity = pVelocity;
        inactive.pop_back();

    }
}

//GETTERS AND SETTERS -----------------------------------------------------------------------------

void simpleParticleManager::setCount(int pCnt){
    
    if (pCnt != count){
        particles.resize(pCnt);
        count = pCnt;
    }
}

void simpleParticleManager::setLife(int pLife){
    
    if (pLife != life){
        life = pLife;
    }
}

void simpleParticleManager::setActive(int p, bool pActive){
    particles[p].active = pActive;
}

void simpleParticleManager::setColour(int p, ofColor pCol){
    particles[p].colour = pCol;
}

void simpleParticleManager::setPosition(int p, ofVec2f pPos){
    particles[p].position = pPos;
}

void simpleParticleManager::setVelocity(int p, ofVec2f pVel){
    particles[p].velocity = pVel;
}

int simpleParticleManager::getCount(){
    return count;
}

int simpleParticleManager::getLife(){
    return life;
}

bool simpleParticleManager::getActive(int p){
    return particles[p].active;
}

ofColor simpleParticleManager::getColour(int p){
    return particles[p].colour;
}

ofVec2f simpleParticleManager::getPosition(int p){
    return particles[p].position;
}

ofVec2f simpleParticleManager::getVelocity(int p){
    return particles[p].velocity;
}
