#include <string>

class Image
{
public:
	Image(){}
	virtual ~Image(){}
	virtual void display() = 0;
};

class ReallImage
	:public Image
{
public:
	ReallImage(std::string fileName);
	virtual ~ReallImage(){}
	virtual void display();
	
private:
	void loadFromDisk( std::string fileName );
	std::string fileName;
};

class ProxyImage
	:public Image
{
public:
	ProxyImage( std::string fileName ) :fileName( fileName ){}
	virtual ~ProxyImage();
	virtual void display();
private:
	ReallImage *reallmage;
	std::string fileName;
};


#pragma once
