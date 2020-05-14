#include "all.h"

struct Array {
  int& operator[](std::size_t i) { return data[i]; }
  int data[10];
};

int main() {
  auto a = Array{0, 1, 2, 3, 4, 5};
  a[3] = 0;
  auto size = sizeof(a) / sizeof(int);
  for (std::size_t i = 0; i < size; ++i) {
    std::cout << a[i] << std::endl;
  }

  return EXIT_SUCCESS;
}