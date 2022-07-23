#include <chrono>
#include <iostream>
using namespace std::chrono_literals;

namespace gl {

class Timer {

public:
  Timer(){};
  ~Timer(){};

private:
  std::chrono::steady_clock::time_point start_point{};

public:
  // start timer
  void start() { start_point = std::chrono::steady_clock::now(); }

  // get current value in seconds
  float sec() const {
    auto end_point = std::chrono::steady_clock::now();
    std::chrono::duration<float> interval = end_point - start_point;

    return interval.count();
  }

  // get current value in milliseconds
  float millisec() const {
    auto end_point = std::chrono::steady_clock::now();
    std::chrono::duration<float, std::milli> interval = end_point - start_point;

    return interval.count();
  }

public:
  // addition
  template <typename T> friend float operator+(Timer t, const T &val) {
    return t.sec() + val;
  }

  template <typename T> friend float operator+(const T &val, const Timer t) {
    return t.sec() + val;
  }

  // subtraction
  template <typename T> friend float operator-(const Timer t, const T &val) {
    return t.sec() - val;
  }

  template <typename T> friend float operator-(const T &val, const Timer t) {
    return t.sec() - val;
  }

  // Multiplication
  template <typename T> friend float operator*(const Timer t, const T &val) {
    return t.sec() * val;
  }

  template <typename T> friend float operator*(const T &val, const Timer t) {
    return t.sec() * val;
  }

  // Division
  template <typename T> friend float operator/(const Timer t, const T &val) {
    return t.sec() / val;
  }

  template <typename T> friend float operator/(const T &val, const Timer t) {
    return t.sec() / val;
  }
};

} // namespace gl
////////////////////////////////////////////////////////////////////////
// Operator overloading
////////////////////////////////////////////////////////////////////////
