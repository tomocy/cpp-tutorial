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

  typename Array::iterator& operator-=(std::size_t n);

  typename Array::iterator operator-(std::size_t n) const;

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
typename Array::iterator& Iter<Array>::operator-=(std::size_t n) {
  i -= n;
  return *this;
}

template <typename Array>
typename Array::iterator Iter<Array>::operator-(std::size_t n) const {
  auto copied = *this;
  copied -= n;
  return copied;
}

template <typename Array>
bool Iter<Array>::operator==(const Iter& right) {
  return i == right.i && **this == *(const_cast<Iter&>(right));
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
  ConstIter(const Array& arr, std::size_t i);

  ConstIter(const typename Array::iterator iter);

  typename Array::const_reference operator*() const;

  typename Array::const_reference operator[](std::size_t n) const;

  typename Array::const_iterator& operator++();

  typename Array::const_iterator operator++(int);

  typename Array::const_iterator& operator+=(std::size_t n);

  typename Array::const_iterator operator+(std::size_t n) const;

  typename Array::const_iterator& operator--();

  typename Array::const_iterator operator--(int);

  typename Array::const_iterator& operator-=(std::size_t n);

  typename Array::const_iterator operator-(std::size_t n) const;

  bool operator==(const ConstIter& right);

  bool operator!=(const ConstIter& right);

  bool operator<(const ConstIter& right);

  bool operator<=(const ConstIter& right);

  bool operator>(const ConstIter& right);

  bool operator>=(const ConstIter& right);

  const Array& arr;
  std::size_t i;
};

template <typename Array>
ConstIter<Array>::ConstIter(const Array& arr, std::size_t i) : arr(arr), i(i) {}

template <typename Array>
ConstIter<Array>::ConstIter(const typename Array::iterator iter)
    : arr(iter.arr), i(iter.i) {}

template <typename Array>
typename Array::const_reference ConstIter<Array>::operator*() const {
  return arr[i];
}

template <typename Array>
typename Array::const_reference ConstIter<Array>::operator[](
    std::size_t n) const {
  return *(*this + n);
}

template <typename Array>
typename Array::const_iterator& ConstIter<Array>::operator++() {
  ++i;
  return *this;
}

template <typename Array>
typename Array::const_iterator ConstIter<Array>::operator++(int) {
  auto copied = *this;
  ++*this;
  return copied;
}

template <typename Array>
typename Array::const_iterator& ConstIter<Array>::operator+=(std::size_t n) {
  i += n;
  return *this;
}

template <typename Array>
typename Array::const_iterator ConstIter<Array>::operator+(
    std::size_t n) const {
  auto copied = *this;
  copied += n;
  return copied;
}

template <typename Array>
typename Array::const_iterator& ConstIter<Array>::operator--() {
  --i;
  return *this;
}

template <typename Array>
typename Array::const_iterator ConstIter<Array>::operator--(int) {
  auto copied = *this;
  --*this;
  return copied;
}

template <typename Array>
typename Array::const_iterator& ConstIter<Array>::operator-=(std::size_t n) {
  i -= n;
  return *this;
}

template <typename Array>
typename Array::const_iterator ConstIter<Array>::operator-(
    std::size_t n) const {
  auto copied = *this;
  copied -= n;
  return copied;
}

template <typename Array>
bool ConstIter<Array>::operator==(const ConstIter& right) {
  return i == right.i && **this == *right;
}

template <typename Array>
bool ConstIter<Array>::operator!=(const ConstIter& right) {
  return !(*this == right);
}

template <typename Array>
bool ConstIter<Array>::operator<(const ConstIter& right) {
  return i < right.i;
}

template <typename Array>
bool ConstIter<Array>::operator<=(const ConstIter& right) {
  return i <= right.i;
}

template <typename Array>
bool ConstIter<Array>::operator>(const ConstIter& right) {
  return i > right.i;
}

template <typename Array>
bool ConstIter<Array>::operator>=(const ConstIter& right) {
  return i >= right.i;
}

template <typename T, std::size_t N>
struct Array {
  using value = T;
  using reference = value&;
  using const_reference = value const&;
  using iterator = Iter<Array>;
  using const_iterator = ConstIter<Array>;

  reference operator[](std::size_t i);
  const_reference operator[](std::size_t i) const;

  std::size_t size() const;

  iterator begin();

  const_iterator begin() const;

  iterator end();

  const_iterator end() const;

  reference front();
  const_reference front() const;

  reference back();
  const_reference back() const;

  value data[N];
};

template <typename T, std::size_t N>
typename Array<T, N>::reference Array<T, N>::operator[](std::size_t i) {
  return data[i];
}

template <typename T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::operator[](
    std::size_t i) const {
  return data[i];
}

template <typename T, std::size_t N>
std::size_t Array<T, N>::size() const {
  return N;
}

template <typename T, std::size_t N>
typename Array<T, N>::iterator Array<T, N>::begin() {
  return iterator(*this, 0);
}

template <typename T, std::size_t N>
typename Array<T, N>::const_iterator Array<T, N>::begin() const {
  return const_iterator(*this, 0);
}

template <typename T, std::size_t N>
typename Array<T, N>::iterator Array<T, N>::end() {
  return iterator(*this, N);
}

template <typename T, std::size_t N>
typename Array<T, N>::const_iterator Array<T, N>::end() const {
  return const_iterator(*this, N);
}

template <typename T, std::size_t N>
typename Array<T, N>::reference Array<T, N>::front() {
  return data[0];
}

template <typename T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::front() const {
  return data[0];
}

template <typename T, std::size_t N>
typename Array<T, N>::reference Array<T, N>::back() {
  return data[N - 1];
}

template <typename T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::back() const {
  return data[N - 1];
}

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