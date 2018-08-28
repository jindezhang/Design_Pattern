// 抽象基类,定义一个对象接口,可以为这个接口动态的添加职责.
class Component2
{
public:
	Component2(){}
	virtual ~Component2(){}
	// 纯虚函数,由派生类实现
	virtual void Operation() = 0;
};

// 抽象基类,维护一个指向Component2 对象的指针
class Decorator
	: public Component2
{
public:
	Decorator( Component2* pComponent ) : m_pComponent( pComponent ){}
	virtual ~Decorator();
protected:
	Component2* m_pComponent;
};
// 派生自Component,在这里表示需要给它动态添加职责的类
class ConcreateComponent
	: public Component2
{
public:
	ConcreateComponent(){}
	virtual ~ConcreateComponent(){}
	virtual void Operation();
};
// 派生自Decorator,这里代表为ConcreateComponent动态添加职责的类
class ConcreateDecorator
	: public Decorator
{
public:
	ConcreateDecorator( Component2* pComponent ) : Decorator( pComponent ){}
	virtual ~ConcreateDecorator(){}
	virtual void Operation(); //调用原接口，再补充新的行为
private:
	void AddedBehavior(); //新增加的行为
};
#pragma once
