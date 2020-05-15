#include "all.h"

template <typename Array>
struct Iter {
  Iter(Array& arr, std::size_t i);

  typename Array::reference operator*();

  typename Array::reference operator[](std::size_t n) const;

  typename Array::iterator& operator++();

  typename Array::iterator operator++(int);

  typename Array::iterator& operator+=(std::size_t n);

  typename Array::iterator operator+(std::size_t n) const;

  typename Array::iterator& operator--();

  typename Array::iterator operator--(int);

  bool operator==(const Iter& right);

  bool operator!=(const Iter& right);

  bool operator<(const Iter& right) const;

  bool operator<=(const Iter& right) const;

  bool operator>(const Iter& right) const;

  bool operator>=(const Iter& right) const;

  Array& arr;
  std::size_t i;
};

template <typename Array>
Iter<Array>::Iter(Array& arr, std::size_t i) : arr(arr), i(i) {}

template <typename Array>
typename Array::reference Iter<Array>::operator*() {
  return arr[i];
}

template <typename Array>
typename Array::reference Iter<Array>::operator[](std::size_t n) const {
  return *(*this + n);
}

template <typename Array>
typename Array::iterator& Iter<Array>::operator++() {
  ++i;
  return *this;
}

template <typename Array>
typename Array::iterator Iter<Array>::operator++(int) {
  auto copied = *this;
  ++*this;
  return copied;
}

template <typename Array>
typename Array::iterator& Iter<Array>::operator+=(std::size_t n) {
  i += n;
  return *this;
}

template <typename Array>
typename Array::iterator Iter<Array>::operator+(std::size_t n) const {
  auto copied = *this;
  copied += n;
  return copied;
}

template <typename Array>
typename Array::iterator& Iter<Array>::operator--() {
  --i;
  return *this;
}

template <typename Array>
typename Array::iterator Iter<Array>::operator--(int) {
  auto copied = *this;
  --*this;
  return copied;
}

template <typename Array>
bool Iter<Array>::operator==(const Iter& right) {
  return i == right.i && arr[i] == right.arr[right.i];
}

template <typename Array>
bool Iter<Array>::operator!=(const Iter& right) {
  return !(*this == right);
}

template <typename Array>
bool Iter<Array>::operator<(const Iter& right) const {
  return i < right.i;
}

template <typename Array>
bool Iter<Array>::operator<=(const Iter& right) const {
  return i <= right.i;
}

template <typename Array>
bool Iter<Array>::operator>(const Iter& right) const {
  return i > right.i;
}

template <typename Array>
bool Iter<Array>::operator>=(const Iter& right) const {
  return i >= right.i;
}

template <typename Array>
struct ConstIter {
  ConstIter(const Array& arr, std::size_t i) : arr(arr), i(i) {}

  ConstIter(const typename Array::iterator iter) : arr(iter.arr), i(iter.i) {}

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
  using value = T;
  using reference = value&;
  using const_reference = value const&;
  using iterator = Iter<Array>;
  using const_iterator = ConstIter<Array>;

  reference operator[](std::size_t i) { return data[i]; }
  const_reference operator[](std::size_t i) const { return data[i]; }

  std::size_t size() const { return N; }

  iterator begin() { return iterator(*this, 0); }

  const_iterator begin() const { return const_iterator(*this, 0); }

  iterator end() { return iterator(*this, N); }

  const_iterator end() const { return const_iterator(*this, N); }

  reference front() { return data[0]; }
  const_reference front() const { return data[0]; }

  reference back() { return data[N - 1]; }
  const_reference back() const { return data[N - 1]; }

  value data[N];
};

int main() {
  auto a = Array<int, 20>{5, 4, 3, 2, 1};
  const auto b = a;

  for (auto iter = a.begin(); iter != a.end(); ++iter) {
    std::cout << *iter << std::endl;
  }
  for (auto iter = b.begin(); iter != b.end(); ++iter) {
    std::cout << *iter << std::endl;
  }

  return EXIT_SUCCESS;
}