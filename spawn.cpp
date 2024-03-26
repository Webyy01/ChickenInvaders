
#include "spawn.h"
#include "chicken.h"
#include <QTimer>
#include <QGraphicsScene>

QTimer* Spawn::timer = new QTimer();
int Spawn::currentTime = 1300;

Spawn::Spawn(QGraphicsScene * scene) {

    this->scene = scene;
    connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    timer->start(currentTime);
}

void Spawn::stopSpawning() {
    timer->stop();
}

void Spawn::spawn(){
    Chicken * chicken= new Chicken();
    scene->addItem(chicken);
}

void Spawn::increaseDifficulty(){
    Spawn::currentTime-=100;
    timer->start(currentTime);
}

