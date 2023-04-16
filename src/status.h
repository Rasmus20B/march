#pragma once

#include <bitset>
#include <iostream>


namespace march {
enum Status {
  STATUS_ALIVE,
  STATUS_DEAD,
  STATUS_COLD,
  STATUS_FREEZING,
  STATUS_HUNGRY,
  STATUS_STARVING,
  STATUS_LEFT_BEHIND,
  STATUS_SIZE,
};

class StatFlags {
public:
  explicit StatFlags(std::initializer_list<march::Status> flags) {
    for(auto f : flags) {
      bs.set(static_cast<unsigned>(f));
    }
  }
  StatFlags() = default;
  int test(march::Status f) {
    return bs.test(static_cast<unsigned>(f));
  }
  void flip(march::Status f) {
    bs.flip(f);
  }
  void printFlags() {
    std::cout << bs.to_ulong() << ", ";
  }
  void zero() {
    bs.reset();
  }
  void dead() {
    bs.reset();
    bs.set(STATUS_DEAD);
  }
private:
    std::bitset<static_cast<size_t>(STATUS_SIZE)> bs;
};
}
