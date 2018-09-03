#include <string>
#include <vector>

typedef std::string StateM;
class Memento;
class Originator //��Ҫ����״̬����
{
public:
	Originator( const StateM& rState );
	Originator();
	~Originator();
	Memento* CreateMemento(); //�Ե�ǰ״̬Ϊ��ʼֵ����Memento״̬��
	void SetMemento( Memento* pMemento );
	StateM GetState();
	void SetState( const StateM& rState );
	void RestoreState( Memento* pMemento ); //��pMemento�лָ�����״̬
	void PrintState();
private:
	StateM m_State;
};
// ��Memento�Ľӿں���������Ϊ˽�е�,��Originator��������Ԫ,
// ������֤��ֻ��Originator���Զ������
class Memento //ΪOriginator�ౣ������״̬
{
private:
	friend class Originator;
	Memento( const StateM& rState ); //���캯����˽�еģ�����ֻ��ʹ��Originator��CreateMemento()����������
	void SetState( const StateM& rState ); //���ݵ�ǰ״̬�ĺ���
	StateM GetState(); //�ָ�����״̬�ĺ���
	StateM m_State; //���ݵ�״̬

};

//���״̬����ʱ�򣬺ñ�������Ϸ�浵��Ӧ�ö��Memento ������,���ǲ���ֱ�ӷ���Memento�ࡣ
class CareTaker
{
public:
	void add( Memento* pMemento );
	Memento* get( int index );
	~CareTaker();
private:
	std::vector<Memento*> v_memento;//vector�������飬�����������ȡ��	
};
#pragma once
