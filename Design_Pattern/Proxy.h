// ������Proxy��RealSubject�Ĺ��нӿ�,
// �����Ϳ������κ���Ҫʹ�õ�RealSubject�ĵط���ʹ��Proxy.
class Subject
{
public:
	Subject(){}
	virtual ~Subject(){}
	virtual void Request() = 0;
};
// ����ʹ�õ�ʵ��
class RealSubject
	: public Subject
{
public:
	RealSubject();
	virtual ~RealSubject(){}
	virtual void Request(); //�ṩʵ�ʹ���
};
// ������,����һ��ָ��RealSubject�����ָ��
class Proxy
	: public Subject
{
public:
	Proxy();
	virtual ~Proxy();
	virtual void Request(); //��һ�α�����ʱ�ڲ�����RealSubject���󲢵����书��
private:
	RealSubject* m_pRealSubject;
};
#pragma once
