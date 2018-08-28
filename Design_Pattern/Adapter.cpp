#include "Adapter.h"
#include <iostream>
void Adaptee::SpecialRequest()
{
	std::cout << "SpecialRequest of Adaptee\n";
}
Adapter::Adapter( Adaptee* pAdaptee )
	: m_pAdptee( pAdaptee )
{
}
Adapter::~Adapter()
{
	delete m_pAdptee;
	m_pAdptee = NULL;
}
void Adapter::Request()
{
	std::cout << "Request of Adapter\n";
	m_pAdptee->SpecialRequest();
}
