
class ShapeF
{
public:
	virtual ~ShapeF(){};
	virtual void draw() = 0;
};

class CircleF
	:public ShapeF
{
public:
	void draw();
	virtual ~CircleF(){};
};

class RectangleF
	:public ShapeF
{
public:
	void draw();
	virtual ~RectangleF(){}


};

class SquareF
	:public ShapeF
{
public:
	void draw();
	virtual ~SquareF(){};
};

class ShapeMaker
{
public:
	ShapeMaker();
	~ShapeMaker();
	void drawRectangle();
	void drawSquare();
	void drawCircle();
private:
	ShapeF* circle;
	ShapeF* rectangle;
	ShapeF* square;
};
#pragma once
