#include <stdio.h>
// 抽象基类,定义一个处理请求的接口
class Handler
{
public:
	Handler( Handler *pSuccessor = nullptr );
	virtual ~Handler();
	// 纯虚函数,由派生类实现
	virtual void HandleRequset() = 0; //每个子类实现一种不同请求的处理
protected:
	Handler* m_pSuccessor;
};
class ConcreateHandler1
	: public Handler
{
public:
	ConcreateHandler1( Handler *pSuccessor = nullptr ) : Handler( pSuccessor ){}
	virtual ~ConcreateHandler1(){}
	virtual void HandleRequset();
};
class ConcreateHandler2
	: public Handler
{
public:
	ConcreateHandler2( Handler *pSuccessor = nullptr ) : Handler( pSuccessor ){}
	virtual ~ConcreateHandler2(){}
	virtual void HandleRequset();
}; 

#pragma once
