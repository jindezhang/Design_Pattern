#pragma once
class Command //封装了命令类的抽象基类
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
};

class Receiver //封装命令的动作对象等
{
public:
	void Action(); //实现命令中的操作或动作
};

class Invoker //命令执行者
{
public:
	Invoker( Command *pCommand );
	~Invoker();
	void Invoke(); //执行具体的命令
private:
	Command *m_pCommand;
};

class ConcreateComand //封装具体的命令
	: public Command
{
public:
	ConcreateComand( Receiver* pReceiver );
	virtual ~ConcreateComand();
	virtual void Execute(); //实现具体命令的执行
private:
	Receiver* m_pReceiver;
};
