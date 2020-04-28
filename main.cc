#include "all.h"

template <typename T>
T ReadFromStdin(std::string prompt) {
  std::cout << prompt;
  T v;
  std::cin >> v;

  return v;
}

std::vector<int> ReadIntsFromStdin(std::string prompt) {
  std::vector<int> vs;
  int v;
  while ((v = ReadFromStdin<int>(prompt)) != 0) {
    vs.push_back(v);
  }

  return vs;
}

void SortWithSelection(std::vector<int>& vs) {
  for (size_t i = 0; i < vs.size(); ++i) {
    auto min = i;
    for (size_t j = i + 1; j < vs.size(); ++j) {
      if (vs.at(min) <= vs.at(j)) {
        continue;
      }

      min = j;
    }

    auto tmp = vs.at(i);
    vs.at(i) = vs.at(min);
    vs.at(min) = tmp;
  }
}

template <typename T>
void PrintWithSep(std::vector<T> vs, std::string sep) {
  for (size_t i = 0; i < vs.size(); ++i) {
    std::cout << vs.at(i);
    if (i != vs.size() - 1) {
      std::cout << sep;
    }
  }
}

int main() {
  auto vs = ReadIntsFromStdin("integer > "s);

  PrintWithSep<int>(vs, ", "s);
  std::cout << " is sorted ";

  SortWithSelection(vs);

  PrintWithSep<int>(vs, ", "s);
  std::cout << "."s << std::endl;

  return EXIT_SUCCESS;
}