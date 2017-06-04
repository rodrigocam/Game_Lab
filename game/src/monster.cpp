#include "monster.hpp"
#include "input_manager.hpp"

Monster::Monster(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 4, 4, 0.8);
    animator->addAction("right",8, 11);
    animator->addAction("left",4, 7);
    animator->addAction("up",12, 15);
    animator->addAction("down",0, 3);
    animator->addAction("idle_right",8,8);
    animator->addAction("idle_left",4,4);
    animator->addAction("idle_up",12,12);
    animator->addAction("idle_down",0,0);
    idleAnimationNumber = 0;
}

Monster::~Monster(){}

void Monster::update(double timeElapsed){
    auto incY = 0.15*timeElapsed;
    auto incX = 0.15*timeElapsed;

    walkInX(incX);
    walkInY(incY, incX);

    if(incX == 0 && incY == 0){
        if(idleAnimationNumber == 8){
          animator->setInterval("idle_right");
        }else{
          animator->setInterval("idle_left");
        }
    }

    animator->update();
}

void Monster::draw(){
    INFO("MONSTER DRAW");
    animator->draw(getPositionX(), getPositionY());
}

void Monster::walkInX(double & incX){
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        incX = incX;
        idleAnimationNumber = 8;
        animator->setInterval("right");
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        incX = incX * (0-1);
        idleAnimationNumber = 4;
        animator->setInterval("left");
    }
    else {
        incX = 0;
    }
    setPositionX(getPositionX()+incX);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        setPositionX(getPositionX()+(incX*(0-1)));
    }
}

void Monster::walkInY(double & incY, double incX){
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        incY = incY * (0-1);
        idleAnimationNumber = 12;
        if(incX == 0){
            animator->setInterval("up");
        }
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        incY = incY;
        idleAnimationNumber = 0;
        if(incX == 0){
            animator->setInterval("down");
        }
    }
    else {
        incY = 0;
    }
    setPositionY(getPositionY()+incY);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        setPositionY(getPositionY()+(incY*(0-1)));
    }
}
