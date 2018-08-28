#include "Proxy.h"
#include <iostream>
RealSubject::RealSubject()
{
	std::cout << "Constructing a RealSubject\n";
}
void RealSubject::Request()
{
	std::cout << "Request By RealSubject\n";
}
Proxy::Proxy()
	: m_pRealSubject( nullptr )
{
	std::cout << "Constructing a Proxy\n";
}
Proxy::~Proxy()
{
	delete m_pRealSubject;
	m_pRealSubject = nullptr;
}
void Proxy::Request()
{
	// ��Ҫʹ��RealSubject ��ʱ���ȥ��ʼ��
	if ( nullptr == m_pRealSubject )
	{
		std::cout << "Request By Proxy\n";
		m_pRealSubject = new RealSubject();
	}
	m_pRealSubject->Request();
}
