#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QMenu;
class QSpinBox;
QT_END_NAMESPACE

class ToolBar : public QToolBar {
    Q_OBJECT

public:
    explicit ToolBar(const QString& title, QWidget* parent);

    QMenu* toolbarMenu() const;

private
slots:
    void order();
    void randomize();
    void addSpinBox();
    void removeSpinBox();

    void changeMovable(bool movable);

    void allowLeft(bool a);
    void allowRight(bool a);
    void allowTop(bool a);
    void allowBottom(bool a);

    void placeLeft(bool p);
    void placeRight(bool p);
    void placeTop(bool p);
    void placeBottom(bool p);

    void updateMenu();
    void insertToolBarBreak();

private:
    void allow(Qt::ToolBarArea area, bool allow);
    void place(Qt::ToolBarArea area, bool place);

    QSpinBox* spinBox;
    QAction* spinBoxAction;

    QMenu* menu;
    QAction* orderAction;
    QAction* randomizeAction;
    QAction* addSpinBoxAction;
    QAction* removeSpinBoxAction;

    QAction* movableAction;

    QActionGroup* allowedAreaAction;
    QAction* allowLeftAction;
    QAction* allowRightAction;
    QAction* allowTopAction;
    QAction* allowBottomAction;

    QActionGroup* areaAction;
    QAction* leftAction;
    QAction* rightAction;
    QAction* topAction;
    QAction* bottomAction;
};

#endif // TOOLBAR_H
