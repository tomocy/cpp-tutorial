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

template <typename Array>
struct ConstIter {
  ConstIter(const Array& arr, std::size_t i) : arr(arr), i(i) {}

  ConstIter(const Iter<Array> iter) : arr(iter.arr), i(iter.i) {}

  typename Array::const_reference operator*() const { return arr[i]; }

  ConstIter& operator++() {
    ++i;
    return *this;
  }

  ConstIter operator++(int) {
    auto copied = *this;
    ++*this;
    return copied;
  }

  ConstIter& operator+=(std::size_t n) {
    i += n;
    return *this;
  }

  ConstIter operator+(std::size_t n) const {
    auto copied = *this;
    copied += n;
    return copied;
  }

  ConstIter& operator--() {
    --i;
    return *this;
  }

  ConstIter operator--(int) {
    auto copied = *this;
    --*this;
    return copied;
  }

  bool operator==(const ConstIter& right) {
    return i == right.i && arr[i] == *right;
  }

  bool operator!=(const ConstIter& right) { return !(*this == right); }

  bool operator<(const ConstIter& right) { return i < right.i; }

  bool operator<=(const ConstIter& right) { return i <= right.i; }

  bool operator>(const ConstIter& right) { return i > right.i; }

  bool operator>=(const ConstIter& right) { return i >= right.i; }

  typename Array::const_reference operator[](std::size_t n) const {
    return *(*this + n);
  }

  const Array& arr;
  std::size_t i;
};

template <typename T, std::size_t N>
struct Array {
  using value_type = T;
  using reference = value_type&;
  using const_reference = value_type const&;

  reference operator[](std::size_t i) { return data[i]; }
  const_reference operator[](std::size_t i) const { return data[i]; }

  std::size_t size() const { return N; }

  Iter<Array> begin() { return Iter<Array>(*this, 0); }

  ConstIter<Array> begin() const { return ConstIter<Array>(*this, 0); }

  Iter<Array> end() { return Iter<Array>(*this, N); }

  ConstIter<Array> end() const { return ConstIter<Array>(*this, N); }

  reference front() { return data[0]; }
  const reference front() const { return data[0]; }

  reference back() { return data[N - 1]; }
  const reference back() const { return data[N - 1]; }

  value_type data[N];
};

int main() {
  auto a = Array<int, 20>{5, 4, 3, 2, 1};
  for (auto iter = a.begin(); iter != a.end(); ++iter) {
    auto original = *iter;
    *iter = 0;
    std::cout << "array: " << *iter << std::endl;
    *iter = original;
  }

  const auto b = a;
  for (auto iter = b.begin(); iter != b.end(); ++iter) {
    // *iter = 0;
    std::cout << "const array: " << *iter << std::endl;
    // *iter = original;
  }

  return EXIT_SUCCESS;
}