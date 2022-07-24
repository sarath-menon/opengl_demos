#pragma once
#include <chrono>

// Distance ----------------

// meter
constexpr float operator"" _m(long double x) { return x; }

// centimeter
constexpr float operator"" _cm(long double x) { return x; }

// Angle ----------------

// degree
constexpr float operator"" _deg(long double x) { return x; }

// radian
constexpr float operator"" _rad(long double x) { return x; }

// Time ----------------

// stl::chrono already has several type for time
using std::chrono::hours;
using std::chrono::microseconds;
using std::chrono::milliseconds;
using std::chrono::minutes;
using std::chrono::seconds;

// Weight ----------------

// kilogram
float operator"" _kg(long double x) { return x; }

// gram
float operator"" _g(long double x) { return x; }