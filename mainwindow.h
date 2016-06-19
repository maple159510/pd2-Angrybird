#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include <QGraphicsPixmapItem>
#include <QImage>
#include <QBrush>
#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QFont>

#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <blocker.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    void repeat();
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    Bird *birdie;
    Bird *birdie2;
    Bird *birdie3;
    Bird *birdie4;
    Bird *birdie_2;
    Bird *birdie2_2;
    Bird *birdie3_2;
    Bird *birdie4_2;
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void close();
    void restart();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QTimer timer;
    int i=0;

};

#endif // MAINWINDOW_H
