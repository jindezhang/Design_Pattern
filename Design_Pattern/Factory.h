#include <iostream>



class Procduct //---��Ʒ
{
public:
	Procduct(){}
	virtual ~Procduct(){}//�麯����Ϊ�˽���ʱ�ø�ָ�����������������

	virtual void fly() = 0;
	//void fly();//�ڸ���͹������У������ǽӿڣ����ܾ���ʵ�֡�
};

class ConcreateProduct //ʵ�ֲ�Ʒ�ľ�����
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
	// ����FactoryMethod()����������ض��ľ����Ʒ��ָ�룬
	// ���Ӧ�ö�Ӧ�������
	//void AnOperation();
	//Procduct * get_Product();
//protected:
	//���ģ��������ɲ�ͬ�ľ����Ʒ
	virtual Procduct* FactoryMethod() = 0;//protected��Ա���Լ̳�
};

class ConcreateCreator :public Creator 
	//�����ľ������࣬���Ʒ�ľ�������ĸ���һһ��Ӧ
{
public:
	ConcreateCreator();
	virtual ~ConcreateCreator();
//protected:
	virtual Procduct* FactoryMethod();//ʵ�ֶ�Ӧ�����Ʒ��ʵ���Ĺ���

	
};


#pragma once
