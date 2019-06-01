#ifndef simpleMath_hpp
#define simpleMath_hpp

#include "primitives.hpp"

const float PI = 3.14159265359;
const float RAD_TO_DEG = 180.0 / PI;
const float DEG_TO_RAD = PI / 180.0;

float lerp(float a, float b, float w);
float clamp(float x, float lower, float upper);
float smoothStep(float a, float b, float x);
float dotProduct(Vector2 v1, Vector2 v2);

#endif /* simpleMath_hpp */
