#ifndef triangle_hpp
#define triangle_hpp

#include <SDL2/SDL.h>
#include "primitives.hpp"

class Triangle
{
public:
	Triangle();
	void setPosition(Vector2 pos);
	void setRotation(float rotation);
	void draw(SDL_Renderer *p_renderer);
	void rotate(float degree); // Rotates around triangle, unit is degree
	void moveForward();
	void look(int mouseX, int mouseY);
private:
	Vector2 _center;
	float _rotation;
	Vector2 _direction;
	Vector2 _a;
	Vector2 _b;
	Vector2 _c;
	float _rad_x;
	float _rad_y;
	float _rad_z;
	void calculateCorners();
};

void triangle_test();

#endif /* triangle_hpp */
