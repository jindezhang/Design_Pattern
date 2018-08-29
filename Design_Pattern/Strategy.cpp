#include "Strategy.h"
#include <iostream>

int OperationAdd::doOperation( int num1, int num2 )
{

	return num1 + num2;
}

int OperationSub::doOperation( int num1, int num2 )
{
	return num1 - num2;
}

Context::~Context()
{
	std::cout << "~Context\n";
	delete state;
	state = nullptr;
}

void Context::setStategy( Stategy * state )
{
	delete this->state;
	this->state = state;
}

int Context::executeStategy( int num1, int num2 )
{
	return state->doOperation(num1,num2);
}
