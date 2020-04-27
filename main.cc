#include "all.h"

template <typename T>
T readFromStdin(std::string prompt) {
  std::cout << prompt;
  T v;
  std::cin >> v;

  return v;
}

void Repeat(std::function<bool()> fn) {
loop:
  if (!(fn())) {
    return;
  }

  goto loop;
}

int main() {
  int sum = 0;
  Repeat([&sum]() -> bool {
    auto v = readFromStdin<double>("> ");
    if (v == 0) {
      return false;
    }

    sum += v;

    return true;
  });

  std::cout << "Sum is "s << sum << "." << std::endl;

  return EXIT_SUCCESS;
}