#include <iostream>



class Procduct //---产品
{
public:
	Procduct(){}
	virtual ~Procduct(){}//虚函数是为了解析时用父指针调用子类析构函数

	virtual void fly() = 0;
	//void fly();//在该类和工厂类中，必须是接口，不能具体实现。
};

class ConcreateProduct //实现产品的具体类
	:public Procduct
{
public:
	ConcreateProduct();
	virtual ~ConcreateProduct();
	void fly();
	void run();
};

class Creator
{
public:
	Creator(){}
	virtual ~Creator(){}
	// 调用FactoryMethod()函数来获得特定的具体产品的指针，
	// 多个应用对应多个函数
	//void AnOperation();
	//Procduct * get_Product();
//protected:
	//核心！用来生成不同的具体产品
	virtual Procduct* FactoryMethod() = 0;//protected成员可以继承
};

class ConcreateCreator :public Creator 
	//工厂的具体子类，与产品的具体子类的个数一一对应
{
public:
	ConcreateCreator();
	virtual ~ConcreateCreator();
//protected:
	virtual Procduct* FactoryMethod();//实现对应具体产品类实例的构造

	
};


#pragma once
