#include "all.h"

template <typename T>
T readFromStdin(std::string prompt) {
  std::cout << prompt;
  T v;
  std::cin >> v;

  return v;
}

int main() {
  int sum = 0;
  int v;
  while ((v = readFromStdin<double>("> ")) != 0) {
    sum += v;
  }
  std::cout << "Sum is "s << sum << "." << std::endl;

  return EXIT_SUCCESS;
}