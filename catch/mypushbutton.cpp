#include "mypushbutton.h"
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgPath=normalImg;
    this->pressImgPath=pressImg;

    QPixmap pix;
    pix.load(normalImg);

    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0Px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));



}
void MyPushButton::zoom1()//向下跳
{
    QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+15,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();

}
void MyPushButton::zoom2()//向上跳
{
    QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+15,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}













