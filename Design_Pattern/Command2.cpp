#include "Command2.h"

void Stock::buy()
{
	std::cout << "name:" << name << "\tquantity:" 
		<< quantity << "\tbuy\n";
}

void Stock::sell()
{
	std::cout << "name:" << name << "\tquantity:"
		<< quantity << "\tsell\n";
}

void Broker::takeOrder( Order * stock )
{
	if ( stock != nullptr )
		list.push_back( stock );
}

Broker::~Broker()
{
	std::cout << "~Broker\n";
	for (auto item: list)
	{
		delete( item );
	}
	list.clear();
}

void Broker::placeOrder()
{
	for (auto item: list)
	{
		item->execute();
	}
}

BuyStock::~BuyStock()
{
	std::cout << "~Buy\n";
	/*if ( stock == nullptr )
		return;
	delete stock;
	stock = nullptr;*/
}

void BuyStock::execute()
{
	stock->buy();
}

BuyStock::BuyStock( Stock * stock )
{
	this->stock = stock;
}

SellStock::~SellStock()
{
	std::cout << "~Sell\n";
	/*if ( stock == nullptr )
		return;
	delete stock;
	stock = nullptr;*/
}

SellStock::SellStock( Stock* stock )
{
	this->stock = stock;
}

void SellStock::execute()
{
	stock->sell();
}
