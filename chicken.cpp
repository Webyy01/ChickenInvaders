#include "chicken.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "stats.h"
#include "ship.h"



Chicken::Chicken() : QObject(), QGraphicsPixmapItem()
{
    this->setPixmap(QPixmap(":/img/CI4_SuperChick.png").scaled(100,100));

    int random = rand() % 700;
    setPos(random,0);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Chicken::move(){
    setPos(x(), y() + 5);

    // When chicken reaches the bottom, delete it and decrease health
    if (pos().y() + pixmap().height() > scene()->height()){
        Stats::decrease();
        scene()->removeItem(this);
        delete this;
        return;
    }


    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Ship)){
            scene()->removeItem(this);

            Stats::decrease();

            delete this;
            return;
        }
    }
}
