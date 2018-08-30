/*ʹ��ģ��ķ���ȥ���������**/
#include <memory>

typedef int DATA;
class Iterater;
// �����ĳ�����࣬������Ҫ�ṩһЩ�Ѿ����淶�涨�õĻ�������
class Aggregate
{
public:
	virtual ~Aggregate(){}
	virtual Iterater* CreateIterater( Aggregate *pAggregate ) = 0;
	virtual int GetSize() = 0;
	virtual DATA GetItem( int nIndex ) = 0;
};
// �������ĳ�����࣬������ʹ�������Ļ�������
//�ṩ��ǿ�Ĺ�����������������ṩ�淶�涨�õ�һ�½ӿ�
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
// һ�������������,�������������ʾ
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
// ����ConcreateAggregate������ĵ�������
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

//��������ģ��
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
