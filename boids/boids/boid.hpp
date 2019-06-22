#ifndef boid_hpp
#define boid_hpp

#include "triangle.hpp"
#include "primitives.hpp"

class Boid
{
public:
	Boid();
	void update(SDL_Renderer *p_renderer, float deltaTime, int mouseX, int mouseY);
	Vector2 _position; // make this private
private:
	float _rotation;
	Triangle _triangle;
	void moveForward();
	void look(Vector2 target);
	Vector2 ruleOne(); // Separation
	Vector2 ruleTwo(); // Allignment
	Vector2 ruleThree(); // Cohesion
};

#endif /* boid_hpp */
