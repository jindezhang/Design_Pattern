// 虚拟基类,所有原型的基类,提供Clone接口函数
class Prototype
{
public:
	Prototype(){}
	virtual ~Prototype(){}
	virtual Prototype* Clone() = 0;
};
// 派生自Prototype,实现Clone方法
class ConcreatePrototype1
	: public Prototype
{
public:
	ConcreatePrototype1();
	ConcreatePrototype1( const ConcreatePrototype1& );
	virtual ~ConcreatePrototype1();
	virtual Prototype* Clone();
};
// 派生自Prototype,实现Clone方法
class ConcreatePrototype2
	: public Prototype
{
public:
	ConcreatePrototype2();
	ConcreatePrototype2( const ConcreatePrototype2& );
	virtual ~ConcreatePrototype2();
	virtual Prototype* Clone();
};

#pragma once
