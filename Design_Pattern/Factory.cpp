#include "Factory.h"

ConcreateCreator::ConcreateCreator()
{
	std::cout << "construction of ConcreateCreator\n";
}

ConcreateCreator::~ConcreateCreator()
{
	std::cout << "destruction of ConcreateCreator\n";
}

Procduct * ConcreateCreator::FactoryMethod()
{
	return new ConcreateProduct();
}

ConcreateProduct::ConcreateProduct()
{
	std::cout << "ConcreateProduct\n";
}

ConcreateProduct::~ConcreateProduct()
{
	std::cout << "~ConcreateProduct\n";
}

void ConcreateProduct::fly()
{
	std::cout << "concreateProduct fly\n";
}

void ConcreateProduct::run()
{
	std::cout << "ConcreateProduct run()\n";
}


void Procduct::fly()
{
	std::cout << "product fly\n";
}


