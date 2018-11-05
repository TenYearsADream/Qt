#include <QSpinBox>
#include <QToolButton>
#include <QMenu>
#include <QAction>
#include <QIcon>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu* editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));
    QAction* action_Open
        = editMenu->addAction(QIcon(":/images/open.png"), tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(action_Open);

    QActionGroup* group = new QActionGroup(this);
    QAction* action_L = group->addAction(tr("左对齐(&L)"));
    action_L->setCheckable(true);
    QAction* action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction* action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);

    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    QToolButton* toolButton = new QToolButton;
    toolButton->setText(tr("颜色"));
    QMenu* colorMenu = new QMenu(this);
    colorMenu->addAction(tr("红色"));
    colorMenu->addAction(tr("绿色"));
    toolButton->setMenu(colorMenu);
    toolButton->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolButton);
    QSpinBox* spinBox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinBox);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent* e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
