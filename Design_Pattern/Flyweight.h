#include <string>
#include <list>
typedef std::string STATE;
class Flyweight //Ŀ�����ĳ����࣬�����Ϊ���������ͷǿɹ��������
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
	STATE m_State; //��־�����ֲ�ͬ�Ĺ������
};
class FlyweightFactory //������
{
public:
	FlyweightFactory(){}
	~FlyweightFactory();
	Flyweight* GetFlyweight( const STATE& key ); 
	//�����Ƿ����д˶���û���򴴽�
private:
	std::list<Flyweight*> m_listFlyweight; //���湲������б�
};
class ConcreateFlyweight //���������
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
