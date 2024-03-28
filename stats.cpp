#include "stats.h"
#include <QMessageBox>
#include "spawn.h"
#include <QString>
#include <QGraphicsScene>
#include <QFont>

int Stats::health = 3;
int Stats::score = 0;
int Stats::difficulty = 1;
QGraphicsTextItem* Stats::healthText = nullptr;
QGraphicsTextItem* Stats::scoreText = nullptr;
QGraphicsTextItem* Stats::difficultyText = nullptr;

void Stats::setHealthText(QGraphicsTextItem* hlthText) {
    healthText = hlthText;
    healthText->setFont(QFont("script", 22));
    healthText->setDefaultTextColor(Qt::white);
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(10,20);    
}

void Stats::setScoreText(QGraphicsTextItem* scrText){
    scoreText = scrText;
    scoreText->setFont(QFont("script", 22));
    scoreText->setDefaultTextColor(Qt::cyan);
    scoreText->setPlainText("Score: " + QString::number(score));
    scoreText->setPos(10,60);
}

void Stats::setDifficultyText(QGraphicsTextItem* diffText){
    difficultyText = diffText;
    difficultyText->setFont(QFont("script", 22));
    difficultyText->setDefaultTextColor(Qt::white);
    difficultyText->setPlainText("Difficulty: " + QString::number(difficulty));
    difficultyText->setPos(10,100);
}

void Stats::updateDifficultyText(){
    difficultyText->setPlainText("Difficulty: " + QString::number(difficulty));
}

void Stats::increase(){
    score+=difficulty;
    scoreText->setPlainText("Score: " + QString::number(score));
}

void Stats::decrease(){
    if(health > 0){
        health--;
        score--;
    }

    healthText->setPlainText("Health: " + QString::number(health));
    scoreText->setPlainText("Score: " + QString::number(score));
    QGraphicsScene* s = healthText->scene();

    if(health==0){
        s->clear();
        Spawn::stopSpawning();

        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle(QString("GAME OVER!"));
        msg->setMinimumWidth(500);
        msg->setMinimumHeight(600);
        msg->setText(QString("Game Over. Your score was ") + QString::number(score));
        msg->exec();
    }
}



