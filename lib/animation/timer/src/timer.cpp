#include "timer.hpp"
namespace gl {

void Timer::start() { start_point = std::chrono::steady_clock::now(); }

} // namespace gl