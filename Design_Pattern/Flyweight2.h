#include <string>
#include <list>
#include <iostream>
#include <algorithm>

typedef std::string STATE;
class Shape
{
public:
	virtual ~Shape(){
		std::cout << "FREE:" << m_color<<std::endl;
	}
	STATE GetColorState();
	virtual void Draw() = 0;
protected:
	Shape( const STATE& state )
		:m_color( state )
	{
	}

private:
	STATE m_color;
};

class ShapeFactory
{
public:
	ShapeFactory(){}
	~ShapeFactory();
	Shape* GetShape(const STATE& state);

private:
	std::list<Shape*> m_shape;
};

class Circle
	:public Shape
{
public:
	Circle( const STATE& state );
	void setX(int x);
	void setY(int y);
	void setRadius(int radius);
	void Draw();
private:
	int x;
	int y;
	int radius;
	std::string color;
};
#pragma once
