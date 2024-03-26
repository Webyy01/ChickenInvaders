#ifndef CHICKEN_H
#define CHICKEN_H
#include <QGraphicsRectItem>
#include <QObject>

class Chicken: public QObject , public QGraphicsPixmapItem
{ Q_OBJECT

public:
    Chicken();

public slots:
    void move();
};

#endif // CHICKEN_H
