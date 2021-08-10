#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPixmap>
#include "mypushbutton.h"
#include <QTimer>
#include "mainscence.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置固定大小
    this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle("GAME");//标题内容




    //开始按钮
    MyPushButton *startBtn =new MyPushButton(":/mbutton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.6-350);

     ms=new MainScence;


    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入下一个场景
        QTimer::singleShot(270,this,[=](){
            //自身隐藏
            this->hide();
            //显示下一个场景
            ms ->show();
        });
    });


 }







MainWindow::~MainWindow()
{
    delete ui;
}

//重写画家事件，画背景图
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/back.jpg");//主场景图片
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}
