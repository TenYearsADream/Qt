#include <QDebug>

#include "del.h"

int main(int argc, char** argv)
{

    if (argc < 3) {
        qDebug() << "Usage: " << argv[0] << "file-size "
                 << "director "
                 << "extension ";
        return 0;
    }

    Del deleteFile(atoi(argv[1]), argv[2]);
    deleteFile.run();

    return 0;
}
