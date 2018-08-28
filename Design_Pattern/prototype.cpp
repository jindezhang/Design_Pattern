#include "prototype.h"
#include <iostream>

ConcreatePrototype1::ConcreatePrototype1()
{
	std::cout << "construction of ConcreatePrototype1\n";
}
ConcreatePrototype1::~ConcreatePrototype1()
{
	std::cout << "destruction of ConcreatePrototype1\n";
}
ConcreatePrototype1::ConcreatePrototype1( const ConcreatePrototype1& )
{
	std::cout << "copy construction of ConcreatePrototype1\n";
}
Prototype* ConcreatePrototype1::Clone()
{
	return new ConcreatePrototype1( *this );
}
ConcreatePrototype2::ConcreatePrototype2()
{
	std::cout << "construction of ConcreatePrototype2\n";
}
ConcreatePrototype2::~ConcreatePrototype2()
{
	std::cout << "destruction of ConcreatePrototype2\n";
}
ConcreatePrototype2::ConcreatePrototype2( const ConcreatePrototype2& )
{
	std::cout << "copy construction of ConcreatePrototype2\n";
}
Prototype* ConcreatePrototype2::Clone()
{
	return new ConcreatePrototype2( *this );
}