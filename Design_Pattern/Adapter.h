// ��Ҫ��Adapt ���࣬�������ṩ���ⲿ���е����õġ�
class Target
{
public:
	Target(){}
	virtual ~Target() {}
	virtual void Request() = 0;
};
// ʵ������ͬ�Ĺ��ܣ�����Target�ṩ�����ݽӿڵ���
class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecialRequest();
};
// ����Adapt����,���þۺ�ԭ�нӿ���ķ�ʽ
class Adapter
	: public Target //1)�̳б�Adapt����
{
public:
	Adapter( Adaptee* pAdaptee );
	virtual ~Adapter();
	virtual void Request(); //�Ա�׼�ⲿ�ӿ��ṩԭ�нӿڵĹ���
private:
	Adaptee* m_pAdptee; //2)���治���ݽӿ����ָ��
};


#pragma once
