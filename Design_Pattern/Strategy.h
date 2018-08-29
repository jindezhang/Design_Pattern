class Stategy
{
public:
	
	virtual int doOperation( int num1, int num2 ) = 0;
};

class OperationAdd
	:public Stategy
{
public:
	int doOperation( int num1, int num2 );
};

class OperationSub
	:public Stategy
{
public:
	int doOperation( int num1, int num2 );
};

class Context
{
public:
	Context( Stategy* state ) :state( state ){}
	virtual ~Context();
	void setStategy( Stategy* state );
	int executeStategy( int num1, int num2 );
private:
	Stategy* state;
	//void delStategy();
};

#pragma once
