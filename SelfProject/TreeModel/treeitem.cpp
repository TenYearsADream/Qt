#include <QStringList>

#include "treeitem.h"

TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parentItem) {
  m_itemData = data;
  m_parentItem = parentItem;
}
