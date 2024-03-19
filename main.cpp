
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********
    QGraphicsView* view = new QGraphicsView();
    view->setFixedSize(800,600);

    // ******* Create the Scene ********
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // *******  Create the Player ********
    Player* player = new Player();
    player->setRect(0,0,50,70);
    scene->addItem(player);

    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********
    player->setPos(view->width()/2, 630);

   // *******   Assign scene to the view   ***************
    view->setScene(scene);
    view->show();

    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);


    return a.exec();
}
