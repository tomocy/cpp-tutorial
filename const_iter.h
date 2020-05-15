#ifndef CONST_ITER_H
#define CONST_ITER_H

#include "all.h"

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

#endif