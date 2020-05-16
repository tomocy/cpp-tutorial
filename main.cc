#include "all.h"
#include "vector.h"

int main() {
  auto x = Vector<int>(10);

  for (auto v : x) {
    std::cout << v << std::endl;
  }

  return EXIT_SUCCESS;
}