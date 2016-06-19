#ifndef BLOCKER_H
#define BLOCKER_H
#include <gameitem.h>
#include <QGraphicsScene>

class Blocker : public GameItem
{
public:
    Blocker(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BLOCKER_H
