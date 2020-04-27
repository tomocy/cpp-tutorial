#include "all.h"

double CalculateBMI(double height, double weight) {
  return weight / (height * height);
}

std::string DiagnoseBMI(double bmi) {
  if (bmi >= 30) {
    return "Overweight"s;
  }
  if (bmi < 18.5) {
    return "Underweight"s;
  }

  return "Normal"s;
}

template <typename T>
T readFromStdin(std::string prompt) {
  std::cout << prompt << "> "s;
  T v;
  std::cin >> v;

  return v;
}

int main() {
  auto height = readFromStdin<double>("height(m)"s);
  auto weight = readFromStdin<double>("weight(kg)"s);
  auto bmi = CalculateBMI(height, weight);
  auto status = DiagnoseBMI(bmi);

  std::cout << "Your BMI is "s << bmi << "."s << std::endl;
  std::cout << "This BMI is generally considered "s << status << "."s
            << std::endl;

  return EXIT_SUCCESS;
}