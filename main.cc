#include "all.h"

void Print(const std::vector<int>& vs) {
  for (auto v : vs) {
    std::cout << v << std::endl;
  }
}

int main() {
  auto vs = std::vector<int>{1, 3, 5, 2, 3, 1};
  Print(vs);

  return EXIT_SUCCESS;
}