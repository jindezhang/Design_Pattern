#include <iostream>
#include "Facade.h"

void CircleF::draw()
{
	std::cout << "Circle draw()" << std::endl;
}

void RectangleF::draw()
{
	std::cout << "Rectangle draw()\n";
}

void SquareF::draw()
{
	std::cout << "Square draw();\n";
}

ShapeMaker::ShapeMaker()
{
	circle = new CircleF();
	rectangle = new RectangleF();
	square = new SquareF();
}

ShapeMaker::~ShapeMaker()
{
	delete circle;
	delete rectangle;
	delete square;
}

void ShapeMaker::drawRectangle()
{
	rectangle->draw();
}

void ShapeMaker::drawSquare()
{
	square->draw();
}

void ShapeMaker::drawCircle()
{
	circle->draw();
}
