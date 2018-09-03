#include <string>
#include <vector>

typedef std::string StateM;
class Memento;
class Originator //需要保存状态的类
{
public:
	Originator( const StateM& rState );
	Originator();
	~Originator();
	Memento* CreateMemento(); //以当前状态为初始值创建Memento状态类
	void SetMemento( Memento* pMemento );
	StateM GetState();
	void SetState( const StateM& rState );
	void RestoreState( Memento* pMemento ); //从pMemento中恢复备份状态
	void PrintState();
private:
	StateM m_State;
};
// 把Memento的接口函数都设置为私有的,而Originator是它的友元,
// 这样保证了只有Originator可以对其访问
class Memento //为Originator类保存它的状态
{
private:
	friend class Originator;
	Memento( const StateM& rState ); //构造函数是私有的，所以只能使用Originator的CreateMemento()函数来创建
	void SetState( const StateM& rState ); //备份当前状态的函数
	StateM GetState(); //恢复备份状态的函数
	StateM m_State; //备份的状态

};

//多个状态备份时候，好比如多个游戏存档。应该多个Memento 管理类,但是不能直接访问Memento类。
class CareTaker
{
public:
	void add( Memento* pMemento );
	Memento* get( int index );
	~CareTaker();
private:
	std::vector<Memento*> v_memento;//vector类似数组，适用于随机存取。	
};
#pragma once
