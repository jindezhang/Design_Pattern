// �������,�����㷨������
class AbstractClass
{
public:
	AbstractClass(){}
	virtual ~AbstractClass(){}
	// ��������ж������㷨������
	void TemplateMethod(); //ʹ��PrimitiveOperation()����װ�㷨
protected:
	// ���麯��,��������ʵ��֮
	virtual void PrimitiveOperation1() = 0; //�㷨�еĸ�������򲿷�
	virtual void PrimitiveOperation2() = 0;
};
// �̳���AbstractClass,ʵ���㷨
class ConcreateClass
	: public AbstractClass
{
public:
	ConcreateClass(){}
	virtual ~ConcreateClass(){}
protected:
	virtual void PrimitiveOperation1();
	virtual void PrimitiveOperation2();
};

#pragma once
