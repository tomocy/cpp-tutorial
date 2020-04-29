#include "all.h"

class Fraction {
 public:
  Fraction(int num, int denom) : num(num), denom(denom) {}

  double Value() {
    return static_cast<double>(num) / static_cast<double>(denom);
  }

  Fraction operator+(const Fraction& right) {
    if (denom == right.denom) {
      return Fraction(num + right.num, denom);
    }

    return Fraction(num * right.denom + right.num * denom, denom * right.denom);
  }

  Fraction operator-(const Fraction& right) {
    if (denom == right.denom) {
      return Fraction(num - right.num, denom);
    }

    return Fraction(num * right.denom - right.num * denom, denom * right.denom);
  }

  Fraction operator*(const Fraction& right) {
    return Fraction(num * right.num, denom * right.denom);
  }

  Fraction operator/(const Fraction& right) {
    return Fraction(num * right.denom, denom * right.num);
  }

 private:
  int num;
  int denom;
};

int main() {
  auto a = Fraction(6, 2);
  auto b = Fraction(4, 2);
  auto c = a + b;
  auto d = a - b;
  auto e = a * b;
  auto f = a / b;

  std::cout << c.Value() << std::endl;
  std::cout << d.Value() << std::endl;
  std::cout << e.Value() << std::endl;
  std::cout << f.Value() << std::endl;

  return EXIT_SUCCESS;
}