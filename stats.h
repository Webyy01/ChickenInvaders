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
    static QGraphicsTextItem* difficultyText;

public:
    static int difficulty;

    Stats();
    static void increase();
    static void decrease();
    static void setHealthText(QGraphicsTextItem* hlthText);
    static void setScoreText(QGraphicsTextItem* scrText);
    static void setDifficultyText(QGraphicsTextItem* diffText);
    static void updateDifficultyText();

    static int getScore(){return score;}
    static int getHealth(){return health;}

};

#endif // STATS_H
