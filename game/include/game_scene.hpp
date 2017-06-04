#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "engine.hpp"
#include "scene.hpp"
#include "sprite.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "wall.hpp"
#include <typeinfo>

class GameScene: public Scene{
public:
    GameScene(int id);
    ~GameScene();

    void load();
    void unload();
    void draw();
    void update(double timeElapsed);

private:
    std::vector<GameObject*> gameObjectsList;
    Player* player;
    Monster* monster;
    Wall* wall;
    Sprite* background;
};

#endif
