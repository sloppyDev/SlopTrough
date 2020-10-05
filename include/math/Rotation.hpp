#ifndef ROTATION_HPP
#define ROTATION_HPP

#include <math.h>
#include "Vector3.hpp"
#include "Matrix3.hpp"

Vector3 Rotate(Vector3 point, float angle, unsigned int axis);
// Vector3 Rotate(Vector3 point, Vector3 rotPoint, unsigned int axis);

#endif
