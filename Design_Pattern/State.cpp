
#include "State.h"
#include <iostream>

StartState::StartState()
{
	std::cout << "\tStartState\n";
}

StartState::StartState( StartState & s )
{
	std::cout << "\t&&&\n";
}

StartState::~StartState()
{
	std::cout << "\t~StartState\n";
}

void StartState::doAction( std::shared_ptr<Contexts> con )
{
	std::cout << con.use_count()<<" doAction\n";
	std::cout << "con:" << con.get();
	/*std::shared_ptr<State> p( this );*/
	auto p = std::make_shared<StartState>( *this );
	con->setState( p );
}

std::string StartState::toString()
{
	return "startState\n";
}

StopState::StopState()
{
	std::cout << "\tStopState\n";
}

StopState::~StopState()
{
	std::cout << "\t~StopState\n";
}

void StopState::doAction( std::shared_ptr<Contexts> con )
{
	std::cout << con.use_count() << " stop doAction\n";
	/*std::shared_ptr<State> p( this );*/
	auto m = std::make_shared<StopState>( *this );
	con->setState( m);
	printf( "m: 0x%x\n", m.get());
	std::cout << "m:" << m.use_count()<<std::endl;
	auto p = std::make_shared<StopState>( *this );
	con->setState( p );
	printf( "m: 0x%x\n", m.get() );
	std::cout << "m:" << m.use_count() << std::endl;
}

std::string StopState::toString()
{
	return "stop state\n";
}

Contexts::~Contexts()
{
	std::cout << "\t~context\n";
}

void Contexts::setState( std::shared_ptr<State> state )
{
	//std::cout << "set: " << state.use_count() << std::endl;
	this->statea = state;

	printf( "setState: 0x%x\n", state.get() );
	printf( "setStatea: 0x%x\n", statea.get() );
}

std::shared_ptr<State> Contexts::getState()
{
	return statea;
}
