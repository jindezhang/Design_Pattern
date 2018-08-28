/*װ��ģʽΪ�����ද̬���Ӷ���Ĺ��ܾ���LOL��
������ҫ����Dota��Ϸ�У�Ӣ������һ����
ÿ��Ӣ���������ḽ��һ�����⼼�ܵ�ѧϰ���ܡ�
�����Ӣ�۾���ConcreteComponent��
����������װ����Decorator��
ÿ�����ܾ���ConcreteDecorator��*/

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
