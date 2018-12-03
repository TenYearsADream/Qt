#include <QDir>

#include "generateprojectfile.h"

int main(int argc, char *argv[]) {
  GenerateProjectFile project(QDir::currentPath());
  project.run();
}
