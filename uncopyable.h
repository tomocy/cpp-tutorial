#ifndef UNCOPYABLE_H
#define UNCOPYABLE_H

class Uncopyable {
 public:
  Uncopyable();

  Uncopyable(const Uncopyable&) = delete;

  Uncopyable& operator=(const Uncopyable&) = delete;
};

#endif