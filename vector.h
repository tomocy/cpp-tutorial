#ifndef VECTOR_H
#define VECTOR_H

#include "all.h"

template <typename T, typename Alloc = std::allocator<T>>
class Vector {
 public:
  using value_t = T;
  using pointer = value_t*;
  using const_pointer = const pointer;
  using reference = value_t&;
  using const_reference = const reference;
  using allocator_t = Alloc;

  Vector();

  Vector(std::size_t);

  Vector(const allocator_t&);

  ~Vector();

  std::size_t size() const noexcept;

  std::size_t capacity() const noexcept;

  void resize(std::size_t);

  void reserve(std::size_t);

  pointer begin() noexcept;

  pointer end() noexcept;

  std::reverse_iterator<pointer> rbegin() noexcept;

  std::reverse_iterator<pointer> rend() noexcept;

 private:
  using allocator_traits = std::allocator_traits<allocator_t>;

  void construct(pointer);

  void construct(pointer, value_t&&);

  void clear() noexcept;

  void destroyUntil(std::reverse_iterator<pointer>);

  void destroy(pointer);

  pointer allocate(std::size_t);

  void deallocate();

  pointer first;
  pointer last;
  pointer reserved_last;
  allocator_t alloc;
};

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector() : Vector(allocator_t()) {}

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(std::size_t n) : Vector(allocator_t()) {
  resize(n);
}

template <typename T, typename Alloc>
Vector<T, Alloc>::Vector(const allocator_t& alloc)
    : first(nullptr), last(nullptr), reserved_last(nullptr), alloc(alloc) {}

template <typename T, typename Alloc>
Vector<T, Alloc>::~Vector() {
  clear();
  deallocate();
}

template <typename T, typename Alloc>
std::size_t Vector<T, Alloc>::size() const noexcept {
  return last - first;
}

template <typename T, typename Alloc>
std::size_t Vector<T, Alloc>::capacity() const noexcept {
  return reserved_last - first;
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::resize(std::size_t n) {
  if (n == size()) {
    return;
  }

  if (n < size()) {
    auto diff = size() - n;
    destroyUntil(rend() - diff);
    return;
  }

  reserve(n);
  for (; last != reserved_last; ++last) {
    construct(last);
  }
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::reserve(std::size_t n) {
  if (n <= capacity()) {
    return;
  }

  auto old = *this;
  first = allocate(n);
  last = first;
  reserved_last = first + n;

  for (auto iter = old.begin(); iter != old.end(); ++iter, ++last) {
    construct(last, std::move(*iter));
  }

  old.clear();
}

template <typename T, typename Alloc>
typename Vector<T, Alloc>::pointer Vector<T, Alloc>::begin() noexcept {
  return first;
}

template <typename T, typename Alloc>
typename Vector<T, Alloc>::pointer Vector<T, Alloc>::end() noexcept {
  return last;
}

template <typename T, typename Alloc>
std::reverse_iterator<typename Vector<T, Alloc>::pointer>
Vector<T, Alloc>::rbegin() noexcept {
  return std::reverse_iterator<pointer>(last);
}

template <typename T, typename Alloc>
std::reverse_iterator<typename Vector<T, Alloc>::pointer>
Vector<T, Alloc>::rend() noexcept {
  return std::reverse_iterator<pointer>(first);
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::construct(pointer p) {
  allocator_traits::construct(alloc, p);
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::construct(pointer p, value_t&& v) {
  allocator_traits::construct(alloc, p, std::move(v));
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::clear() noexcept {
  destroyUntil(rend());
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::destroyUntil(std::reverse_iterator<pointer> last) {
  for (auto iter = rbegin(); iter != last; ++iter, --this->last) {
    destroy(&*iter);
  }
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::destroy(pointer p) {
  allocator_traits::destroy(alloc, p);
}

template <typename T, typename Alloc>
typename Vector<T, Alloc>::pointer Vector<T, Alloc>::allocate(std::size_t n) {
  return allocator_traits::allocate(alloc, n);
}

template <typename T, typename Alloc>
void Vector<T, Alloc>::deallocate() {
  allocator_traits::deallocate(alloc, first, capacity());
}

#endif
