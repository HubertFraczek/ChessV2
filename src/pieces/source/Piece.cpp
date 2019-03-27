//
// Created by sunil on 3/27/19.
//

#include "../headers/Piece.h"

Piece::Piece(sf::Sprite *sprite, int id) {
    this->sprite = sprite;
    this->id = id;
}

sf::Sprite *Piece::getSprite() const {
    return sprite;
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
