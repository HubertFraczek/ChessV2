//
// Created by sunil on 3/27/19.
//

#ifndef CHESSV2_GAME_H
#define CHESSV2_GAME_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Game {
private:
    int const WIDTH = 800;
    int const HEIGHT = 800;
    int const FPS = 30;
    int const SPRITE_SIZE = 100;
public:
    void run();

};


#endif //CHESSV2_GAME_H
