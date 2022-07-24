#pragma once
#include <chrono>

// Distance ----------------

// meter
inline constexpr float operator"" _m(long double x) { return x; }

// centimeter
inline constexpr float operator"" _cm(long double x) { return x; }

// Angle ----------------

// degree
inline constexpr float operator"" _deg(long double x) { return x; }

// radian
inline constexpr float operator"" _rad(long double x) { return x; }

// Time ----------------

// stl::chrono already has several type for time
using std::chrono::hours;
using std::chrono::microseconds;
using std::chrono::milliseconds;
using std::chrono::minutes;
using std::chrono::seconds;

// Weight ----------------

// kilogram
inline float operator"" _kg(long double x) { return x; }

// gram
inline float operator"" _g(long double x) { return x; }