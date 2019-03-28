//
// Created by sunil on 3/27/19.
//

#include "../headers/Rook.h"

Rook::Rook(sf::Sprite *sprite, int id, int x, int y) {
    this->sprite = sprite;
    this->id = id;
    sprite->setPosition(x, y);
}