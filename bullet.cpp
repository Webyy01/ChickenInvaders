#include "chicken.h"
#include "stats.h"
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "stats.h"
#include "spawn.h"

Bullet::Bullet(): QObject(), QGraphicsPixmapItem()
{
    this->setPixmap(QPixmap(":/img/red_laser.png").scaled(40,40));

    /*
    audioOutput = new QAudioOutput();
    soundEffect = new QMediaPlayer();
    soundEffect->setSource(QUrl("qrc:/sounds/sounds/blaster-2-81267.mp3"));
    soundEffect->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
    soundEffect->play();
    */

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet :: move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i = 0; i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Chicken)){
            Stats::increase();

            int score = Stats::getScore();
            if(score > 0 && score%10 == 0){
                Spawn::increaseDifficulty();
            }
            //soundEffect->setSource(QUrl("qrc:/sounds/sounds/kill.mp3"));
            //soundEffect->play();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }



    setPos(x(),y()-10);
    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
