#ifndef ARRAY_H
#define ARRAY_H

#include "all.h"
#include "const_iter.h"
#include "iter.h"

template <typename T, std::size_t N>
struct Array {
  using value = T;
  using reference = value &;
  using const_reference = const reference;
  using iterator = Iter<Array>;
  using const_iterator = ConstIter<Array>;

  reference operator[](std::size_t i);
  const_reference operator[](std::size_t i) const;

  std::size_t size() const;

  reference at(std::size_t i);
  const_reference at(std::size_t i) const;

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
typename Array<T, N>::reference Array<T, N>::at(std::size_t i) {
  if (i >= size()) {
    throw std::out_of_range(std::to_string(i));
  }

  return (*this)[i];
}

template <typename T, std::size_t N>
typename Array<T, N>::const_reference Array<T, N>::at(std::size_t i) const {
  return at(i);
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

#endif