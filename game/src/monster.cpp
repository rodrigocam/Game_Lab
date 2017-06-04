#include "monster.hpp"
#include "input_manager.hpp"

Monster::Monster(std::string objectName, double positionX, double positionY,
                                     int width, int height, std::string initialDirection) : GameObject(objectName,
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
    direction = initialDirection;
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
    if(direction == "right"){
        incX = incX * (1);
        idleAnimationNumber = 5;
        animator->setInterval(direction);
    }else if(direction == "left"){
        incX = incX * (-1);
        idleAnimationNumber = 0;
        animator->setInterval(direction);
    }else {
        incX = 0;
    }
    setPositionX(getPositionX()+incX);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        if(direction == "left"){
          direction = "right";
        }else{
          direction = "left";
        }
        setPositionX(getPositionX()+(incX*(0-1)));
    }
}

void Monster::walkInY(double & incY, double incX){
    if(direction == "down"){
        incY = incY * (1);
        idleAnimationNumber = 5;
        animator->setInterval(direction);
    }else if(direction == "up"){
        incY = incY * (-1);
        idleAnimationNumber = 0;
        animator->setInterval(direction);
    }else {
        incY = 0;
    }
    setPositionY(getPositionY()+incY);
    if(CollisionManager::instance.verifyCollisionWithWalls(this)){
        if(direction == "down"){
          direction = "up";
        }else{
          direction = "down";
        }
        setPositionY(getPositionY()+(incY*(0-1)));
    }
}
