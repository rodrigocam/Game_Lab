#ifndef MOSNTER_HPP
#define MONSTER_HPP

#include "animation.hpp"
#include "engine.hpp"
#include "input_manager.hpp"
#include "collision_manager.hpp"

using namespace engine;

class Monster: public GameObject{
public:
    Monster(std::string objectName, double positionX, double positionY,
                                         int width, int height, std::string initialDirection);
    ~Monster();
    void update(double timeElapsed);
    void draw();

private:
    Animation* animator;
    int idleAnimationNumber;
    void walkInX(double & incX);
    void walkInY(double & incY, double incX);
    std::string direction;
};


#endif
