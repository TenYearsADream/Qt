#include <QAction>
#include <QApplication>
#include <QColorDialog>
#include <QDir>
#include <QFileDialog>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>

#include "MainWindow.h"
#include "TabletCanvas.h"

MainWindow::MainWindow(TabletCanvas *canvas) : m_canvas(canvas), m_colorDialog(nullptr) {
  createMenus();
  setWindowTitle(tr("Tablet Example"));
  setCentralWidget(m_canvas);
  QCoreApplication::setAttribute(Qt::AA_CompressHighFrequencyEvents);
}

MainWindow::~MainWindow() {
}

void MainWindow::setBurshColor() {
  if (!m_colorDialog) {
    m_colorDialog = new QColorDialog(this);
    m_colorDialog->setModal(false);
    m_colorDialog->setCurrentColor(m_canvas->color());
    connect(m_colorDialog, &QColorDialog::colorSelected, m_canvas, &TabletCanvas::setColor);
  }
  m_colorDialog->setVisible(true);
}

void MainWindow::setAlphaValuator(QAction *action) {
  m_canvas->setAlphaChannelValuator(action->data().value<TabletCanvas::Valuator>());
}

void MainWindow::setLineWidthValuator(QAction *action) {
  m_canvas->setLineWidthType(action->data().value<TabletCanvas::Valuator>());
}

void MainWindow::setSaturationValuator(QAction *action) {
  m_canvas->setColorSaturationValuator(action->data().value<TabletCanvas::Valuator>());
}

void MainWindow::setEventCompression(bool compress) {
  QCoreApplication::setAttribute(Qt::AA_CompressTabletEvents, compress);
}

void MainWindow::save() {
  QString path = QDir::currentPath() + "/untitled.png";
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save Picture"), path);

  if (!m_canvas->saveImage(fileName)) {
    QMessageBox::information(this, tr("Error Saving Picture"), "Could not save the image");
  }
}

void MainWindow::load() {
  QString fileName = QFileDialog::getOpenFileName(this, tr("Open Picture"), QDir::currentPath());

  if (!m_canvas->loadImage(fileName)) {
    QMessageBox::information(this, "Error Opening Picture", "Could not open picture");
  }
}

void MainWindow::about() {
  QMessageBox::about(this, tr("About Tablet Example"), tr("This example shows how to use a graphics drawing tablet in Qt"));
}

void MainWindow::createMenus() {
  QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(tr("&Open..."), this, &MainWindow::load, QKeySequence::Open);
  fileMenu->addAction(tr("&Save As..."), this, &MainWindow::save, QKeySequence::SaveAs);
  fileMenu->addAction(tr("E&xit"), this, &MainWindow::close, QKeySequence::Quit);

  QMenu *brushMenu = menuBar()->addMenu(tr("&Brush"));
  brushMenu->addAction(tr("&Brush Color..."), this, &MainWindow::setBurshColor, tr("Ctrl+B"));

  QMenu *tabletMenu = menuBar()->addMenu(tr("&Tablet"));
  QMenu *lineWidthMenu = tabletMenu->addMenu(tr("&Line Width"));

  QAction *lineWidthPressureAction = lineWidthMenu->addAction(tr("&Pressure"));
  lineWidthPressureAction->setData(TabletCanvas::PressureValuator);
  lineWidthPressureAction->setCheckable(true);
  lineWidthPressureAction->setChecked(true);

  QAction *lineWidhtTiltAction = lineWidthMenu->addAction(tr("&Tilt"));
  lineWidhtTiltAction->setData(TabletCanvas::TiltValuator);
  lineWidhtTiltAction->setCheckable(true);

  QAction *lineWidthFixedAction = lineWidthMenu->addAction(tr("&Fixed"));
  lineWidthFixedAction->setData(TabletCanvas::NoValuator);
  lineWidthFixedAction->setCheckable(true);

  QActionGroup *lineWidthGroup = new QActionGroup(this);
  lineWidthGroup->addAction(lineWidthPressureAction);
  lineWidthGroup->addAction(lineWidhtTiltAction);
  lineWidthGroup->addAction(lineWidthFixedAction);
  connect(lineWidthGroup, &QActionGroup::triggered, this, &MainWindow::setLineWidthValuator);

  QMenu *alphaChannelMenu = tabletMenu->addMenu(tr("&Alpha Channel"));
  QAction *alphaChannelPressureAction = alphaChannelMenu->addAction(tr("&Pressure"));
  alphaChannelPressureAction->setData(TabletCanvas::PressureValuator);
  alphaChannelPressureAction->setCheckable(true);

  QAction *alphaChannelTangentialPressureAction = alphaChannelMenu->addAction(tr("T&angential Pressure"));
  alphaChannelTangentialPressureAction->setData(TabletCanvas::TangentialPressureValuator);
  alphaChannelTangentialPressureAction->setCheckable(true);
  alphaChannelTangentialPressureAction->setChecked(true);

  QAction *alphaChannelTiltAction = alphaChannelMenu->addAction(tr("&Tilt"));
  alphaChannelTiltAction->setData(TabletCanvas::TiltValuator);
  alphaChannelTiltAction->setCheckable(true);

  QAction *noAlphaChannelAction = alphaChannelMenu->addAction(tr("No Alpha Channel"));
  noAlphaChannelAction->setData(TabletCanvas::NoValuator);
  noAlphaChannelAction->setCheckable(true);

  QActionGroup *alphaChannelGroup = new QActionGroup(this);
  alphaChannelGroup->addAction(alphaChannelPressureAction);
  alphaChannelGroup->addAction(alphaChannelTangentialPressureAction);
  alphaChannelGroup->addAction(alphaChannelTiltAction);
  alphaChannelGroup->addAction(noAlphaChannelAction);
  connect(alphaChannelGroup, &QActionGroup::triggered, this, &MainWindow::setAlphaValuator);

  QMenu *colorSaturationMenu = tabletMenu->addMenu(tr("&Color Saturation"));

  QAction *colorSaturationVTiltAction = colorSaturationMenu->addAction(tr("&Vertical Tilt"));
  colorSaturationVTiltAction->setData(TabletCanvas::VTiltValuator);
  colorSaturationVTiltAction->setCheckable(true);

  QAction *colorSaturationHTiltAction = colorSaturationMenu->addAction(tr("&Horizontal Tilt"));
  colorSaturationHTiltAction->setData(TabletCanvas::HTiltValuator);
  colorSaturationHTiltAction->setCheckable(true);

  QAction *colorSaturationPressureAction = colorSaturationMenu->addAction(tr("&Pressure"));
  colorSaturationPressureAction->setData(TabletCanvas::PressureValuator);
  colorSaturationPressureAction->setCheckable(true);

  QAction *noColorSaturationAction = colorSaturationMenu->addAction(tr("&No Color Saturation"));
  noColorSaturationAction->setData(TabletCanvas::NoValuator);
  noColorSaturationAction->setCheckable(true);
  noColorSaturationAction->setChecked(true);

  QActionGroup *colorSaturationGroup = new QActionGroup(this);
  colorSaturationGroup->addAction(colorSaturationVTiltAction);
  colorSaturationGroup->addAction(colorSaturationHTiltAction);
  colorSaturationGroup->addAction(colorSaturationPressureAction);
  colorSaturationGroup->addAction(noColorSaturationAction);
  connect(colorSaturationGroup, &QActionGroup::triggered, this, &MainWindow::setSaturationValuator);

  QAction *compressAction = tabletMenu->addAction(tr("Co&mpress events"));
  compressAction->setCheckable(true);
  connect(compressAction, &QAction::toggled, this, &MainWindow::setEventCompression);

  QMenu *helpMenu = menuBar()->addMenu("&Help");
  helpMenu->addAction(tr("A&bout"), this, &MainWindow::about);
  helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
}
