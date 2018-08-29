#include "ChainOfResponsibility.h"
#include <iostream>
Handler::Handler( Handler *pSuccessor /* = NULL*/ )
	: m_pSuccessor( pSuccessor )
{
}
Handler::~Handler()
{
	std::cout << "~Handler:\n";
	delete m_pSuccessor;
	m_pSuccessor = nullptr;
}
void ConcreateHandler1::HandleRequset()
{
	if ( nullptr != m_pSuccessor )
	{
		m_pSuccessor->HandleRequset();
	}
	else
	{
		std::cout << "HandleRequset by ConcreateHandler1\n";
	}
}
void ConcreateHandler2::HandleRequset()
{
	if ( nullptr != m_pSuccessor )
	{
		m_pSuccessor->HandleRequset();
	}
	else
	{
		std::cout << "HandleRequset by ConcreateHandler2\n";
	}
}
