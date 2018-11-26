#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QTextEdit* editor1 = new QTextEdit;
    QTextEdit* editor2 = new QTextEdit;
    QTextEdit* editor3 = new QTextEdit;

    QSplitter splitter(Qt::Horizontal);
    splitter.addWidget(editor1);
    splitter.addWidget(editor2);
    splitter.addWidget(editor3);

    editor1->setPlainText(QObject::tr("天行有常，不为尧存，不为桀亡。"));
    editor2->setPlainText(QObject::tr("哈哈哈哈哈哈哈哈哈哈哈哈\n哈哈哈哈哈哈哈哈哈哈哈"));
    editor3->setPlainText(QObject::tr("Qt"));

    splitter.setWindowTitle(QObject::tr("Splitter"));
    splitter.show();

    return app.exec();
}
