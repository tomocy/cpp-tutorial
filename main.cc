#include "all.h"

int main() {
  for (auto i = 1; i <= 9; ++i) {
    for (auto j = 1; j <= 9; ++j) {
      std::cout << i * j << "\t"s;
    }
    std::cout << std::endl;
  }

  return EXIT_SUCCESS;
}