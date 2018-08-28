class Implementor;
// ά��һ��Implementor���ָ��
class Abstraction
{
public:
	Abstraction( Implementor* pImplementor );
	virtual ~Abstraction();
	void Operation(); //���ݹ��캯���д���Ĳ�ͬ��Implementor���ָ��ͻ��в�ͬ��ʵ��
protected:
	Implementor* m_pImplementor;
};
// Ϊʵ��Abstraction ����ĳ������,������ʵ�ֵĽӿں���
class Implementor
{
public:
	Implementor(){}
	virtual ~Implementor(){}
	virtual void OperationImpl() = 0;
};
// �̳���Implementor,��Implementor�Ĳ�ͬʵ��֮һ
class ConcreateImplementorA
	: public Implementor
{
public:
	ConcreateImplementorA(){}
	virtual ~ConcreateImplementorA(){}
	virtual void OperationImpl();
};
// �̳���Implementor,��Implementor�Ĳ�ͬʵ��֮һ
class ConcreateImplementorB
	: public Implementor
{
public:
	ConcreateImplementorB(){}
	virtual ~ConcreateImplementorB(){}
	virtual void OperationImpl();
};
#pragma once
