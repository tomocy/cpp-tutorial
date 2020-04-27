#include "all.h"

template <typename T>
T ReadFromStdin(std::string prompt) {
  std::cout << prompt;
  T v;
  std::cin >> v;

  return v;
}

class Base {
 public:
  Base(int val) : val_(val) {}

  std::string String() const {
    switch (val_) {
      case 2:
        return "binary";
      case 10:
        return "decimal";
      default:
        return "";
    }
  }

  int Value() const { return val_; }

 private:
  int val_;
};

int ConvertBinToDec(int src) {
  if (src < 0) {
    return -ConvertBinToDec(-src);
  }
  if (src < 2) {
    return src;
  }

  return 2 * ConvertBinToDec(src / 10) + src % 10;
}

int ConvertDecToBin(int src) {
  if (src < 0) {
    return -ConvertDecToBin(-src);
  }

  std::function<std::string(std::string, int)> remainders =
      [&remainders](std::string joined, int src) {
        auto q = src / 2, r = src % 2;
        joined += std::to_string(r);
        if (q == 0) {
          return joined;
        }

        return remainders(joined, q);
      };
  auto joined = remainders(""s, src);
  std::reverse(joined.begin(), joined.end());

  std::cout << joined << std::endl;

  return std::stoi(joined);
}

void ConvertBaseFromStdin(Base from, Base to) {
  auto src = ReadFromStdin<int>(from.String() + " > "s);
  int converted = [from, to, src]() {
    if (from.Value() == 2 && to.Value() == 10) {
      return ConvertBinToDec(src);
    }
    if (from.Value() == 10 && to.Value() == 2) {
      return ConvertDecToBin(src);
    }

    return 0;
  }();

  std::cout << from.String() << " "s << src << " is "s << to.String() << " "s
            << converted << "."s << std::endl;
}

int main() {
  std::cout << "convert bases" << std::endl;
  std::cout << "SIGINT to quit" << std::endl;
  auto from = Base(ReadFromStdin<int>("from > ")),
       to = Base(ReadFromStdin<int>("to > "));
  while (true) {
    ConvertBaseFromStdin(from, to);
  }

  return EXIT_SUCCESS;
}