#include <list>

typedef int STATE;

class Observer;
// SubjectOb 抽象基类,只需要知道Observer基类的声明就可以了
class SubjectOb
{
public:
	SubjectOb() : m_nSubjectState( -1 ){}
	virtual ~SubjectOb();
	void Notify(); // 通知对象改变状态
	void Attach( Observer *pObserver ); // 新增对象
	void Detach( Observer *pObserver ); // 删除对象
										// 虚函数,提供默认的实现,派生类可以自己实现来覆盖基类的实现
	virtual void SetState( STATE nState ); // 设置状态
	virtual STATE GetState(); // 得到状态
protected:
	STATE m_nSubjectState; // 模拟保存SubjectOb状态的变量
	std::list<Observer*> m_ListObserver; // 保存Observer指针的链表
};
// Observer抽象基类
class Observer
{
public:
	Observer() : m_nObserverState( -1 ){}
	virtual ~Observer(){}
	// 纯虚函数,各个派生类可能有不同的实现
	// 通知Observer状态发生了变化
	virtual void Update( SubjectOb* pSubject ) = 0;
protected:
	STATE m_nObserverState; // 模拟保存Observer状态的变量
};

//派生在SubjectOb类的ConcreateSubject类
class ConcreateSubject
	: public SubjectOb
{
public:
	ConcreateSubject() : SubjectOb(){}
	virtual ~ConcreateSubject(){}
	// 派生类自己实现来覆盖基类的实现
	virtual void SetState( STATE nState ); // 设置状态
	virtual STATE GetState(); // 得到状态
};

//派生自Observer的ConcreateObserver类
class ConcreateObserver
	: public Observer
{
public:
	ConcreateObserver() : Observer(){}
	virtual ~ConcreateObserver(){}
	// 虚函数,实现基类提供的接口
	virtual void Update( SubjectOb* pSubject );
};
#pragma once
