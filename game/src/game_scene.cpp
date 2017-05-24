#include "game_scene.hpp"

GameScene::GameScene(int id) : Scene(id){

}

GameScene::~GameScene(){}

void GameScene::draw(){
    //background->init();
    background->draw(0, 0);
    monster->draw();
    player->draw();
}

void GameScene::update(double timeElapsed){
    player->update(timeElapsed);
    monster->update(timeElapsed);
}

void GameScene::load(){
    player = new Player("assets/player.png", 100, 0, 36, 36);
    monster = new Monster("assets/minotaur.png", 200, 200, 80, 80);
    background = new Sprite("assets/maze_floor.jpg", 960, 600);
}
