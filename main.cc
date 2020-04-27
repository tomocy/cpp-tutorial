#include "all.h"

int main() {
  int i = 1;
  while (i <= 9) {
    int j = 1;
    while (j <= 9) {
      std::cout << i * j << "\t"s;
      ++j;
    }
    std::cout << std::endl;

    ++i;
  }

  return EXIT_SUCCESS;
}