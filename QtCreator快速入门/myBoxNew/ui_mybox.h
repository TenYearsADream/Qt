/********************************************************************************
** Form generated from reading UI file 'mybox.ui'
**
** Created: Thu Apr 29 17:42:24 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYBOX_H
#define UI_MYBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyBox
{
public:
    QFrame *gameFrame;
    QPushButton *reStartBtn;
    QPushButton *pauseBtn;
    QPushButton *backBtn;
    QWidget *MainMenuWidget;
    QGridLayout *gridLayout;
    QPushButton *gameStartBtn;
    QPushButton *setOptionBtn;
    QPushButton *gameExitBtn;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_5;
    QLabel *scoreLabel;
    QWidget *gradeWidget;
    QLabel *gradeLabel_11;
    QLabel *gradeLabel_1;
    QLabel *gradeLabel_21;
    QLabel *gradeLabel_2;
    QLabel *gradeLabel_31;
    QLabel *gradeLabel_3;
    QLabel *gradeLabel_41;
    QLabel *gradeLabel_51;
    QLabel *gradeLabel_4;
    QLabel *gradeLabel_5;
    QWidget *maskWidget;
    QFrame *optionFrame;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *backOptionBtn;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QRadioButton *gameGridRadioButton;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *downKeyRadioButton;
    QFrame *frame_3;
    QGridLayout *gridLayout_3;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *MyBox)
    {
        if (MyBox->objectName().isEmpty())
            MyBox->setObjectName(QString::fromUtf8("MyBox"));
        MyBox->resize(800, 500);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        MyBox->setFont(font);
        gameFrame = new QFrame(MyBox);
        gameFrame->setObjectName(QString::fromUtf8("gameFrame"));
        gameFrame->setGeometry(QRect(130, 60, 421, 421));
        gameFrame->setFocusPolicy(Qt::StrongFocus);
        gameFrame->setFrameShape(QFrame::Panel);
        gameFrame->setFrameShadow(QFrame::Sunken);
        gameFrame->setLineWidth(6);
        reStartBtn = new QPushButton(MyBox);
        reStartBtn->setObjectName(QString::fromUtf8("reStartBtn"));
        reStartBtn->setGeometry(QRect(610, 90, 81, 23));
        QFont font1;
        font1.setPointSize(12);
        reStartBtn->setFont(font1);
        pauseBtn = new QPushButton(MyBox);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        pauseBtn->setGeometry(QRect(610, 130, 81, 23));
        pauseBtn->setFont(font1);
        pauseBtn->setCheckable(true);
        backBtn = new QPushButton(MyBox);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(610, 170, 81, 23));
        backBtn->setFont(font1);
        backBtn->setCheckable(true);
        MainMenuWidget = new QWidget(MyBox);
        MainMenuWidget->setObjectName(QString::fromUtf8("MainMenuWidget"));
        MainMenuWidget->setGeometry(QRect(572, 398, 151, 181));
        MainMenuWidget->setFont(font);
        MainMenuWidget->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100)"));
        gridLayout = new QGridLayout(MainMenuWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gameStartBtn = new QPushButton(MainMenuWidget);
        gameStartBtn->setObjectName(QString::fromUtf8("gameStartBtn"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font2.setPointSize(12);
        gameStartBtn->setFont(font2);
        gameStartBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255)"));
        gameStartBtn->setCheckable(true);

        gridLayout->addWidget(gameStartBtn, 3, 1, 1, 1);

        setOptionBtn = new QPushButton(MainMenuWidget);
        setOptionBtn->setObjectName(QString::fromUtf8("setOptionBtn"));
        setOptionBtn->setFont(font2);
        setOptionBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255)"));

        gridLayout->addWidget(setOptionBtn, 4, 1, 1, 1);

        gameExitBtn = new QPushButton(MainMenuWidget);
        gameExitBtn->setObjectName(QString::fromUtf8("gameExitBtn"));
        gameExitBtn->setFont(font2);
        gameExitBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255)"));

        gridLayout->addWidget(gameExitBtn, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 1, 1, 1);

        label = new QLabel(MainMenuWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font3.setPointSize(30);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0,200);\n"
"background-color:rgb(255, 255, 255,0)"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 2, 1, 1, 1);

        scoreLabel = new QLabel(MyBox);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setGeometry(QRect(580, 250, 191, 21));
        scoreLabel->setFont(font2);
        scoreLabel->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color:(0,0,0,0);"));
        gradeWidget = new QWidget(MyBox);
        gradeWidget->setObjectName(QString::fromUtf8("gradeWidget"));
        gradeWidget->setGeometry(QRect(50, 10, 581, 50));
        gradeWidget->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100)"));
        gradeLabel_11 = new QLabel(gradeWidget);
        gradeLabel_11->setObjectName(QString::fromUtf8("gradeLabel_11"));
        gradeLabel_11->setGeometry(QRect(50, 20, 40, 22));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font4.setPointSize(15);
        gradeLabel_11->setFont(font4);
        gradeLabel_11->setStyleSheet(QString::fromUtf8("background:rgba(0, 0, 0, 100)"));
        gradeLabel_1 = new QLabel(gradeWidget);
        gradeLabel_1->setObjectName(QString::fromUtf8("gradeLabel_1"));
        gradeLabel_1->setGeometry(QRect(9, 10, 28, 32));
        gradeLabel_1->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0)"));
        gradeLabel_21 = new QLabel(gradeWidget);
        gradeLabel_21->setObjectName(QString::fromUtf8("gradeLabel_21"));
        gradeLabel_21->setGeometry(QRect(160, 20, 40, 22));
        gradeLabel_21->setFont(font4);
        gradeLabel_21->setStyleSheet(QString::fromUtf8("background:rgba(0, 0, 0, 100)"));
        gradeLabel_2 = new QLabel(gradeWidget);
        gradeLabel_2->setObjectName(QString::fromUtf8("gradeLabel_2"));
        gradeLabel_2->setGeometry(QRect(115, 6, 28, 32));
        gradeLabel_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0)"));
        gradeLabel_31 = new QLabel(gradeWidget);
        gradeLabel_31->setObjectName(QString::fromUtf8("gradeLabel_31"));
        gradeLabel_31->setGeometry(QRect(260, 20, 40, 22));
        gradeLabel_31->setFont(font4);
        gradeLabel_31->setStyleSheet(QString::fromUtf8("background:rgba(0, 0, 0, 100)"));
        gradeLabel_3 = new QLabel(gradeWidget);
        gradeLabel_3->setObjectName(QString::fromUtf8("gradeLabel_3"));
        gradeLabel_3->setGeometry(QRect(221, 9, 28, 32));
        gradeLabel_3->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0)"));
        gradeLabel_41 = new QLabel(gradeWidget);
        gradeLabel_41->setObjectName(QString::fromUtf8("gradeLabel_41"));
        gradeLabel_41->setGeometry(QRect(370, 20, 60, 22));
        gradeLabel_41->setFont(font4);
        gradeLabel_41->setStyleSheet(QString::fromUtf8("background:rgba(0, 0, 0, 100)"));
        gradeLabel_51 = new QLabel(gradeWidget);
        gradeLabel_51->setObjectName(QString::fromUtf8("gradeLabel_51"));
        gradeLabel_51->setGeometry(QRect(500, 20, 60, 22));
        gradeLabel_51->setFont(font4);
        gradeLabel_51->setStyleSheet(QString::fromUtf8("background:rgba(0, 0, 0, 100)"));
        gradeLabel_4 = new QLabel(gradeWidget);
        gradeLabel_4->setObjectName(QString::fromUtf8("gradeLabel_4"));
        gradeLabel_4->setGeometry(QRect(327, 9, 28, 32));
        gradeLabel_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0)"));
        gradeLabel_5 = new QLabel(gradeWidget);
        gradeLabel_5->setObjectName(QString::fromUtf8("gradeLabel_5"));
        gradeLabel_5->setGeometry(QRect(460, 9, 28, 32));
        gradeLabel_5->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 0)"));
        maskWidget = new QWidget(MyBox);
        maskWidget->setObjectName(QString::fromUtf8("maskWidget"));
        maskWidget->setGeometry(QRect(30, 510, 120, 80));
        maskWidget->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255)"));
        optionFrame = new QFrame(MyBox);
        optionFrame->setObjectName(QString::fromUtf8("optionFrame"));
        optionFrame->setGeometry(QRect(0, 190, 121, 281));
        optionFrame->setFont(font);
        optionFrame->setStyleSheet(QString::fromUtf8("background-color:rgba(0, 0, 0, 100)"));
        optionFrame->setFrameShape(QFrame::StyledPanel);
        optionFrame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(optionFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(12, 29, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 6, 1, 1, 1);

        backOptionBtn = new QPushButton(optionFrame);
        backOptionBtn->setObjectName(QString::fromUtf8("backOptionBtn"));
        backOptionBtn->setFont(font2);
        backOptionBtn->setStyleSheet(QString::fromUtf8("background-color:rgba(255, 255, 255)"));

        gridLayout_2->addWidget(backOptionBtn, 5, 1, 1, 1);

        frame = new QFrame(optionFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gameGridRadioButton = new QRadioButton(frame);
        gameGridRadioButton->setObjectName(QString::fromUtf8("gameGridRadioButton"));
        gameGridRadioButton->setFont(font2);
        gameGridRadioButton->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color:(0,0,0,0);"));
        gameGridRadioButton->setCheckable(true);
        gameGridRadioButton->setChecked(false);

        horizontalLayout->addWidget(gameGridRadioButton);


        gridLayout_2->addWidget(frame, 1, 1, 1, 1);

        frame_2 = new QFrame(optionFrame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        downKeyRadioButton = new QRadioButton(frame_2);
        downKeyRadioButton->setObjectName(QString::fromUtf8("downKeyRadioButton"));
        downKeyRadioButton->setFont(font2);
        downKeyRadioButton->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color:(0,0,0,0);"));
        downKeyRadioButton->setChecked(false);

        horizontalLayout_2->addWidget(downKeyRadioButton);


        gridLayout_2->addWidget(frame_2, 2, 1, 1, 1);

        frame_3 = new QFrame(optionFrame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSlider = new QSlider(frame_3);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setValue(99);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider, 1, 0, 1, 1);

        horizontalSlider_2 = new QSlider(frame_3);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setValue(99);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_2, 3, 0, 1, 1);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color:(0,0,0,0);"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"background-color:(0,0,0,0);"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);


        gridLayout_2->addWidget(frame_3, 3, 1, 1, 1);


        retranslateUi(MyBox);

        QMetaObject::connectSlotsByName(MyBox);
    } // setupUi

    void retranslateUi(QWidget *MyBox)
    {
        MyBox->setWindowTitle(QApplication::translate("MyBox", "\344\277\204\347\275\227\346\226\257\346\226\271\345\235\227\345\212\263\346\213\211\347\211\210", 0, QApplication::UnicodeUTF8));
        reStartBtn->setText(QApplication::translate("MyBox", "\351\207\215\346\226\260\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        pauseBtn->setText(QApplication::translate("MyBox", "\346\232\202\345\201\234", 0, QApplication::UnicodeUTF8));
        backBtn->setText(QApplication::translate("MyBox", "\345\233\236\345\210\260\344\270\273\350\217\234\345\215\225", 0, QApplication::UnicodeUTF8));
        gameStartBtn->setText(QApplication::translate("MyBox", "\345\274\200\345\247\213\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        setOptionBtn->setText(QApplication::translate("MyBox", "\351\200\211\351\241\271\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        gameExitBtn->setText(QApplication::translate("MyBox", "\347\273\223\346\235\237\346\270\270\346\210\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MyBox", "\345\212\263\346\213\211\346\226\271\345\235\227", 0, QApplication::UnicodeUTF8));
        scoreLabel->setText(QApplication::translate("MyBox", "\344\275\240\347\232\204\345\276\227\345\210\206\346\230\257\357\274\23210000", 0, QApplication::UnicodeUTF8));
        gradeLabel_11->setText(QApplication::translate("MyBox", "\346\226\260\346\211\213", 0, QApplication::UnicodeUTF8));
        gradeLabel_1->setText(QApplication::translate("MyBox", "TextLabel", 0, QApplication::UnicodeUTF8));
        gradeLabel_21->setText(QApplication::translate("MyBox", "\345\205\245\351\227\250", 0, QApplication::UnicodeUTF8));
        gradeLabel_2->setText(QApplication::translate("MyBox", "TextLabel", 0, QApplication::UnicodeUTF8));
        gradeLabel_31->setText(QApplication::translate("MyBox", "\351\253\230\346\211\213", 0, QApplication::UnicodeUTF8));
        gradeLabel_3->setText(QApplication::translate("MyBox", "TextLabel", 0, QApplication::UnicodeUTF8));
        gradeLabel_41->setText(QApplication::translate("MyBox", "\346\214\221\346\210\230\350\200\205", 0, QApplication::UnicodeUTF8));
        gradeLabel_51->setText(QApplication::translate("MyBox", "\346\227\240\347\225\217\350\200\205", 0, QApplication::UnicodeUTF8));
        gradeLabel_4->setText(QApplication::translate("MyBox", "TextLabel", 0, QApplication::UnicodeUTF8));
        gradeLabel_5->setText(QApplication::translate("MyBox", "TextLabel", 0, QApplication::UnicodeUTF8));
        backOptionBtn->setText(QApplication::translate("MyBox", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        gameGridRadioButton->setText(QApplication::translate("MyBox", "\346\230\276\347\244\272\346\270\270\346\210\217\347\275\221\346\240\274", 0, QApplication::UnicodeUTF8));
        downKeyRadioButton->setText(QApplication::translate("MyBox", "\346\214\211\345\220\221\344\270\213\351\224\256\346\226\271\345\235\227\345\235\240\350\220\275", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MyBox", "\351\237\263\344\271\220\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MyBox", "\351\237\263\346\225\210\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyBox: public Ui_MyBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYBOX_H
