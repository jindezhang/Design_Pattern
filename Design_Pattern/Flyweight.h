#include <string>
#include <list>
typedef std::string STATE;
class Flyweight //目标对象的抽象类，子类分为共享对象类和非可共享对象类
{
public:
	virtual ~Flyweight(){}
	STATE GetIntrinsicState();
	virtual void Operation( STATE& ExtrinsicState ) = 0;
protected:
	Flyweight( const STATE& state )
		:m_State( state )
	{
	}
private:
	STATE m_State; //标志，区分不同的共享对象
};
class FlyweightFactory //工厂类
{
public:
	FlyweightFactory(){}
	~FlyweightFactory();
	Flyweight* GetFlyweight( const STATE& key ); 
	//查找是否已有此对象，没有则创建
private:
	std::list<Flyweight*> m_listFlyweight; //保存共享对象列表
};
class ConcreateFlyweight //共享对象类
	: public Flyweight
{
public:
	ConcreateFlyweight( const STATE& state )
		: Flyweight( state )
	{
	}
	virtual ~ConcreateFlyweight(){}
	virtual void Operation( STATE& ExtrinsicState );
};
#pragma once
