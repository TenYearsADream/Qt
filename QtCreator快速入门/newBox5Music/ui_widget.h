/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sat Apr 17 11:19:28 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *frame;
    QPushButton *gameStartBtn;
    QPushButton *gamePauseBtn;
    QPushButton *exitBtn;
    QLCDNumber *lcdNumber;
    QSlider *boxAudioVolumeSlider;
    QSlider *backgroundAudioVolumeSlider_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 450);
        frame = new QFrame(Widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(29, 20, 381, 411));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(1);
        frame->setMidLineWidth(0);
        gameStartBtn = new QPushButton(Widget);
        gameStartBtn->setObjectName(QString::fromUtf8("gameStartBtn"));
        gameStartBtn->setGeometry(QRect(500, 50, 75, 23));
        gamePauseBtn = new QPushButton(Widget);
        gamePauseBtn->setObjectName(QString::fromUtf8("gamePauseBtn"));
        gamePauseBtn->setGeometry(QRect(500, 110, 75, 23));
        gamePauseBtn->setCheckable(true);
        exitBtn = new QPushButton(Widget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setGeometry(QRect(500, 180, 75, 23));
        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(470, 250, 121, 23));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setLineWidth(1);
        lcdNumber->setMidLineWidth(1);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setNumDigits(5);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        boxAudioVolumeSlider = new QSlider(Widget);
        boxAudioVolumeSlider->setObjectName(QString::fromUtf8("boxAudioVolumeSlider"));
        boxAudioVolumeSlider->setGeometry(QRect(489, 370, 101, 21));
        boxAudioVolumeSlider->setMaximum(100);
        boxAudioVolumeSlider->setSingleStep(1);
        boxAudioVolumeSlider->setPageStep(10);
        boxAudioVolumeSlider->setValue(100);
        boxAudioVolumeSlider->setSliderPosition(100);
        boxAudioVolumeSlider->setOrientation(Qt::Horizontal);
        backgroundAudioVolumeSlider_2 = new QSlider(Widget);
        backgroundAudioVolumeSlider_2->setObjectName(QString::fromUtf8("backgroundAudioVolumeSlider_2"));
        backgroundAudioVolumeSlider_2->setGeometry(QRect(490, 330, 101, 21));
        backgroundAudioVolumeSlider_2->setMaximum(100);
        backgroundAudioVolumeSlider_2->setSingleStep(1);
        backgroundAudioVolumeSlider_2->setPageStep(10);
        backgroundAudioVolumeSlider_2->setValue(100);
        backgroundAudioVolumeSlider_2->setSliderPosition(100);
        backgroundAudioVolumeSlider_2->setOrientation(Qt::Horizontal);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 330, 41, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 370, 41, 16));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        gameStartBtn->setText(QApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        gamePauseBtn->setText(QApplication::translate("Widget", "\346\232\202\345\201\234\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        exitBtn->setText(QApplication::translate("Widget", "\351\200\200\345\207\272\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\351\237\263\344\271\220\357\274\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\351\237\263\346\225\210\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
