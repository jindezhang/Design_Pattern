#include "Observer.h"
#include <iostream>
#include <algorithm>
/* --------------------------------------------------------------------
| SubjectOb 类成员函数的实现
|
----------------------------------------------------------------------*/
void SubjectOb::Attach( Observer *pObserver )
{
	std::cout << "Attach an Observer\n";
	m_ListObserver.push_back( pObserver );
}
void SubjectOb::Detach( Observer *pObserver )
{
	std::list<Observer*>::iterator iter;
	iter = std::find( m_ListObserver.begin(), m_ListObserver.end(), pObserver );
	if ( m_ListObserver.end() != iter )
	{
		m_ListObserver.erase( iter );
	}
	std::cout << "Detach an Observer\n";
}
void SubjectOb::Notify()
{
	std::cout << "Notify Observers's State\n";
	std::list<Observer*>::iterator iter1, iter2;
	for ( iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end();
		iter1 != iter2;
		++iter1 )
	{
		( *iter1 )->Update( this );
	}
}
void SubjectOb::SetState( STATE nState )
{
	std::cout << "SetState By SubjectOb\n";
	m_nSubjectState = nState;
}
STATE SubjectOb::GetState()
{
	std::cout << "GetState By SubjectOb\n";
	return m_nSubjectState;
}
SubjectOb::~SubjectOb()
{
	std::list<Observer*>::iterator iter1, iter2, temp;
	for ( iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end();
		iter1 != iter2;
		)
	{
		temp = iter1;
		++iter1;
		delete ( *temp );
	}
	m_ListObserver.clear();
}
/* --------------------------------------------------------------------
| ConcreateSubject类成员函数的实现
|
----------------------------------------------------------------------*/
void ConcreateSubject::SetState( STATE nState )
{
	std::cout << "SetState By ConcreateSubject\n";
	m_nSubjectState = nState;
}
STATE ConcreateSubject::GetState()
{
	std::cout << "GetState By ConcreateSubject\n";
	return m_nSubjectState;
}
/* --------------------------------------------------------------------
| ConcreateObserver类成员函数的实现
|
----------------------------------------------------------------------*/
void ConcreateObserver::Update( SubjectOb* pSubject )
{
	if ( NULL == pSubject )
		return;
	m_nObserverState = pSubject->GetState();
	std::cout << "The ObeserverState is " << m_nObserverState << std::endl;
}