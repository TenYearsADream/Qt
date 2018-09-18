#include "parsebibtex.h"

int main(int argc, char **argv) {
  Q_UNUSED(argc);
  Q_UNUSED(argv);

  ParseBibtex parseBibTex;
  parseBibTex.parse();

  return 0;
}
