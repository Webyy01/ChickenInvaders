
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "ship.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "stats.h"
#include "spawn.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create scene
    QGraphicsScene * scene = new QGraphicsScene();

    // Add ship tp the scene
    QGraphicsPixmapItem * player = new Ship();


    // Add player to scene
    scene-> addItem(player);

    // Remove scroll bars
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // Make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    QPixmap bgImage(":/img/spaceBackground.png");
    scene->setBackgroundBrush(bgImage.scaled(scene->width(),scene->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    // Set pos of player
    player->setPos(view->width()/2,view->height() - player->pixmap().height());

    QGraphicsTextItem* scoreText = new QGraphicsTextItem();
    QGraphicsTextItem* healthText = new QGraphicsTextItem();
    QGraphicsTextItem* diffText = new QGraphicsTextItem();

    scene->addItem(scoreText);
    scene->addItem(healthText);
    scene->addItem(diffText);

    Stats::setHealthText(healthText);
    Stats::setScoreText(scoreText);
    Stats::setDifficultyText(diffText);

    // Spawn
    Spawn spawn(scene);

    return a.exec();
}
