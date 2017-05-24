#ifndef MOSNTER_HPP
#define MONSTER_HPP

#include "animation.hpp"
#include "engine.hpp"
#include "input_manager.hpp"

using namespace engine;

class Monster: public GameObject{
public:
    Monster(std::string objectName, double positionX, double positionY,
                                         int width, int height);
    ~Monster();
    void update(double timeElapsed);
    void draw();

private:
    Animation* animator;
};


#endif
