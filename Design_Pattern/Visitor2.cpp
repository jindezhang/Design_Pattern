#include "Visitor2.h"
#include <algorithm>
#include <iostream>

KeyBoard::~KeyBoard()
{
	std::cout << "delete K" << std::endl;
}

void KeyBoard::accept( ComputerPartVisitor * computerPartVisitor )
{
	computerPartVisitor->visit( this );
}

void Mouse::accept( ComputerPartVisitor * computerPartVisitor )
{
	computerPartVisitor->visit( this );
}

void Monitor::accept( ComputerPartVisitor * computerPartVisitor )
{
	computerPartVisitor->visit( this );
}

void Computer::accept( ComputerPartVisitor * computerPartVisitor )
{
	std::for_each( v_part.begin(), v_part.end(), [ computerPartVisitor ]( auto v ){
		v->accept( computerPartVisitor ); } );
	computerPartVisitor->visit( this );
}

Computer::Computer()
{
	v_part = { new Mouse(), new KeyBoard(), new Monitor() };
}

Computer::~Computer()
{
	for ( auto item : v_part )
		delete item;
}

void ComputerPartDisplayVisitor::visit( Monitor * computer )
{
	std::cout << "Monitor display\n";
}

void ComputerPartDisplayVisitor::visit( Mouse * computer )
{
	std::cout << "Mouse display\n";
}

void ComputerPartDisplayVisitor::visit( KeyBoard * computer )
{
	std::cout << "keyboard display\n";
}

void ComputerPartDisplayVisitor::visit( Computer * computer )
{
	std::cout << "Computer display\n";
}
