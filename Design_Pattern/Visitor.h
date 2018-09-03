class Visitor;
class Element //ͨ������Visitor�������ʽ��ĳ������::�ȶ�������
{
public:
	virtual ~Element(){}
	virtual void Accept( Visitor &rVisitor ) = 0;
protected:
	Element(){}
};

class ConcreateElementA //���ʾ���ĳ������Element����
	: public Element
{
public:
	virtual ~ConcreateElementA() {}
	virtual void Accept( Visitor &rVisitor );
};

class ConcreateElementB //���ʾ���ĳ������Element����
	: public Element
{
public:
	virtual ~ConcreateElementB() {}
	virtual void Accept( Visitor &rVisitor );
};

class Visitor //��װ�˷������н��Ľӿڵĳ������::�ȶ��Ĳ���
{
public:
	virtual ~Visitor(){}
	virtual void VisitConcreateElementA( ConcreateElementA *pConcreateElementA ) = 0;
	virtual void VisitConcreateElementB( ConcreateElementB *pConcreateElementB ) = 0;
protected:
	Visitor(){}
};

class ConcreateVisitorA //����ʵ���˲�ͬ��ʽ�ķ��ʽӿڵ�Visitor����
	: public Visitor
{
public:
	virtual ~ConcreateVisitorA(){}
	virtual void VisitConcreateElementA( ConcreateElementA *pConcreateElementA );
	virtual void VisitConcreateElementB( ConcreateElementB *pConcreateElementB );
};

class ConcreateVisitorB //����ʵ���˲�ͬ��ʽ�ķ��ʽӿڵ�Visitor����
	: public Visitor
{
public:
	virtual ~ConcreateVisitorB(){}
	virtual void VisitConcreateElementA( ConcreateElementA *pConcreateElementA );
	virtual void VisitConcreateElementB( ConcreateElementB *pConcreateElementB );
};
#pragma once
