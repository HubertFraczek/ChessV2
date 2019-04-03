//
// Created by sunil on 3/28/19.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H


#include <SFML/Window/Event.hpp>
#include "../../pieces/headers/Piece.h"
#include "../../pieces/headers/FreeSpace.h"

class Board {
private:
    Piece* board[8][8];
    Piece* freeSpace = new FreeSpace();
    int SPRITE_SIZE;
    bool whitesMove;
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
    ~Board();
    void mouseEvents(sf::Event *event, bool &mouseButtonReleased, sf::Vector2i mousePos);
    void update(sf::Vector2i mousePos, bool &mouseButtonReleased);
    Piece* getElement(int x, int y);
    void printDebug();
    void swap(int oldBoardX, int oldBoardY, int newBoardX, int newBoardY);
    bool isLegal(sf::Vector2i mousePos, int x, int y);
    bool isLegalRook(sf::Vector2i mousePos, int x, int y);
    bool isLegalKnight(sf::Vector2i mousePos, int x, int y);
    bool isLegalBishop(sf::Vector2i mousePos, int x, int y);
    bool isLegalQueen(sf::Vector2i mousePos, int x, int y);
    bool isLegalKing(sf::Vector2i mousePos, int x, int y);
    bool isLegalPawn(sf::Vector2i mousePos, int x, int y);
    bool isAttacked(int color, int x, int y);
    std::pair<int, int> findKing(int color);
    bool isRevealingCheck(sf::Vector2i mousePos, int x, int y);
};


#endif //CHESS_BOARD_H
