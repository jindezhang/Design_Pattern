#include <vector>

class ComputerPartVisitor;

class ComputerPart
{
public:
	virtual ~ComputerPart(){}
	virtual void accept( ComputerPartVisitor* computerPartVisitor ) = 0;
protected:
	explicit ComputerPart(){}
};

class KeyBoard
	:public ComputerPart
{
public:
	~KeyBoard();
	void accept( ComputerPartVisitor* computerPartVisitor );

};

class Mouse
	:public ComputerPart
{
public:
	void accept( ComputerPartVisitor* computerPartVisitor );
};


class Monitor
	:public ComputerPart
{
	void accept( ComputerPartVisitor* computerPartVisitor );
};

class Computer
	:public ComputerPart
{
public:
	void accept( ComputerPartVisitor* computerPartVisitor );
	Computer();
	~Computer();

private:
	std::vector<ComputerPart*> v_part;
};

class ComputerPartVisitor
{
public:
	virtual void visit( Monitor* computer ) =0;
	virtual void visit( Mouse* computer ) = 0;
	virtual void visit( KeyBoard* computer ) = 0;
	virtual void visit( Computer* computer ) = 0;

};

class ComputerPartDisplayVisitor
	:public ComputerPartVisitor
{
public:
	void visit( Monitor* computer );
	void visit( Mouse* computer );
	void visit( KeyBoard* computer );
	void visit( Computer* computer );
};

#pragma once

