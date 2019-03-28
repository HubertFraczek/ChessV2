//
// Created by sunil on 3/27/19.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Piece.h"

class Queen : public Piece {
public:
    Queen(sf::Sprite *sprite, int id, int x, int y);
};


#endif //CHESS_QUEEN_H
