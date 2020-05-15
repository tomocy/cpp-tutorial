#include "all.h"
#include "array.h"

int main() {
  auto a = Array<int, 20>{5, 4, 3, 2, 1};
  const auto b = a;

  for (auto iter = a.begin(); iter != a.end(); ++iter) {
    std::cout << *iter << std::endl;
  }
  for (auto iter = b.begin(); iter != b.end(); ++iter) {
    std::cout << *iter << std::endl;
  }

  return EXIT_SUCCESS;
}