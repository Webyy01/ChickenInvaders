#ifndef STATS_H
#define STATS_H
#include <QGraphicsTextItem>

class Stats
{
private:
    static int score;
    static int health;
    static QGraphicsTextItem* healthText;
    static QGraphicsTextItem* scoreText;

public:
    Stats();
    static void increase();
    static void decrease();
    static void setHealthText(QGraphicsTextItem* healthText);
    static void setScoreText(QGraphicsTextItem* scoreText);

    static int getScore(){return score;}
    static int getHealth(){return health;}
};

#endif // STATS_H
