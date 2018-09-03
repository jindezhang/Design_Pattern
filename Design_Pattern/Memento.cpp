#include "Memento.h"
#include <iostream>
#include <algorithm>

Originator::Originator( const StateM & rState )
{
	m_State = rState;
}

Originator::Originator()
{
}

Originator::~Originator()
{
}

Memento * Originator::CreateMemento()
{
	return new Memento(m_State);
}

void Originator::SetMemento( Memento * pMemento )
{
	if(pMemento != nullptr )
		pMemento->SetState( m_State );
}

StateM Originator::GetState()
{
	return m_State;
}

void Originator::SetState( const StateM & rState )
{
	m_State = rState;
}

void Originator::RestoreState( Memento * pMemento )
{
	if (pMemento != nullptr)
	{
		m_State = pMemento->GetState();
	}
}

void Originator::PrintState()
{
	std::cout << "State=" << m_State << std::endl;
}

Memento::Memento( const StateM & rState )
{
	m_State = rState;
}

void Memento::SetState( const StateM & rState )
{
	m_State = rState;
}

StateM Memento::GetState()
{
	return m_State;
}

void CareTaker::add( Memento * pMemento )
{
	if(pMemento != nullptr )
		v_memento.push_back( pMemento );
}

Memento * CareTaker::get( int index )
{
	return v_memento[index];
}

CareTaker::~CareTaker()
{
	std::for_each( v_memento.begin(), v_memento.end(), []( auto p ){
		std::cout << "delete" << std::endl;
		delete p; } );
}
