//
// Created by sunil on 3/27/19.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Piece.h"

class King : public Piece {
public:
    King(sf::Sprite *sprite, int id, int x, int y);
};


#endif //CHESS_KING_H
