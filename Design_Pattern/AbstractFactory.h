class AbstractProductA
{
public:
	AbstractProductA() {}
	virtual ~AbstractProductA(){};
};
// ������ConcreateProductA1,�̳���AbstractProductA,�����ƷA�ĵ�һ��ʵ��
class ConcreateProductA1
	: public AbstractProductA
{
public:
	ConcreateProductA1();
	virtual ~ConcreateProductA1();
};


// ������ConcreateProductA2,�̳���AbstractProductA,�����ƷA�ĵڶ���ʵ��
class ConcreateProductA2
	: public AbstractProductA
{
public:
	ConcreateProductA2();
	virtual ~ConcreateProductA2();
};


// �������AbstractProductB,�����ƷB�ĳ���
class AbstractProductB
{
public:
	AbstractProductB() {}
	virtual ~AbstractProductB(){};
};
// ������ConcreateProductB1,�̳���AbstractProductB,�����ƷB�ĵ�һ��ʵ��
class ConcreateProductB1
	: public AbstractProductB
{
public:
	ConcreateProductB1();
	virtual ~ConcreateProductB1();
};
// ������ConcreateProductB2,�̳���AbstractProductB,�����ƷB�ĵڶ���ʵ��
class ConcreateProductB2
	: public AbstractProductB
{
public:
	ConcreateProductB2();
	virtual ~ConcreateProductB2();
};


// �������AbstractFactory,�����ĳ�����,������ƷA�Ͳ�ƷB
class AbstractFactory
{
public:
	AbstractFactory(){}
	virtual ~AbstractFactory(){}
	virtual AbstractProductA* CreateProductA() = 0;
	virtual AbstractProductB* CreateProductB() = 0;
};

// ������ConcreateFactory1,�̳���AbstractFactory
// ������ƷA�Ͳ�ƷB�ĵ�һ��ʵ��
class ConcreateFactory1
	: public AbstractFactory
{
public:
	ConcreateFactory1();
	virtual ~ConcreateFactory1();
	virtual AbstractProductA* CreateProductA();
	virtual AbstractProductB* CreateProductB();
};

// ������ConcreateFactory2,�̳���AbstractFactory
// ������ƷA�Ͳ�ƷB�ĵڶ���ʵ��
class ConcreateFactory2
	: public AbstractFactory
{
public:
	ConcreateFactory2();
	virtual ~ConcreateFactory2();
	virtual AbstractProductA* CreateProductA();
	virtual AbstractProductB* CreateProductB();
};


#pragma once
