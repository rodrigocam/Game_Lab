#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "sprite.hpp"
#include "player.hpp"

class GameScene: public Scene{
public:
    GameScene(int id);
    ~GameScene();

    void load();
    void draw();
    void update(double timeElapsed);

private:
    Player* player;
    Sprite* background;
};

#endif
