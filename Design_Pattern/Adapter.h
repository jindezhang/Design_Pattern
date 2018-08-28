// 需要被Adapt 的类，此类是提供给外部进行调用用的。
class Target
{
public:
	Target(){}
	virtual ~Target() {}
	virtual void Request() = 0;
};
// 实现了相同的功能，但与Target提供不兼容接口的类
class Adaptee
{
public:
	Adaptee(){}
	~Adaptee(){}
	void SpecialRequest();
};
// 进行Adapt的类,采用聚合原有接口类的方式
class Adapter
	: public Target //1)继承被Adapt的类
{
public:
	Adapter( Adaptee* pAdaptee );
	virtual ~Adapter();
	virtual void Request(); //以标准外部接口提供原有接口的功能
private:
	Adaptee* m_pAdptee; //2)保存不兼容接口类的指针
};


#pragma once
