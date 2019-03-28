//
// Created by sunil on 3/27/19.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(sf::Sprite *sprite, int id, int x, int y);
};


#endif //CHESS_PAWN_H
