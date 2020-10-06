#ifndef ROTATION_HPP
#define ROTATION_HPP

#include <math.h>
#include "Vector3.h"
#include "Matrix3.h"

Vector3 Rotate(Vector3 point, float angle, unsigned int axis);
Vector3 Rotate(Vector3 point, float angle, Vector3 rotPoint, unsigned int axis);
#endif
