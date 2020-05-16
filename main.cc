#include <array>

#include "all.h"
#include "vector.h"

int main() {
  auto src = std::array<int, 5>{1, 2, 3, 4, 5};
  auto x = Vector<int>(std::begin(src), std::end(src));

  for (auto v : x) {
    std::cout << v << std::endl;
  }

  return EXIT_SUCCESS;
}