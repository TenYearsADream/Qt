#include <QtWidgets>

#include "spreadsheet.h"
#include "cell.h"

Spreadsheet::Spreadsheet(QWidget* parent) : QTableWidget(parent)
{
    autoRecalc = true;

    setItemPrototype(new Cell);
    setSelectionMode(ContiguousSelection);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(somethingChanged()));
    clear();
}
