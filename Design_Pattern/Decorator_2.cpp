#include "Decorator_2.h"

BlindMonk::BlindMonk( std::string name )
{
	this->name = name;
}

void BlindMonk::learnSkills()
{
	std::cout << name << " learn all skills\n";

}

Skills::Skills( hero* h )
{
	//std::cout << "Skills\n";
	this->name = h;
}

Skills::~Skills()
{
	delete name;
	name = nullptr;
}

void Skills::learnSkills()
{
	//std::cout << "learnSkills\n";
	name->learnSkills();
}

Skill_q::Skill_q( hero* h , std::string skillName) :Skills( h )
{
	this->skillName = skillName;
}

void Skill_q::learnSkills()
{
	name->learnSkills();//子类调用父类的方法。
	std::cout << "learn skill：" << skillName<<std::endl;
	
}
