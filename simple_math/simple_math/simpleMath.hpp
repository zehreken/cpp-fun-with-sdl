#ifndef simpleMath_hpp
#define simpleMath_hpp

#include "primitives.hpp"

float lerp(float a, float b, float w);
float clamp(float x, float lower, float upper);
float smoothStep(float a, float b, float x);
float dotProduct(Vector2 v1, Vector2 v2);

#endif /* simpleMath_hpp */
