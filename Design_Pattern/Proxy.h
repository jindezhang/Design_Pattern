// 定义了Proxy和RealSubject的公有接口,
// 这样就可以在任何需要使用到RealSubject的地方都使用Proxy.
class Subject
{
public:
	Subject(){}
	virtual ~Subject(){}
	virtual void Request() = 0;
};
// 真正使用的实体
class RealSubject
	: public Subject
{
public:
	RealSubject();
	virtual ~RealSubject(){}
	virtual void Request(); //提供实际功能
};
// 代理类,含有一个指向RealSubject对象的指针
class Proxy
	: public Subject
{
public:
	Proxy();
	virtual ~Proxy();
	virtual void Request(); //第一次被调用时内部生成RealSubject对象并调用其功能
private:
	RealSubject* m_pRealSubject;
};
#pragma once
