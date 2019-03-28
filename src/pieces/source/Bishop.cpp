//
// Created by sunil on 3/27/19.
//

#include "../headers/Bishop.h"

Bishop::Bishop(sf::Sprite *sprite, int id, int x, int y) {
    this->sprite = sprite;
    this->id = id;
    sprite->setPosition(x, y);
}