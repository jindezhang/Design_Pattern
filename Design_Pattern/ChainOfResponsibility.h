#include <stdio.h>
// �������,����һ����������Ľӿ�
class Handler
{
public:
	Handler( Handler *pSuccessor = nullptr );
	virtual ~Handler();
	// ���麯��,��������ʵ��
	virtual void HandleRequset() = 0; //ÿ������ʵ��һ�ֲ�ͬ����Ĵ���
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
