#include <QTextFrame>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QTextDocument *document = ui->textEdit->document();
  QTextFrame *rootFrame = document->rootFrame();
  QTextFrameFormat format;
  format.setBorderBrush(Qt::red);
  format.setBorder(3);
  rootFrame->setFrameFormat(format);

  QTextFrameFormat frameFormat;
  frameFormat.setBackground(Qt::lightGray);
  frameFormat.setTopMargin(10);
  frameFormat.setPadding(5);
  frameFormat.setBorder(2);
  frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted);
  QTextCursor cursor = ui->textEdit->textCursor();
  cursor.insertFrame(frameFormat);

  QAction *action_textFrame = new QAction(tr("Frame"), this);
  connect(action_textFrame, &QAction::triggered, this, &MainWindow::showTextFrame);
  ui->mainToolBar->addAction(action_textFrame);

  QAction *action_textBlock = new QAction(tr("Block"), this);
  connect(action_textBlock, &QAction::triggered, this, &MainWindow::showTextBlock);
  ui->mainToolBar->addAction(action_textBlock);

  QAction *action_font = new QAction(tr("Font"), this);
  action_font->setCheckable(true);
  connect(action_font, &QAction::triggered, this, &MainWindow::setTextFont);
  ui->mainToolBar->addAction(action_font);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::changeEvent(QEvent *e) {
  QMainWindow::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
  }
}

void MainWindow::showTextFrame() {
  QTextDocument *document = ui->textEdit->document();
  QTextFrame *frame = document->rootFrame();
  for (auto it = frame->begin(); !it.atEnd(); ++it) {
    QTextFrame *childFrame = it.currentFrame();
    QTextBlock childBlock = it.currentBlock();
    if (childFrame) {
      qDebug() << "frame";
    } else if (childBlock.isValid()) {
      qDebug() << "block:" << childBlock.text();
    }
  }
}

void MainWindow::showTextBlock() {
  QTextDocument *document = ui->textEdit->document();
  QTextBlock block = document->firstBlock();
  for (int i = 0; i != document->blockCount(); ++i) {
    qDebug() << tr("text block %1, the row number is: %2, lenght is: %3, contents are:")
                    .arg(i)
                    .arg(block.firstLineNumber())
                    .arg(block.length()) << block.text();
  }
}

void MainWindow::setTextFont(bool checked) {
  if (checked) {
    QTextCursor cursor = ui->textEdit->textCursor();
    QTextBlockFormat blockFormat;
    blockFormat.setAlignment(Qt::AlignCenter);
    cursor.insertBlock(blockFormat);
    QTextCharFormat charFormat;
    charFormat.setBackground(Qt::lightGray);
    charFormat.setForeground(Qt::blue);
    charFormat.setFont(QFont(tr("SongTi"), 12, QFont::Bold, true));
    charFormat.setFontUnderline(true);
    cursor.setCharFormat(charFormat);
    cursor.insertText(tr("text char "));
  } else {
    //.......d
  }
}
