//
// Created by sunil on 3/27/19.
//

#include "../headers/King.h"

King::King(sf::Sprite *sprite, int id, int x, int y) {
    this->sprite = sprite;
    this->id = id;
    sprite->setPosition(x, y);
    if (id < 0) this->color = -1;
    else this->color = 1;
}