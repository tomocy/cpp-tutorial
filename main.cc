#include "all.h"

template <typename T>
T ReadFromStdin(std::string prompt) {
  std::cout << prompt;
  T v;
  std::cin >> v;

  return v;
}

int ConvertBinToDec(int bin) {
  if (bin < 0) {
    return -ConvertBinToDec(-bin);
  }
  if (bin <= 1) {
    return bin;
  }

  return 2 * ConvertBinToDec(bin / 10) + bin % 10;
}

int main() {
  while (true) {
    auto bin = ReadFromStdin<int>("binary > ");
    auto dec = ConvertBinToDec(bin);
    std::cout << "binary "s << bin << " is decimal "s << dec << "."s
              << std::endl;
  }

  return EXIT_SUCCESS;
}