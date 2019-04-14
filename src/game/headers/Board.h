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
    int moveNumber = 0;
    int toBePromotedX;
    int toBePromotedY;
    bool whitesMove;
    bool pvp = true;
    bool promote = false;
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
    sf::Texture tPromotionScreen;
    sf::Sprite *sPromotion;
    sf::Sprite *sWhiteQueen;
    sf::Sprite *sWhiteRook;
    sf::Sprite *sWhiteBishop;
    sf::Sprite *sWhiteKnight;
    sf::Sprite *sBlackQueen;
    sf::Sprite *sBlackRook;
    sf::Sprite *sBlackBishop;
    sf::Sprite *sBlackKnight;
public:
    Board(int SPRITE_SIZE, int WIDTH, int HEIGHT);
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
    void turnOffHasMovedBy2(int color);
    bool anyLegalMove(int x, int y);
    bool anyLegalMoveRook(int x, int y);
    bool anyLegalMoveKnight(int x, int y);
    bool anyLegalMoveBishop(int x, int y);
    bool anyLegalMoveQueen(int x, int y);
    bool anyLegalMoveKing(int x, int y);
    bool anyLegalMovePawn(int x, int y);
    bool isGameOver();
    void flipBoardVertically();
    void flipBoardHorizontally();
    void promotion(sf::Event *event, sf::Vector2i mousePos);
    bool isPromote();
    void setPromote(bool promote);
    sf::Sprite getSPromotion();
    void setSPromotion(sf::Sprite *sPromotion);
    bool isWhitesMove();
    void setWhitesMove(bool whitesMove);
    sf::Sprite getSWhiteQueen();
    sf::Sprite getSWhiteRook();
    sf::Sprite getSWhiteBishop();
    sf::Sprite getSWhiteKnight();
    sf::Sprite getSBlackQueen();
    sf::Sprite getSBlackRook();
    sf::Sprite getSBlackBishop();
    sf::Sprite getSBlackKnight();
};


#endif //CHESS_BOARD_H
