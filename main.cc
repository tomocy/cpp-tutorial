#include <array>

#include "all.h"
#include "uncopyable.h"
#include "unmovable.h"

int main() {
  Uncopyable a;

  // auto b = a;

  Unmovable c;

  // auto z = Unmovable(std::move(c));

  return EXIT_SUCCESS;
}