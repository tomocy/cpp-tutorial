#ifndef UNMOVABLE_H
#define UNMOVABLE_H

class Unmovable {
 public:
  Unmovable();

  Unmovable(const Unmovable&) = delete;

  Unmovable& operator=(const Unmovable&) = delete;
};

#endif