#pragma once
class Command //��װ��������ĳ������
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
};

class Receiver //��װ����Ķ��������
{
public:
	void Action(); //ʵ�������еĲ�������
};

class Invoker //����ִ����
{
public:
	Invoker( Command *pCommand );
	~Invoker();
	void Invoke(); //ִ�о��������
private:
	Command *m_pCommand;
};

class ConcreateComand //��װ���������
	: public Command
{
public:
	ConcreateComand( Receiver* pReceiver );
	virtual ~ConcreateComand();
	virtual void Execute(); //ʵ�־��������ִ��
private:
	Receiver* m_pReceiver;
};
