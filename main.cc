#include "all.h"
#include "array.h"

int main() {
  auto a = Array<int, 10>{1, 2, 3, 4, 5};
  for (auto x : a) {
    std::cout << x << std::endl;
  }

  return EXIT_SUCCESS;
}