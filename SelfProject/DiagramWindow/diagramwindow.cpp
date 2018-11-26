#include "diagramwindow.h"

DiagramWindow::DiagramWindow(QWidget *parent) : QMainWindow(parent) {
  scene = new QGraphicsScene(0, 0, 600, 500);
  view = new QGraphicsView;
  view->setScene(scene);
  view->setDragMode(QGraphicsView::RubberBandDrag);
  view->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
  view->setContextMenuPolicy(Qt::ActionsContextMenu);
  setCentralWidget(view);

  minZ = 0;
  maxZ = 0;
  seqNumber = 0;

  createActions();
  createMenus();
  createToolBars();
  connect(scene, &QGraphicsScene::selectionChanged, this, &DiagramWindow::updateActions);
  setWindowTitle(tr("Diagram"));
  updateActions();
}

DiagramWindow::~DiagramWindow() {
}

void DiagramWindow::addNode() {
  Node *node = new Node;
  node->setText(tr("Node %1").arg(seqNumber + 1));
  setupNode(node);
}

void DiagramWindow::setupNode(Node *node) {
  node->setPos(QPoint(80 + (100 * (seqNumber % 5)), 80 + (50 * ((seqNumber / 5) % 7))));
  scene->addItem(node);
  ++seqNumber;

  scene->clearSelection();
  node->setSelected(true);
  bringToFront();
}
