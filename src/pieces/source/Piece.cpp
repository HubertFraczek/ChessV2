//
// Created by sunil on 3/27/19.
//

#include "../headers/Piece.h"

Piece::Piece() {
    this->isMove = false;
    this->isBeingModified = false;
}

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

bool Piece::isIsMove() {
    return isMove;
}

void Piece::setIsMove(bool isMove) {
    Piece::isMove = isMove;
}

void Piece::setSpritePos(int x, int y) {
    this->sprite->setPosition(x, y);
}

bool Piece::getIsBeingModified() {
    return isBeingModified;
}

void Piece::setIsBeingModified(bool isBeingModified) {
    Piece::isBeingModified = isBeingModified;
}

int Piece::getColor() {
    return color;
}

void Piece::setColor(int color) {
    Piece::color = color;
}
