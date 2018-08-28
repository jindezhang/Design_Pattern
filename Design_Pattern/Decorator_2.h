/*装饰模式为已有类动态附加额外的功能就像LOL、
王者荣耀等类Dota游戏中，英雄升级一样。
每次英雄升级都会附加一个额外技能点学习技能。
具体的英雄就是ConcreteComponent，
技能栏就是装饰器Decorator，
每个技能就是ConcreteDecorator；*/

#include <string>
#include <iostream>

class hero
{
public:
	hero(){}
	virtual ~hero(){}
	virtual void learnSkills() = 0;
};

class BlindMonk
	:public hero
{
public:
	BlindMonk( std::string name );
	virtual void learnSkills();
private:
	std::string name;
	
};

class Skills
	:virtual public hero
{
public:
	Skills( hero* h );
	virtual ~Skills();
	virtual void learnSkills();
protected:
	hero* name;
};

class Skill_q
	:virtual public Skills
{
public:
	Skill_q( hero* h, std::string skillName );
	void learnSkills();
private:
	//hero name;
	std::string skillName;
};

#pragma once
