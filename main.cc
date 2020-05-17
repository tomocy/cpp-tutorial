#include <array>

#include "all.h"
#include "vector.h"

template <typename Vector>
void Print(const std::string name, const Vector& v) {
  std::cout << name << " ---" << std::endl;
  std::cout << "- metadata ---" << std::endl;
  std::cout << "    size: " << v.size() << std::endl;
  std::cout << "    capacity: " << v.capacity() << std::endl;
  std::cout << "    first: " << v.begin() << std::endl;
  std::cout << "    last: " << v.end() << std::endl;
  if (v.size() >= 1) {
    std::cout << "    front: " << v.front() << std::endl;
    std::cout << "    back: " << v.back() << std::endl;
  }
  std::cout << "- data ---" << std::endl;
  for (auto x : v) {
    std::cout << x << std::endl;
  }
}

int main() {
  auto src = std::array<int, 5>{1, 2, 3, 4, 5};

  auto x = Vector<int>(std::begin(src), std::end(src));
  Print("x", x);

  auto y = Vector<int>(x);
  Print("y", y);

  y.at(0) = 100;
  Print("x after changing y", x);
  Print("y after changing", y);

  auto z = Vector<int>(20);
  Print("z before coping y", z);
  z = y;
  Print("z after coping y", z);

  auto a = Vector<int>(0);
  Print("a before coping z", a);
  a = z;
  Print("a after coping z", a);

  auto b = Vector<int>(std::move(a));
  Print("a after moving", a);
  Print("b", b);

  auto c = std::move(b);
  Print("b after moving", b);
  Print("c", c);

  return EXIT_SUCCESS;
}