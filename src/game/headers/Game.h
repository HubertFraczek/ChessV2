//
// Created by sunil on 3/27/19.
//

#ifndef CHESSV2_GAME_H
#define CHESSV2_GAME_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include "../../pieces/headers/Piece.h"

class Game {
private:
    int const WIDTH = 800;
    int const HEIGHT = 800;
    int const FPS = 30;
    int const SPRITE_SIZE = 100;
    bool mouseButtonReleased = false;
    int dx; int dy;
public:
    void run();
    void mouseEvents(sf::Event *event, Piece *board[][8], bool &mouseButtonReleased, sf::Vector2i mousePos);
    void update(Piece *board[][8], sf::Vector2i mousePos, bool &mouseButtonReleased);

};


#endif //CHESSV2_GAME_H
