#ifndef primitives_hpp
#define primitives_hpp

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	float getX();
	float getY();
	float getMagnitude();
	Vector2 getNormalized();
private:
	float _x;
	float _y;
	float _magnitude;
};

void primitives_test();

#endif /* primitives_hpp */
