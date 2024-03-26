#include "ship.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "chicken.h"

Ship::Ship() {

    setPixmap(QPixmap(":/img/ship.png"));
}

void Ship::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Ship ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the Ship from getting out of the screen
            setPos(x()-10,y());

    }

    else if(event->key()== Qt::Key_Right)
    {
        if(x()+100<800) // to prevent the Ship from getting out of the screen
            setPos(x()+10,y());
    }

    else if(event->key() == Qt::Key_Up){
        if(y() > 0)
            setPos(x(), y() - 10);
    }

    else if(event->key() == Qt::Key_Down){
        if(y() + 100 < 600)
            setPos(x(), y() + 10);
    }

    else if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);
    }

    else if(event->key() == Qt::Key_2){
        Bullet * bullet1 = new Bullet();
        Bullet * bullet2 = new Bullet();
        bullet1->setPos(x()+10, y());
        bullet2->setPos(x()+40, y());
        scene()->addItem(bullet1);
        scene()->addItem(bullet2);
    }

    else if(event->key() == Qt::Key_3){
        Bullet * bullet1 = new Bullet();
        Bullet * bullet2 = new Bullet();
        Bullet * bullet3 = new Bullet();
        bullet1->setPos(x()+10, y());
        bullet2->setPos(x()+25, y());
        bullet3->setPos(x()+40, y());
        scene()->addItem(bullet1);
        scene()->addItem(bullet2);
        scene()->addItem(bullet3);
    }


}
 // CreateChicken   function used to create the eneimes
void Ship::createChicken()
{ Chicken* chicken = new Chicken();
  scene()->addItem(chicken);

}
