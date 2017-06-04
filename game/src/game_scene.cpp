#include "game_scene.hpp"

GameScene::GameScene(int id) : Scene(id){

}

GameScene::~GameScene(){}

void GameScene::draw(){
    //background->init();
    background->draw(0, 0);
    //monster->draw();
    //player->draw();
    for(auto gameObject : gameObjectsList) {
        (*gameObject).draw();
    }
}

void GameScene::update(double timeElapsed){
    //player->update(timeElapsed);
    //monster->update(timeElapsed);
    for(auto gameObject : gameObjectsList) {
        (*gameObject).update(timeElapsed);
    }
}

void GameScene::load(){
    player = new Player("assets/player.png", 100, 0, 36, 36);
    monster = new Monster("assets/minotaur.png", 200, 250, 80, 80, "left");
    background = new Sprite("assets/maze_floor.jpg", 960, 600);
    wall = new Wall("assets/wall1.png", 200, 0, 35, 55);
    //wall2 = new Wall("assets/wall1.png", 200, 0, 73, 41);

    gameObjectsList.push_back(player);
    gameObjectsList.push_back(monster);

    gameObjectsList.push_back(new Wall("assets/invisible_wall.png", 0, -1, 960, 1));
    gameObjectsList.push_back(new Wall("assets/invisible_wall.png", 0, 570, 960, 1));

    gameObjectsList.push_back(new Wall("assets/invisible_wall2.png", -1, 0, 1, 600));
    gameObjectsList.push_back(new Wall("assets/invisible_wall2.png", 960, 0, 1, 600));


    gameObjectsList.push_back(new Wall("assets/wall2.png", -32, 350, 53, 26));
    gameObjectsList.push_back(new Wall("assets/wall2.png", 0, 350, 53, 26));
    gameObjectsList.push_back(new Wall("assets/wall2.png", 32, 350, 53, 26));

    for(int i=960; i>=704; i-=32){
        gameObjectsList.push_back(new Wall("assets/wall2.png", i, 450, 53, 26));
    }

    gameObjectsList.push_back(new Wall("assets/wall2.png", 960, 250, 53, 26));
    gameObjectsList.push_back(new Wall("assets/wall2.png", 928, 250, 53, 26));
    gameObjectsList.push_back(new Wall("assets/wall2.png", 896, 250, 53, 26));
    gameObjectsList.push_back(new Wall("assets/wall2.png", 864, 250, 53, 26));

    gameObjectsList.push_back(new Wall("assets/wall1.png", 860, 250, 35, 55));
    gameObjectsList.push_back(new Wall("assets/wall1.png", 860, 285, 35, 55));

    gameObjectsList.push_back(new Wall("assets/wall1.png", 480, -35, 35, 55));
    gameObjectsList.push_back(new Wall("assets/wall1.png", 480, 0, 35, 55));
    gameObjectsList.push_back(new Wall("assets/wall1.png", 480, 35, 35, 55));

    for(int i=-35; i<=140; i+=35){
        gameObjectsList.push_back(new Wall("assets/wall1.png", 300, i, 35, 55));
    }

    gameObjectsList.push_back(new Wall("assets/wall1.png", 100, 145, 35, 55));
    gameObjectsList.push_back(new Wall("assets/wall1.png", 100, 110, 35, 55));
    gameObjectsList.push_back(new Wall("assets/wall1.png", 100, 75, 35, 55));

    for(int i=272; i>=102; i-=32){
        gameObjectsList.push_back(new Wall("assets/wall2.png", i, 175, 53, 26));
    }

    gameObjectsList.push_back(new Wall("assets/wall2.png", 110, 75, 53, 26));
    gameObjectsList.push_back(new Wall("assets/wall2.png", 142, 75, 53, 26));
    gameObjectsList.push_back(new Wall("assets/wall2.png", 174, 75, 53, 26));

    for(auto gameObject: gameObjectsList){
        if(typeid(*gameObject) == typeid(Wall)){
            CollisionManager::instance.addWall(gameObject);
        }else if(typeid(*gameObject) == typeid(Player)){
            CollisionManager::instance.addPlayer(gameObject);
        }else if(typeid(*gameObject) == typeid(Monster)){
            CollisionManager::instance.addMonster(gameObject);
        }
    }
}

void GameScene::unload(){
    CollisionManager::instance.resetLists();
    gameObjectsList.clear();
}
