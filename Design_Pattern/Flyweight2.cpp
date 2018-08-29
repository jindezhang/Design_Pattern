#include "Flyweight2.h"

STATE Shape::GetColorState()
{
	return m_color;
}

ShapeFactory::~ShapeFactory()
{
	for_each( m_shape.begin(), m_shape.end(), []( Shape* item ){
		delete ( item ); } );
	m_shape.clear();
}

Shape * ShapeFactory::GetShape( const STATE & state )
{
	auto iter = std::find_if( m_shape.begin(), m_shape.end(), [ state ]( Shape* item )->bool{
		return item->GetColorState() == state;
	} );
	/*--����---
	//STL�㷨�������ص���ָ��洢�����͵ĵ�������
	Shape * tmp = std::find_if( m_shape.begin(), m_shape.end(), [ state ]( Shape* item )->bool{
		return item->GetColorState() == state;
	*/
	if ( iter != m_shape.end() )
	{
		std::cout << "***The color:" << state << " already exits" << std::endl;
		return *iter;
	}	
	else
	{
		std::cout << "^^^Create color:" << state << std::endl;
		Shape * tmp = new Circle( state );
		m_shape.push_back( tmp );
		return tmp;
	}

}

Circle::Circle( const STATE & state ):Shape(state)
{
	this->color = state;
}

void Circle::setX(int x)
{
	this->x = x;
}

void Circle::setY( int y )
{
	this->y = y;
}

void Circle::setRadius( int radius )
{
	this->radius = radius;
}

void Circle::Draw()
{
	
	std::cout << "Circle: Draw() [Color : " << color
		<< ", x :" << x << ", y :" << y << ", radius :" << radius << std::endl;
}
