#include <iostream>
#include <string>
#include <list>

class Order//封装命令的抽象基类
{
public:
	virtual ~Order(){};
	virtual void execute() = 0;
};

class Stock//封装命令的动作对象等
{
public:
	Stock( std::string name, int q ) :name( name ), quantity( q ){}
	void buy();
	void sell();
private:
	std::string name;
	int quantity;
};

class Broker//命令执行者
{
public:
	void takeOrder(Order *stock);
	~Broker();
	void placeOrder();
private:
	std::list<Order* > list;
};

class BuyStock //封装具体的命令
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
