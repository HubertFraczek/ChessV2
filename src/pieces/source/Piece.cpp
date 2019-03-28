//
// Created by sunil on 3/27/19.
//

#include "../headers/Piece.h"

Piece::Piece() {}

sf::Sprite Piece::getSprite() {
    return *this->sprite;
}

void Piece::setSprite(sf::Sprite *sprite) {
    Piece::sprite = sprite;
}

int Piece::getId() const {
    return id;
}

void Piece::setId(int id) {
    Piece::id = id;
}
