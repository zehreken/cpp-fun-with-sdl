#ifndef boid_hpp
#define boid_hpp

#include "triangle.hpp"
#include "primitives.hpp"

class Boid
{
public:
	Boid();
	void update(float deltaTime);
	Vector2 _position;
private:
	float _rotation;
	Triangle _triangle;
	void draw(SDL_Renderer *p_renderer);
	void moveForward();
	void look(Vector2 target);
	Vector2 ruleOne(); // Separation
	Vector2 ruleTwo(); // Allignment
	Vector2 ruleThree(); // Cohesion
};

#endif /* boid_hpp */
