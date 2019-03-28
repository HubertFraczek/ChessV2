//
// Created by sunil on 3/28/19.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H


#include <SFML/Window/Event.hpp>
#include "../../pieces/headers/Piece.h"

class Board {
private:
    Piece* board[8][8];
    int SPRITE_SIZE;
    sf::Texture tWhitePawn;
    sf::Texture tBlackPawn;
    sf::Texture tWhiteRook;
    sf::Texture tBlackRook;
    sf::Texture tWhiteKnight;
    sf::Texture tBlackKnight;
    sf::Texture tWhiteBishop;
    sf::Texture tBlackBishop;
    sf::Texture tWhiteQueen;
    sf::Texture tBlackQueen;
    sf::Texture tWhiteKing;
    sf::Texture tBlackKing;
public:
    Board(int SPRITE_SIZE);
    void mouseEvents(sf::Event *event, bool &mouseButtonReleased, sf::Vector2i mousePos);
    void update(sf::Vector2i mousePos, bool &mouseButtonReleased);
    Piece* getElement(int x, int y);
    void printDebug();
};


#endif //CHESS_BOARD_H
