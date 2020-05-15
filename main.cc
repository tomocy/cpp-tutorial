#include "all.h"

template <typename T, std::size_t N>
struct Array {
  T& operator[](std::size_t i) { return data[i]; }
  const T& operator[](std::size_t i) const { return data[i]; }

  std::size_t size() const { return N; }

  T data[N];
};

int main() {
  const auto a = Array<int, 20>{0, 1, 2, 3, 4, 5};
  for (std::size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << std::endl;
  }

  return EXIT_SUCCESS;
}