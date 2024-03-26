#ifndef SPAWN_H
#define SPAWN_H
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Spawn: public QObject
{
    Q_OBJECT
public:
    Spawn(QGraphicsScene*);
    static void stopSpawning();
private:
    static int currentTime;
    static QTimer* timer;
    QGraphicsScene* scene;
public slots:
    static void increaseDifficulty();
    void spawn();
};

#endif // SPAWN_H
