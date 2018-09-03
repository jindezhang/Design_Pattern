class Visitor;
class Element //通过调用Visitor类来访问结点的抽象基类::稳定的数据
{
public:
	virtual ~Element(){}
	virtual void Accept( Visitor &rVisitor ) = 0;
protected:
	Element(){}
};

class ConcreateElementA //访问具体某个结点的Element子类
	: public Element
{
public:
	virtual ~ConcreateElementA() {}
	virtual void Accept( Visitor &rVisitor );
};

class ConcreateElementB //访问具体某个结点的Element子类
	: public Element
{
public:
	virtual ~ConcreateElementB() {}
	virtual void Accept( Visitor &rVisitor );
};

class Visitor //封装了访问所有结点的接口的抽象基类::稳定的操作
{
public:
	virtual ~Visitor(){}
	virtual void VisitConcreateElementA( ConcreateElementA *pConcreateElementA ) = 0;
	virtual void VisitConcreateElementB( ConcreateElementB *pConcreateElementB ) = 0;
protected:
	Visitor(){}
};

class ConcreateVisitorA //具体实现了不同形式的访问接口的Visitor子类
	: public Visitor
{
public:
	virtual ~ConcreateVisitorA(){}
	virtual void VisitConcreateElementA( ConcreateElementA *pConcreateElementA );
	virtual void VisitConcreateElementB( ConcreateElementB *pConcreateElementB );
};

class ConcreateVisitorB //具体实现了不同形式的访问接口的Visitor子类
	: public Visitor
{
public:
	virtual ~ConcreateVisitorB(){}
	virtual void VisitConcreateElementA( ConcreateElementA *pConcreateElementA );
	virtual void VisitConcreateElementB( ConcreateElementB *pConcreateElementB );
};
#pragma once
