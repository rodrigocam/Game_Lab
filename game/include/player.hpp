#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "input_manager.hpp"
#include "animation.hpp"
#include "engine.hpp"
#include "collision_manager.hpp"

using namespace engine;

class Player: public GameObject{
public:
    Player(std::string objectName, double positionX, double positionY,
                                         int width, int height);
    ~Player();
    void update(double timeElapsed);
    void draw();

private:
    Animation* animator;
    int idleAnimationNumber;
    void walkInX(double & incX);
    void walkInY(double & incY, double incX);
};

#endif
