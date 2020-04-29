#include "all.h"

class Fraction {
 public:
  Fraction(int num, int denom) : num(num), denom(denom) {}

  double Value() {
    return static_cast<double>(num) / static_cast<double>(denom);
  }

 private:
  int num;
  int denom;
};

int main() {
  auto f = Fraction(3, 2);
  std::cout << f.Value() << std::endl;

  return EXIT_SUCCESS;
}