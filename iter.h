#ifndef ITER_H
#define ITER_H

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
#endif