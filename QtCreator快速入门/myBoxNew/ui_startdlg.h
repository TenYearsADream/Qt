/********************************************************************************
** Form generated from reading UI file 'startdlg.ui'
**
** Created: Thu Apr 29 17:18:07 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDLG_H
#define UI_STARTDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StartDlg
{
public:
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *jiantou;
    QPushButton *pushButton;
    QFrame *frame_2;
    QLabel *yafeilinux;

    void setupUi(QDialog *StartDlg)
    {
        if (StartDlg->objectName().isEmpty())
            StartDlg->setObjectName(QString::fromUtf8("StartDlg"));
        StartDlg->resize(800, 500);
        StartDlg->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(StartDlg);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(181, 10, 511, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout->addWidget(label_3);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout->addWidget(label_13);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_11->setFont(font2);

        verticalLayout->addWidget(label_11);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout->addWidget(label_14);

        label_15 = new QLabel(frame);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout->addWidget(label_15);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color:rgb(255, 0, 0)"));

        verticalLayout->addWidget(label_6);

        label_8 = new QLabel(StartDlg);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(250, 350, 141, 41));
        QFont font3;
        font3.setPointSize(15);
        label_8->setFont(font3);
        jiantou = new QLabel(StartDlg);
        jiantou->setObjectName(QString::fromUtf8("jiantou"));
        jiantou->setGeometry(QRect(400, 350, 100, 50));
        jiantou->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(StartDlg);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(550, 350, 75, 51));
        frame_2 = new QFrame(StartDlg);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(30, 250, 120, 80));
        frame_2->setStyleSheet(QString::fromUtf8("background:rgb(0, 0, 0)"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        yafeilinux = new QLabel(frame_2);
        yafeilinux->setObjectName(QString::fromUtf8("yafeilinux"));
        yafeilinux->setGeometry(QRect(20, 30, 54, 13));

        retranslateUi(StartDlg);

        QMetaObject::connectSlotsByName(StartDlg);
    } // setupUi

    void retranslateUi(QDialog *StartDlg)
    {
        StartDlg->setWindowTitle(QApplication::translate("StartDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StartDlg", "\345\212\263\346\213\211\346\226\271\345\235\227\347\272\252\345\277\265\347\211\210", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("StartDlg", "\344\270\272\345\272\206\347\245\235www.yafeilinux.com\346\255\243\345\274\217\345\274\200\351\200\232\357\274\214\347\211\271\346\204\217\345\260\206\346\234\254\346\270\270\346\210\217\350\277\233\350\241\214\346\233\264\346\226\260\344\274\230\345\214\226\343\200\202", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("StartDlg", "\357\274\210\344\270\213\346\254\241\346\270\270\346\210\217\345\217\257\344\273\245\346\214\211\344\273\273\346\204\217\351\224\256\350\267\263\350\277\207\346\234\254\347\252\227\345\217\243\357\274\211", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("StartDlg", "\346\233\264\346\226\2601\357\274\232\345\234\250\351\200\211\351\241\271\344\270\255\345\217\257\344\273\245\350\256\276\347\275\256\351\237\263\344\271\220\343\200\201\351\237\263\346\225\210\347\232\204\351\237\263\351\207\217\345\244\247\345\260\217", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("StartDlg", "\346\233\264\346\226\2602\357\274\232\345\234\250\344\273\273\344\275\225\345\205\263\345\215\241\357\274\214\345\217\252\350\246\201\346\214\211\344\270\213\351\224\256\347\233\230\344\270\212\347\232\204End\351\224\256\357\274\214\347\204\266\345\220\216\346\255\243\345\270\270\347\273\223\346\235\237\346\270\270\346\210\217\357\274\214\351\203\275\344\274\232\350\277\233\345\205\245\347\211\271\345\210\253\345\205\263", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StartDlg", "1.\345\220\221\344\270\212\357\274\214\345\220\221\345\267\246\357\274\214\345\220\221\345\217\263\357\274\214\345\220\221\344\270\213\346\226\271\345\220\221\351\224\256\345\210\206\345\210\253\345\256\236\347\216\260\346\224\271\345\217\230\345\275\242\347\212\266\357\274\214\345\267\246\347\247\273\357\274\214\345\217\263\347\247\273\345\222\214\344\270\213\347\247\273", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StartDlg", "2.\345\234\250\346\270\270\346\210\217\347\232\204\351\200\211\351\241\271\350\256\276\347\275\256\351\207\214\345\217\257\344\273\245\350\256\276\347\275\256\346\214\211\345\220\221\344\270\213\351\224\256\346\230\257\344\270\213\347\247\273\344\270\200\346\240\274\350\277\230\346\230\257\347\233\264\346\216\245\345\235\240\350\220\275\357\274\214\351\273\230\350\256\244\346\230\257\345\220\216\350\200\205", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("StartDlg", "3.\346\270\270\346\210\217\344\270\255\346\266\210\344\270\200\350\241\21410\345\210\206\357\274\214\344\270\244\350\241\21430\345\210\206\357\274\214\344\270\211\350\241\21450\345\210\206\357\274\214\345\233\233\350\241\21470\345\210\206", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("StartDlg", "4.\346\270\270\346\210\217\345\205\261\344\272\224\345\205\263\357\274\214\347\254\254\344\270\200\343\200\201\344\272\214\345\205\263\345\220\204\351\234\200300\345\210\206\357\274\214\347\254\254\344\270\211\343\200\201\345\233\233\345\205\263\345\220\204\351\234\200200\345\210\206\357\274\214\347\254\254\344\272\224\345\205\263\351\234\200100\345\210\206", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("StartDlg", "5.\345\275\223\346\210\220\344\270\272\346\227\240\347\225\217\350\200\205\346\227\266\345\217\257\344\273\245\350\277\233\345\205\245\347\211\271\345\210\253\345\205\263\357\274\214\351\202\243\351\207\214\346\234\211\345\205\250\346\226\260\347\232\204\347\216\251\346\263\225\357\274\214\344\275\240\344\270\200\345\256\232\350\246\201\345\235\232\346\214\201\345\210\260\345\272\225", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StartDlg", "\345\243\260\346\230\216\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StartDlg", "\346\234\254\346\270\270\346\210\217\347\224\261yafeilinux\345\210\266\344\275\234\357\274\214\346\230\257\350\207\252\347\224\261\350\275\257\344\273\266\357\274\214\345\217\257\344\273\245\345\234\250\347\275\221\344\270\212\344\272\244\346\265\201\357\274\214\344\274\240\346\222\255\345\222\214\344\270\213\350\275\275\357\274\214\344\275\206\350\257\267\345\213\277\344\275\234\344\270\272\345\225\206\344\270\232\347\224\250\351\200\224", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("StartDlg", "\346\234\211\344\273\273\344\275\225\351\227\256\351\242\230\350\257\267\345\210\260www.yafeilinux.com\350\201\224\347\263\273\346\210\221\344\273\254\343\200\202", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("StartDlg", "\351\251\254\344\270\212\350\277\233\345\205\245\346\270\270\346\210\217\357\274\232", 0, QApplication::UnicodeUTF8));
        jiantou->setText(QApplication::translate("StartDlg", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("StartDlg", "\350\277\233\345\205\245", 0, QApplication::UnicodeUTF8));
        yafeilinux->setText(QApplication::translate("StartDlg", "TextLabel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StartDlg: public Ui_StartDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDLG_H
