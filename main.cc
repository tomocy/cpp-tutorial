#include <array>

#include "all.h"
#include "vector.h"

template <typename Vector>
void Print(const Vector& v) {
  std::cout << "vector ---" << std::endl;
  std::cout << "- metadata ---" << std::endl;
  std::cout << "    size: " << v.size() << std::endl;
  std::cout << "    capacity: " << v.capacity() << std::endl;
  std::cout << "    first: " << v.begin() << std::endl;
  std::cout << "    last: " << v.end() << std::endl;
  std::cout << "    front: " << v.front() << std::endl;
  std::cout << "    back: " << v.back() << std::endl;
  std::cout << "- data ---" << std::endl;
  for (auto x : v) {
    std::cout << x << std::endl;
  }
}

int main() {
  auto src = std::array<int, 5>{1, 2, 3, 4, 5};
  auto v = Vector<int>(std::begin(src), std::end(src));
  Print(v);

  std::cout << "reserved: " << std::endl;
  v.reserve(20);
  Print(v);

  std::cout << "pushed back: " << std::endl;
  for (auto i = 0; i < 5; ++i) {
    v.pushBack(i);
  }
  Print(v);

  std::cout << "shrunk to fit: " << std::endl;
  v.shrinkToFit();
  Print(v);

  std::cout << "resized: " << std::endl;
  v.resize(30);
  Print(v);

  return EXIT_SUCCESS;
}