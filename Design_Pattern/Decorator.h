// �������,����һ������ӿ�,����Ϊ����ӿڶ�̬�����ְ��.
class Component2
{
public:
	Component2(){}
	virtual ~Component2(){}
	// ���麯��,��������ʵ��
	virtual void Operation() = 0;
};

// �������,ά��һ��ָ��Component2 �����ָ��
class Decorator
	: public Component2
{
public:
	Decorator( Component2* pComponent ) : m_pComponent( pComponent ){}
	virtual ~Decorator();
protected:
	Component2* m_pComponent;
};
// ������Component,�������ʾ��Ҫ������̬���ְ�����
class ConcreateComponent
	: public Component2
{
public:
	ConcreateComponent(){}
	virtual ~ConcreateComponent(){}
	virtual void Operation();
};
// ������Decorator,�������ΪConcreateComponent��̬���ְ�����
class ConcreateDecorator
	: public Decorator
{
public:
	ConcreateDecorator( Component2* pComponent ) : Decorator( pComponent ){}
	virtual ~ConcreateDecorator(){}
	virtual void Operation(); //����ԭ�ӿڣ��ٲ����µ���Ϊ
private:
	void AddedBehavior(); //�����ӵ���Ϊ
};
#pragma once
