#include "rotation.hpp"

Rot::Rot() {}

void Rot::axis(enum axis ax, const float angle) {

  switch (ax) {

  case axis::x:
    R_x(2, 2) = cos(angle);
    R_x(2, 3) = -sin(angle);
    R_x(3, 2) = sin(angle);
    R_x(3, 3) = cos(angle);
    break;
  case axis::y:
    R_x(2, 2) = cos(angle);
    R_x(2, 3) = -sin(angle);
    R_x(3, 2) = sin(angle);
    R_x(3, 3) = cos(angle);
    break;
  case axis::z:
    R_x(2, 2) = cos(angle);
    R_x(2, 3) = -sin(angle);
    R_x(3, 2) = sin(angle);
    R_x(3, 3) = cos(angle);
    break;
  }
}