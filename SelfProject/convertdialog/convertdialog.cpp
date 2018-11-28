#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include <QPushButton>

#include "convertdialog.h"

ConvertDialog::ConvertDialog(QWidget *parent) : QDialog(parent) {
  setupUi(this);

  QPushButton *convertButton = buttonBox->button(QDialogButtonBox::Ok);
  convertButton->setText(tr("&Convert"));
  convertButton->setEnabled(false);

  connect(convertButton, &QPushButton::clicked, this, &ConvertDialog::convertImage);
  connect(buttonBox, &QDialogButtonBox::rejected, this, &ConvertDialog::reject);
  connect(&process, &QProcess::readyReadStandardError, this, &ConvertDialog::updateOutputTextEdit);
  connect(&process, SIGNAL(finished(int, QProcess::ExitStatus)), this,
          SLOT(processFinished(int, QProcess::ExitStatus)));
  connect(&process, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
}

void ConvertDialog::on_browseButton_clicked() {
  QString initalName = sourceFileEdit->text();
  if (initalName.isEmpty()) {
    initalName = QDir::homePath();
  }
  QString fileName = QFileDialog::getOpenFileName(this, tr("Close File"), initalName);
  fileName = QDir::toNativeSeparators(fileName);

  if (!fileName.isEmpty()) {
    sourceFileEdit->setText(fileName);
    qDebug() << fileName;
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
  }
}

void ConvertDialog::convertImage() {
  QString sourceFile = sourceFileEdit->text();
  targetFile = QFileInfo(sourceFile).path() + QDir::separator() + QFileInfo(sourceFile).baseName() + "." +
               targetFormatComboBox->currentText().toLower();
  buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
  outputTextEdit->clear();

  QStringList args;
  if (enhanceCheckBox->isChecked()) {
    args << "-enhance";
  }
  if (monochromeCheckBox->isChecked()) {
    args << "-monochrome";
  }
  args << sourceFile << targetFile;

  process.start("convert", args);
}

void ConvertDialog::updateOutputTextEdit() {
  QByteArray newData = process.readAllStandardError();
  QString text = outputTextEdit->toPlainText() + QString::fromLocal8Bit(newData);
  outputTextEdit->setPlainText(text);
}

void ConvertDialog::processFinished(int exitCode, QProcess::ExitStatus exitStatus) {
  if (exitStatus == QProcess::CrashExit) {
    outputTextEdit->append(tr("Conversion program failed"));
  } else if (exitCode != 0) {
    outputTextEdit->append(tr("Conversion failed"));
  } else {
    outputTextEdit->append(tr("File %1 created").arg(targetFile));
  }
  buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void ConvertDialog::processError(QProcess::ProcessError error) {
  if (error == QProcess::FailedToStart) {
    outputTextEdit->append(tr("Conversion program not found"));
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
  }
}
