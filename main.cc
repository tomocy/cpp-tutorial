#include "all.h"

template <typename Array>
struct Iter {
  Iter(Array& arr, std::size_t i) : arr(arr), i(i) {}

  typename Array::reference operator*() { return arr[i]; }

  Iter& operator++() {
    ++i;
    return *this;
  }

  Iter operator++(int) {
    auto copied = *this;
    ++*this;
    return copied;
  }

  Iter& operator--() {
    --i;
    return *this;
  }

  Iter operator--(int) {
    auto copied = *this;
    --*this;
    return copied;
  }

  bool operator==(const Iter& right) {
    return i == right.i && arr[i] == right.arr[right.i];
  }

  bool operator!=(const Iter& right) { return !(*this == right); }

  Iter& operator+=(std::size_t n) {
    i += n;
    return *this;
  }

  Iter operator+(std::size_t n) const {
    auto copied = *this;
    copied += n;
    return copied;
  }

  typename Array::reference operator[](std::size_t n) const {
    return *(*this + n);
  }

  bool operator<(const Iter& right) const { return i < right.i; }

  bool operator<=(const Iter& right) const { return i <= right.i; }

  bool operator>(const Iter& right) const { return i > right.i; }

  bool operator>=(const Iter& right) const { return i >= right.i; }

  Array& arr;
  std::size_t i;
};

template <typename T, std::size_t N>
struct Array {
  using value_type = T;
  using reference = value_type&;

  reference operator[](std::size_t i) { return data[i]; }
  const reference operator[](std::size_t i) const { return data[i]; }

  std::size_t size() const { return N; }

  Iter<Array> begin() { return Iter<Array>(*this, 0); }

  Iter<Array> end() { return Iter<Array>(*this, N); }

  reference front() { return data[0]; }
  const reference front() const { return data[0]; }

  reference back() { return data[N - 1]; }
  const reference back() const { return data[N - 1]; }

  value_type data[N];
};

int main() {
  auto a = Array<int, 20>{5, 4, 3, 2, 1};
  for (std::size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << std::endl;
  }

  auto begin = a.begin();
  std::cout << "begin: " << *begin << std::endl;
  auto second = ++begin;
  std::cout << "second: " << *second << std::endl;
  auto third = second;
  third++;
  std::cout << "third: " << *third << std::endl;
  auto secondBackFromThird = --third;
  std::cout << "second back from third: " << *secondBackFromThird << std::endl;
  auto firstBackFromSecond = secondBackFromThird;
  firstBackFromSecond--;
  std::cout << "first back from second:" << *firstBackFromSecond << std::endl;
  auto end = a.end();
  std::cout << "end: " << *end << std::endl;

  std::for_each(std::begin(a), std::end(a),
                [](auto x) { std::cout << x << std::endl; });

  auto b = Array<int, 20>{1, 2, 3, 4, 5};
  std::cout << "a.begin == b.begin: " << (a.begin() == b.begin()) << std::endl;

  auto iterB = b.begin();
  std::cout << "iter b: " << *iterB << std::endl;
  iterB += 3;
  std::cout << "iter b after += 3: " << *iterB << std::endl;
  auto fourthB = iterB + 1;
  std::cout << "fourth b: " << *fourthB << std::endl;
  std::cout << "17th b: " << b.begin()[17] << std::endl;

  auto x = b.begin();
  auto y = b.begin() + 1;
  std::cout << "x < y: " << (x < y) << std::endl;
  std::cout << "x <= y: " << (x <= y) << std::endl;
  std::cout << "x += 2" << std::endl;
  x += 2;
  std::cout << "x > y: " << (x > y) << std::endl;
  std::cout << "x >= y: " << (x >= y) << std::endl;

  const auto front = a.front();
  const auto back = a.back();
  std::cout << "front: " << front << std::endl;
  std::cout << "back: " << back << std::endl;

  return EXIT_SUCCESS;
}