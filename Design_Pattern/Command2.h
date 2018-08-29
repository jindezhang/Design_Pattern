#include <iostream>
#include <string>
#include <list>

class Order//��װ����ĳ������
{
public:
	virtual ~Order(){};
	virtual void execute() = 0;
};

class Stock//��װ����Ķ��������
{
public:
	Stock( std::string name, int q ) :name( name ), quantity( q ){}
	void buy();
	void sell();
private:
	std::string name;
	int quantity;
};

class Broker//����ִ����
{
public:
	void takeOrder(Order *stock);
	~Broker();
	void placeOrder();
private:
	std::list<Order* > list;
};

class BuyStock //��װ���������
	:public Order
{
public:
	virtual ~BuyStock();
	void execute();
	BuyStock( Stock *stock );

private:
	Stock* stock;
};

class SellStock
	:public Order
{
public:
	virtual ~SellStock();
	SellStock( Stock* stock );
	void execute();
private:
	Stock* stock;

};

#pragma once
