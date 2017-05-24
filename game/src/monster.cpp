#include "monster.hpp"
#include "input_manager.hpp"

Monster::Monster(std::string objectName, double positionX, double positionY,
                                     int width, int height) : GameObject(objectName,
                                                                         positionX,
                                                                         positionY,
                                                                         width, height){

    animator = new Animation(objectName, 4, 4, 0.8);
}

Monster::~Monster(){}

void Monster::update(double timeElapsed){
    if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_RIGHT)){
        auto inc = 0.15*timeElapsed;
        setPositionX(getPositionX()+inc);
        animator->setInterval(8, 11);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_LEFT)){
        auto inc = 0.15*timeElapsed;
        setPositionX(getPositionX()-inc);
        animator->setInterval(4, 7);
    }
    else if(InputManager::instance.isKeyPressed(InputManager::KeyPress::KEY_PRESS_UP)){
        auto inc = 0.15*timeElapsed;
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        setPositionY(getPositionY()-inc);
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        animator->setInterval(12, 15);
    }
    else if(engine::InputManager::instance.isKeyPressed(engine::InputManager::KeyPress::KEY_PRESS_DOWN)){
        auto inc = 0.15*timeElapsed;
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        setPositionY(getPositionY()+inc);
        WARN("INCREMENTO//:" << inc <<"POSITION" << getPositionY());
        animator->setInterval(0, 3);
    }
    else {
        animator->setInterval(animator->getInterval().first, animator->getInterval().first);
    }

    animator->update();
}

void Monster::draw(){
    INFO("MONSTER DRAW");
    animator->draw(getPositionX(), getPositionY());
}
