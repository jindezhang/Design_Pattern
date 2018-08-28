class Implementor;
// 维护一个Implementor类的指针
class Abstraction
{
public:
	Abstraction( Implementor* pImplementor );
	virtual ~Abstraction();
	void Operation(); //根据构造函数中传入的不同的Implementor类的指针就会有不同的实现
protected:
	Implementor* m_pImplementor;
};
// 为实现Abstraction 定义的抽象基类,定义了实现的接口函数
class Implementor
{
public:
	Implementor(){}
	virtual ~Implementor(){}
	virtual void OperationImpl() = 0;
};
// 继承自Implementor,是Implementor的不同实现之一
class ConcreateImplementorA
	: public Implementor
{
public:
	ConcreateImplementorA(){}
	virtual ~ConcreateImplementorA(){}
	virtual void OperationImpl();
};
// 继承自Implementor,是Implementor的不同实现之一
class ConcreateImplementorB
	: public Implementor
{
public:
	ConcreateImplementorB(){}
	virtual ~ConcreateImplementorB(){}
	virtual void OperationImpl();
};
#pragma once
