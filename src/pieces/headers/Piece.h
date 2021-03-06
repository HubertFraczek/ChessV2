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
    bool isMove;
    bool isBeingModified;
    int color;
    bool hasMovedBy2;
    bool hasMoved;
public:
    Piece();
    virtual sf::Sprite getSprite();
    virtual void setSprite(sf::Sprite *sprite);
    virtual int getId() const;
    virtual void setId(int id);
    virtual bool isIsMove();
    virtual void setIsMove(bool isMove);
    virtual void setSpritePos(int x, int y);
    virtual bool getIsBeingModified();
    virtual void setIsBeingModified(bool isBeingModified);
    virtual int getColor();
    virtual void setColor(int color);
    virtual bool isHasMovedBy2();
    virtual void setHasMovedBy2(bool hasMovedBy2);
    virtual bool isHasMoved();
    virtual void setHasMoved(bool hasMoved);

};


#endif //CHESS_PIECE_H
