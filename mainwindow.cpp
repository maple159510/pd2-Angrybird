#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background.png")));
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    /*QPixmap Bg(":/background.png");
    Bg= Bg.scaled(800,600);

    QPalette p(palette());
    p.setBrush(QPalette::Background,Bg);
    setAutoFillBackground(true);
    setPalette(p);*/

    //create the scene
    //scene = new QGraphicsScene();
    //scene->setSceneRect(0,0,32,18);//make the scene 1000x640 instead of infinity by infinity
    //setBackgroundBrush(QBrush(QImage(":/background.png")));
    //setScene(scene);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // setFixedSize(32,18);

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    // Create bird (You can edit here)
    birdie = new Bird(1.5f,6.0f,0.35f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie2 = new Bird(3.0f,6.0f,0.35f,&timer,QPixmap(":/bird2.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie3 = new Bird(4.5f,6.0f,0.35f,&timer,QPixmap(":/bird3.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie4 = new Bird(6.0f,6.0f,0.35f,&timer,QPixmap(":/bird4.png").scaled(height()/9.0,height()/9.0),world,scene);

    Bird *enemy1 = new Bird(18.0f,6.0f,0.4f,&timer,QPixmap(":/enemy1.png").scaled(height()/8.0,height()/8.0),world,scene);
    Bird *enemy2 = new Bird(20.0f,6.0f,0.27f,&timer,QPixmap(":/blocker9.png").scaled(height()/10.0,height()/10.0),world,scene);
    Bird *enemy3 = new Bird(12.0f,6.0f,0.8f,&timer,QPixmap(":/enemy3.png").scaled(height()/6.0,height()/6.0),world,scene);
    Bird *enemy4 = new Bird(24.0f,2.0f,0.3f,&timer,QPixmap(":/enemy4.png").scaled(height()/9.0,height()/9.0),world,scene);
    Bird *enemy5 = new Bird(24.0f,5.0f,0.5f,&timer,QPixmap(":/enemy5.png").scaled(height()/12.0,height()/12.0),world,scene);
    Bird *enemy6 = new Bird(24.0f,7.0f,0.5f,&timer,QPixmap(":/enemy6.png").scaled(height()/12.0,height()/12.0),world,scene);
    Bird *blocker4 = new Bird(28.0f,2.0f,0.7f,&timer,QPixmap(":/blocker4.png").scaled(height()/5.0,height()/6.0),world,scene);
    Bird *blocker6 = new Bird(22.0f,6.0f,0.27f,&timer,QPixmap(":/blocker6.png").scaled(height()/10.0,height()/10.0),world,scene);
    Bird *blocker8 = new Bird(22.0f,6.0f,0.4f,&timer,QPixmap(":/blocker8.png").scaled(height()/12.0,height()/12.0),world,scene);
    itemList.push_back(enemy1);
    itemList.push_back(enemy2);
    itemList.push_back(enemy3);
    itemList.push_back(enemy4);
    itemList.push_back(enemy5);
    itemList.push_back(enemy6);
    itemList.push_back(blocker4);
    itemList.push_back(blocker6);
    itemList.push_back(blocker8);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

    QIcon *button = new QIcon(QPixmap(":/exit.png"));
    QPushButton *exit = new QPushButton(*button,"");
    exit->setIconSize(QSize(60,60));
    exit->setGeometry(700,30,80,80);
    scene->addWidget(exit);
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));

    QIcon *button2 = new QIcon(QPixmap(":/restart.png"));
    QPushButton *start = new QPushButton(*button2,"");
    start->setIconSize(QSize(60,60));
    start->setGeometry(400,30,80,80);
    scene->addWidget(start);
    connect(start,SIGNAL(clicked()),this,SLOT(restart()));

}

void MainWindow::repeat(){
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/background.png")));
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    /*QPixmap Bg(":/background.png");
    Bg= Bg.scaled(800,600);

    QPalette p(palette());
    p.setBrush(QPalette::Background,Bg);
    setAutoFillBackground(true);
    setPalette(p);*/

    //create the scene
    //scene = new QGraphicsScene();
    //scene->setSceneRect(0,0,32,18);//make the scene 1000x640 instead of infinity by infinity
    //setBackgroundBrush(QBrush(QImage(":/background.png")));
    //setScene(scene);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   // setFixedSize(32,18);

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/ground.png").scaled(width(),height()/6.0),world,scene));

    // Create bird (You can edit here)
    birdie = new Bird(1.5f,6.0f,0.35f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie2 = new Bird(3.0f,6.0f,0.35f,&timer,QPixmap(":/bird2.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie3 = new Bird(4.5f,6.0f,0.35f,&timer,QPixmap(":/bird3.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie4 = new Bird(6.0f,6.0f,0.35f,&timer,QPixmap(":/bird4.png").scaled(height()/9.0,height()/9.0),world,scene);

    Bird *enemy1 = new Bird(18.0f,6.0f,0.4f,&timer,QPixmap(":/enemy1.png").scaled(height()/8.0,height()/8.0),world,scene);
    Bird *enemy2 = new Bird(20.0f,6.0f,0.27f,&timer,QPixmap(":/blocker9.png").scaled(height()/10.0,height()/10.0),world,scene);
    Bird *enemy3 = new Bird(12.0f,6.0f,0.8f,&timer,QPixmap(":/enemy3.png").scaled(height()/6.0,height()/6.0),world,scene);
    Bird *enemy4 = new Bird(24.0f,4.0f,0.3f,&timer,QPixmap(":/enemy4.png").scaled(height()/9.0,height()/9.0),world,scene);
    Bird *enemy5 = new Bird(24.0f,6.0f,0.5f,&timer,QPixmap(":/enemy5.png").scaled(height()/12.0,height()/12.0),world,scene);
    Bird *enemy6 = new Bird(24.0f,8.0f,0.5f,&timer,QPixmap(":/enemy6.png").scaled(height()/12.0,height()/12.0),world,scene);
    Bird *blocker4 = new Bird(28.0f,4.0f,0.7f,&timer,QPixmap(":/blocker4.png").scaled(height()/5.0,height()/6.0),world,scene);
    Bird *blocker6 = new Bird(22.0f,6.0f,0.27f,&timer,QPixmap(":/blocker6.png").scaled(height()/10.0,height()/10.0),world,scene);
    Bird *blocker8 = new Bird(22.0f,6.0f,0.4f,&timer,QPixmap(":/blocker8.png").scaled(height()/12.0,height()/12.0),world,scene);
    itemList.push_back(enemy1);
    itemList.push_back(enemy2);
    itemList.push_back(enemy3);
    itemList.push_back(enemy4);
    itemList.push_back(enemy5);
    itemList.push_back(enemy6);
    itemList.push_back(blocker4);
    itemList.push_back(blocker6);
    itemList.push_back(blocker8);



    QIcon *button = new QIcon(QPixmap(":/exit.png"));
    QPushButton *exit = new QPushButton(*button,"");
    exit->setIconSize(QSize(60,60));
    exit->setGeometry(700,30,80,80);
    scene->addWidget(exit);
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));

    QIcon *button2 = new QIcon(QPixmap(":/restart.png"));
    QPushButton *start = new QPushButton(*button2,"");
    start->setIconSize(QSize(60,60));
    start->setGeometry(400,30,80,80);
    scene->addWidget(start);
    connect(start,SIGNAL(clicked()),this,SLOT(restart()));
};

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */


    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        i=i+1;

        if(i==2){
            //std::cout << "Hi A !" << std::endl ;
            delete birdie;
            birdie_2 = new Bird(9.0f,9.0f,0.35f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
            birdie_2->setLinearVelocity(b2Vec2(5,7));
            itemList.push_back(birdie_2);
        }

        if(i==4){
            //std::cout << "Hi B !" << std::endl ;
            delete birdie2;
            birdie2_2 = new Bird(9.0f,9.0f,0.35f,&timer,QPixmap(":/bird2.png").scaled(height()/9.0,height()/9.0),world,scene);
            birdie2_2->setLinearVelocity(b2Vec2(5,7));
            itemList.push_back(birdie2_2);

        }
        if(i==6){
            //std::cout << "Hi B2 !" << std::endl ;
            Bird *party = new Bird(25.0f,16.0f,0.35f,&timer,QPixmap(":/party.png").scaled(height()/9.0,height()/9.0),world,scene);
            Bird *party1 = new Bird(12.0f,16.0f,0.35f,&timer,QPixmap(":/party1.png").scaled(height()/9.0,height()/9.0),world,scene);
            Bird *party2 = new Bird(22.0f,16.0f,0.35f,&timer,QPixmap(":/party2.png").scaled(height()/9.0,height()/9.0),world,scene);
            Bird *party3 = new Bird(4.0f,16.0f,0.35f,&timer,QPixmap(":/party3.png").scaled(height()/9.0,height()/9.0),world,scene);
            Bird *party4 = new Bird(30.0f,16.0f,0.35f,&timer,QPixmap(":/party4.png").scaled(height()/9.0,height()/9.0),world,scene);
            itemList.push_back(party);
            itemList.push_back(party1);
            itemList.push_back(party2);
            itemList.push_back(party3);
            itemList.push_back(party4);
            birdie2_2->setLinearVelocity(b2Vec2(7,7));
        }
        if(i==8){
            //std::cout << "Hi C !" << std::endl ;
            delete birdie3;
            birdie3_2 = new Bird(9.0f,9.0f,0.35f,&timer,QPixmap(":/bird3.png").scaled(height()/9.0,height()/9.0),world,scene);
            birdie3_2->setLinearVelocity(b2Vec2(5,7));
            itemList.push_back(birdie3_2);
        }
        if(i==10){
            //std::cout << "Hi C2 !" << std::endl ;
            birdie3_2->setLinearVelocity(b2Vec2(25,0));
        }
        if(i==12){
            //std::cout << "Hi D !" << std::endl ;
            delete birdie4;
            birdie4_2 = new Bird(9.0f,9.0f,0.35f,&timer,QPixmap(":/bird4.png").scaled(height()/9.0,height()/9.0),world,scene);
            birdie4_2->setLinearVelocity(b2Vec2(5,7));
            itemList.push_back(birdie4_2);
        }
        if(i==14){
            //std::cout << "Hi D2 !" << std::endl ;
            birdie4_2->setLinearVelocity(b2Vec2(0,-26));
        }

        //std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // Close event
    switch( QMessageBox::information( this, tr("Are you sure?"),
        tr("Do you really want to exit the Angrybird game?"),
        tr("Yes"), tr("No"),
        0, 1 ) )
        {
         case 0:
         event->accept();
            break;
         case 1:
         default:
            event->ignore();
            break;
        }
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::close()
{
    emit quitGame();
    QApplication *app;
    app->quit();
    //world->Step(1.0/60.0,6,2);
    //scene->update();
}

void MainWindow::restart()
{

    i=0;
    itemList.clear();
    repeat();

    //std::cout<<"restart"<<std::endl;
    //world->Step(1.0/60.0,6,2);
    scene->update();
}
