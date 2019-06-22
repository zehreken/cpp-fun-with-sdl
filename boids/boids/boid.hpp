#ifndef boid_hpp
#define boid_hpp

#include "triangle.hpp"
#include "primitives.hpp"

class Boid
{
public:
	Boid();
	void update(float deltaTime);
private:
	Triangle triangle;
	Vector2 ruleOne(); // Separation
	Vector2 ruleTwo(); // Allignment
	Vector2 ruleThree(); // Cohesion
};

#endif /* boid_hpp */
