/*使用模板的方法去定义迭代器**/
#include <memory>

typedef int DATA;
class Iterater;
// 容器的抽象基类，容器需要提供一些已经被规范规定好的基本操作
class Aggregate
{
public:
	virtual ~Aggregate(){}
	virtual Iterater* CreateIterater( Aggregate *pAggregate ) = 0;
	virtual int GetSize() = 0;
	virtual DATA GetItem( int nIndex ) = 0;
};
// 迭代器的抽象基类，迭代器使用容器的基本操作
//提供更强的功能如遍历，并对外提供规范规定好的一致接口
class Iterater
{
public:
	virtual ~Iterater(){}
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual DATA CurrentItem() = 0;
private:
};
// 一个具体的容器类,这里是用数组表示
class ConcreateAggregate
	: public Aggregate
{
public:
	ConcreateAggregate( int nSize );
	virtual ~ConcreateAggregate();
	virtual Iterater* CreateIterater( Aggregate *pAggregate );
	virtual int GetSize();
	virtual DATA GetItem( int nIndex );
private:
	int m_nSize;
	DATA *m_pData;
};
// 访问ConcreateAggregate容器类的迭代器类
class ConcreateIterater
	: public Iterater
{
public:
	ConcreateIterater( Aggregate* pAggregate );
	virtual ~ConcreateIterater(){}
	virtual void First();
	virtual void Next();
	virtual bool IsDone();
	virtual DATA CurrentItem();
private:
	Aggregate *m_pConcreateAggregate;
	int m_nIndex;
};

//迭代器类模板
template <typename T>
class ConcreateIterater2
{
public:
	ConcreateIterater2( std::shared_ptr<T> type ) :m_type( type ), m_nindex( 0 ){}
	void First();
	void Next();
	bool IsDone();
	DATA CurrentItem();
private:
	std::shared_ptr<T> m_type;
	int m_nindex;
	};
#pragma once

template<typename T>
inline void ConcreateIterater2<T>::First()
{
	m_nindex = 0;
}

template<typename T>
inline void ConcreateIterater2<T>::Next()
{
	if (m_nindex < m_type->GetSize())
	{
		m_nindex++;
	}
}

template<typename T>
inline bool ConcreateIterater2<T>::IsDone()
{
	return m_nindex == m_type->GetSize();
}

template<typename T>
inline DATA ConcreateIterater2<T>::CurrentItem()
{
	return m_type->GetItem(m_nindex);
}
