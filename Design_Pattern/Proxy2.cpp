#include "Proxy2.h"
#include <iostream>

ReallImage::ReallImage(std::string fileName):fileName(fileName)
{
//	std::cout << "crate ReallImage\n";
	loadFromDisk( fileName );
}

void ReallImage::display()
{
	std::cout << "\nDisplaying" << fileName;
}

void ReallImage::loadFromDisk( std::string fileName )
{
	std::cout << "\nLoading" << fileName;
}

ProxyImage::~ProxyImage()
{
	delete reallmage;
	reallmage = nullptr;

}

void ProxyImage::display()
{
	if (nullptr == reallmage)
	{
		reallmage = new ReallImage( fileName );
	}
	reallmage->display();
}
