#include <list>

typedef int STATE;

class Observer;
// SubjectOb �������,ֻ��Ҫ֪��Observer����������Ϳ�����
class SubjectOb
{
public:
	SubjectOb() : m_nSubjectState( -1 ){}
	virtual ~SubjectOb();
	void Notify(); // ֪ͨ����ı�״̬
	void Attach( Observer *pObserver ); // ��������
	void Detach( Observer *pObserver ); // ɾ������
										// �麯��,�ṩĬ�ϵ�ʵ��,����������Լ�ʵ�������ǻ����ʵ��
	virtual void SetState( STATE nState ); // ����״̬
	virtual STATE GetState(); // �õ�״̬
protected:
	STATE m_nSubjectState; // ģ�Ᵽ��SubjectOb״̬�ı���
	std::list<Observer*> m_ListObserver; // ����Observerָ�������
};
// Observer�������
class Observer
{
public:
	Observer() : m_nObserverState( -1 ){}
	virtual ~Observer(){}
	// ���麯��,��������������в�ͬ��ʵ��
	// ֪ͨObserver״̬�����˱仯
	virtual void Update( SubjectOb* pSubject ) = 0;
protected:
	STATE m_nObserverState; // ģ�Ᵽ��Observer״̬�ı���
};

//������SubjectOb���ConcreateSubject��
class ConcreateSubject
	: public SubjectOb
{
public:
	ConcreateSubject() : SubjectOb(){}
	virtual ~ConcreateSubject(){}
	// �������Լ�ʵ�������ǻ����ʵ��
	virtual void SetState( STATE nState ); // ����״̬
	virtual STATE GetState(); // �õ�״̬
};

//������Observer��ConcreateObserver��
class ConcreateObserver
	: public Observer
{
public:
	ConcreateObserver() : Observer(){}
	virtual ~ConcreateObserver(){}
	// �麯��,ʵ�ֻ����ṩ�Ľӿ�
	virtual void Update( SubjectOb* pSubject );
};
#pragma once
