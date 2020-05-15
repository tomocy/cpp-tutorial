#include "all.h"

template <typename T, std::size_t N>
struct Array {
  using value_type = T;
  using reference = value_type&;

  reference operator[](std::size_t i) { return data[i]; }
  const reference operator[](std::size_t i) const { return data[i]; }

  std::size_t size() const { return N; }

  reference front() { return data[0]; }
  const reference front() const { return data[0]; }

  reference back() { return data[N - 1]; }
  const reference back() const { return data[N - 1]; }

  value_type data[N];
};

int main() {
  auto a = Array<int, 20>{5, 4, 3, 2, 1};
  for (std::size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << std::endl;
  }

  const auto front = a.front();
  const auto back = a.back();
  std::cout << "front: " << front << std::endl;
  std::cout << "back: " << back << std::endl;

  return EXIT_SUCCESS;
}