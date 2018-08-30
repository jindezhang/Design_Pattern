#include <string>
#include <memory>
#include <iostream>

class Contexts;
class State
{
public:
	
	virtual ~State(){ std::cout << "\t^^^^\n"; };
	virtual std::string toString() = 0;
	virtual void doAction( std::shared_ptr<Contexts> con ) = 0;
};

class StartState
	:public State
{
public:
	explicit StartState();
	StartState( StartState& s );
	~StartState();
	virtual void doAction( std::shared_ptr<Contexts> con );
	std::string toString();
};

class StopState
	:public State
{
public:
	explicit StopState();
	~StopState();
	StopState( StopState& s ){ std::cout << "\t%%%%\n"; }
	virtual void doAction( std::shared_ptr<Contexts> con );
	std::string toString();
};

class Contexts
{
public:
	
	~Contexts();
	explicit Contexts() :statea( nullptr ){ std::cout << "\tcontext\n"; }
	void setState( std::shared_ptr<State> state );
	std::shared_ptr<State> getState();
private:
	std::shared_ptr<State>statea;
};

#pragma once
