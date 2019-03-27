//
// Created by sunil on 3/27/19.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <SFML/Graphics/Sprite.hpp>

class Piece {
protected:
    sf::Sprite *sprite;
    int id;
public:
    Piece(sf::Sprite *sprite, int id);
    sf::Sprite *getSprite() const;
    void setSprite(sf::Sprite *sprite);
    int getId() const;
    void setId(int id);
};


#endif //CHESS_PIECE_H
