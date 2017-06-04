#include "player.hpp"

Player::Player(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 4, 9, 0.8);
    animator->addAction("right",27,35);
    animator->addAction("left",9,17);
    animator->addAction("up",0,8);
    animator->addAction("down",18, 26);
    animator->addAction("idle_right",27,27);
    animator->addAction("idle_left",9,9);
    animator->addAction("idle_up",0,0);
    animator->addAction("idle_down",18,18);
    idleAnimationNumber = 18;
}

Player::~Player(){}

void Player::update(double timeElapsed){
    auto incY = 0.15*timeElapsed;
    auto incX = 0.15*timeElapsed;

    walkInX(incX);
    walkInY(incY, incX);

    if(incX == 0 && incY == 0){
        if(idleAnimationNumber == 27){
          animator->setInterval("idle_right");
        }else{
          animator->setInterval("idle_left");
        }
    }
    if(CollisionManager::instance.verifyCollisionWithMonsters(this)){
        WARN("Colidiu");
    }

    animator->update();
}

void Player::draw(){
    INFO("PLAYER DRAW");
    animator->draw(getPositionX(), getPositionY());
}

void Player::walkInX(double & incX){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        incX = incX;
        idleAnimationNumber = 27;
        animator->setInterval("right");
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        incX = incX * (0-1);
        idleAnimationNumber = 9;
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

void Player::walkInY(double & incY, double incX){

    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        incY = incY * (0-1);
        idleAnimationNumber = 0;
        if(incX == 0){
            animator->setInterval("up");
        }
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        incY = incY;
        idleAnimationNumber = 18;
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
