#include "Factory.h"
#include <stdlib.h>
#include "AbstractFactory.h"
#include "Builder.h"
#include "prototype.h"

void test_Factory(){
	Creator *p = new ConcreateCreator();
	ConcreateProduct* pro = ( ConcreateProduct* )p->FactoryMethod();
	pro->fly();
	pro->run();
	delete pro;
	delete p;
	//system( "pause" );
}

int test_abstractFactory(){
	// 生产产品A的第一种实现
	ConcreateFactory1 *pFactory1 = new ConcreateFactory1;
	AbstractProductA *pProductA = pFactory1->CreateProductA();
	// 生产产品B的第二种实现
	ConcreateFactory2 *pFactory2 = new ConcreateFactory2;
	AbstractProductB *pProductB = pFactory2->CreateProductB();
	delete pFactory1;
	delete pProductA;
	delete pFactory2;
	delete pProductB;
	return 0;
}
int test_Builder()
{
	Builder * pBuilder1 = new ConcreateBuilder1;
	//pBuilder1->BuilderPartA();
	
	Director * pDirector1 = new Director( pBuilder1 );
	pDirector1->Construct();
	Builder * pBuilder2 = new ConcreateBuilder2;
	Director * pDirector2 = new Director( pBuilder2 );
	pDirector2->Construct();
	delete pDirector1;
	delete pDirector2;
	
	return 0;
}

int test_prototype()
{
	Prototype* pPrototype1 = new ConcreatePrototype1();
	Prototype* pPrototype2 = pPrototype1->Clone();
	Prototype* pPrototype3 = new ConcreatePrototype2();
	Prototype* pPrototype4 = pPrototype3->Clone();
	delete pPrototype1;
	delete pPrototype2;
	delete pPrototype3;
	delete pPrototype4;
	
	return 0;
}

#include "Adapter.h"
int main_Adapter()
{
	Adaptee *pAdaptee = new Adaptee;
	Target *pTarget = new Adapter( pAdaptee );
	pTarget->Request();
	delete pTarget;
	
	return 0;
}

#include "Bridge.h"
#include <stdlib.h>
int main_Bridge()
{
	ConcreateImplementorA *pImplA = new ConcreateImplementorA();
	Abstraction *pAbstraction1 = new Abstraction( pImplA );
	pAbstraction1->Operation();
	ConcreateImplementorB *pImplB = new ConcreateImplementorB();
	Abstraction *pAbstraction2 = new Abstraction( pImplB );
	pAbstraction2->Operation();
	delete pAbstraction1;
	delete pAbstraction2;
	system( "pause" );
	return 0;
}

#include "Composite.h"
#include <stdlib.h>
int main_Composite()
{
	Leaf *pLeaf1 = new Leaf();
	Leaf *pLeaf2 = new Leaf();
	Composite* pComposite = new Composite;
	pComposite->Add( pLeaf1 );
	pComposite->Add( pLeaf2 );
	pComposite->Operation();
	pComposite->GetChild( 2 )->Operation();
	delete pComposite;
	

	return 0;
}

#include "Decorator.h"
#include <stdlib.h>
int main_Decorator()
{
	// 初始化一个Component对象
	Component2* pComponent = new ConcreateComponent();
	// 采用这个Component对象去初始化一个Decorator对象,
	// 这样就可以为这个Component对象动态添加职责
	Decorator* pDecorator = new ConcreateDecorator( pComponent );
	pDecorator->Operation();
	delete pDecorator;
	system( "pause" );
	return 0;
}

#include "Decorator_2.h"
void main_Decorator2()
{
	hero* he = new BlindMonk( "gai" );
	Skills* skills = new Skills( he );
	Skill_q* r = new Skill_q( skills, "猛龙摆尾" );
	Skill_q* e = new Skill_q( r, "天雷破/摧筋断骨" );
	Skill_q* w = new Skill_q( e, "金钟罩/铁布衫" );
	
	Skill_q* q = new Skill_q( w, "天音波/回音击" );
	q->learnSkills();
}

#include "Proxy2.h"
void main_Proxy2()
{
	Image *image = new ProxyImage( "test_10.jpg" );
	image->display();
	std::cout << std::endl;
	image->display();
	delete image;
}

#include "TemplateMethod2.h"
void main_Tempalate2()
{
	Game* game = new Cricket();

	game->play();
	std::cout << std::endl;
	delete game;
	game = new Football();
	game->play();
	delete game;

	/*Football* ggame = new Football();
	ggame->play();
	delete ggame;*/
}

#include "ChainOfResponsibility.h"
#include <stdlib.h>
int main_ChainOR()
{
	Handler *p1 = new ConcreateHandler1();
	Handler *p2 = new ConcreateHandler2( p1 );
	p2->HandleRequset();
	delete p2;
	return 0;	
}

/*
#include "FlyWeight.h"
int main_Flyweight()
{
	FlyweightFactory flyweightfactory;
	flyweightfactory.GetFlyweight( "hello" );
	flyweightfactory.GetFlyweight( "world" );
	flyweightfactory.GetFlyweight( "hello" );
	//system( "pause" );
	return 0;
}*/

/*
#include "Flyweight2.h"
#include <time.h>
#include <stdlib.h>

void main_Flyweight2()
{
	std::string color[] = { "Red", "Green", "Blue", "White", "Black" };
	srand((int)time(0));
	auto f = []( int m, int n )->int{ return ( rand() % ( n - m + 1 ) + m ); };
	ShapeFactory shapeFactory;
	for ( int i = 0; i < 20; i++ )
	{
		Circle* circle = ( Circle * )shapeFactory.GetShape( color[ f( 0, 4 ) ] );
		circle->setX( f( 0, 100 ) );
		circle->setRadius( 100 );
		circle->setY( f( 0, 100 ) );
		circle->Draw();
	}
	
}*/

#include "Command.h"
#include <stdlib.h>
int main_Command()
{
	Receiver* pReceiver = new Receiver();
	Command* pCommand = new ConcreateComand( pReceiver );
	Invoker* pInvoker = new Invoker( pCommand );
	pInvoker->Invoke();
	delete pInvoker;
	
	return 0;
}

#include "Command2.h"
void main_Command2()
{
	Stock *stock = new Stock( "ak", 100 );
	Order* pbuy = new BuyStock( stock );
	Order* psell = new SellStock( stock );
	Broker* pbroker = new Broker();
	pbroker->takeOrder( pbuy );
	pbroker->takeOrder( psell );

	pbroker->placeOrder();
	delete pbroker;
	delete stock;
	std::cout << "pause\n";
}

#include "Observer.h"
#include <iostream>
int main_Observer()
{
	Observer *p1 = new ConcreateObserver();
	Observer *p2 = new ConcreateObserver();
	SubjectOb* p = new ConcreateSubject();
	p->Attach( p1 );
	p->Attach( p2 );
	p->SetState( 4 );
	p->Notify();
	p->Detach( p1 );
	p->SetState( 10 );
	p->Notify();
	delete p;
	
	return 0;
}

#include "Strategy.h"
#include <memory>
void main_Strategy()
{
	//std::shared_ptr<T> p1 = std::make_shared<T>();
	std::shared_ptr<Context> context = std::make_shared<Context>( new OperationAdd() );
	//context = new Context( new OperationAdd() );
	std::cout << "10 + 5 = " << context->executeStategy( 10, 5 ) << std::endl;

	context->setStategy(new OperationSub() );
	std::cout << "10 - 5 = " << context->executeStategy( 10, 5 ) << std::endl;
	
}

#include "State.h"
/*智能指针的问题*/
void main_State()
{
	std::shared_ptr<Contexts> context = std::make_shared<Contexts>();
	std::shared_ptr<StartState>startstate = std::make_shared<StartState>();
	startstate->doAction( context );

	printf( "startstate : 0x%x\n", startstate.get() );
	printf( "context : 0x%x\n", context.get() );
	std::cout <<startstate.use_count()<<" "<< context->getState()->toString();
	
	/*std::shared_ptr<StopState> stopstate = std::make_shared<StopState>();
	std::shared_ptr<StopState> stopstate1 = stopstate;
	/ *StopState* stopstate = new StopState();
	StopState* stopstate1 = stopstate;* /
	stopstate->doAction( context );
	//std::cout << stopstate.use_count() << " " << context->getState()->toString();
	printf( "0x%x\n", stopstate.get() );
	printf( "0x%x\n", stopstate1.get() );
	printf( "0x%p\n", stopstate.get() );
	printf( "0x%p\n", stopstate1.get() );

	
	std::cout << "\n" << stopstate << " ," 
		<< stopstate1 << " ,\n";*/
}

#include "Iterator.h"
void main_Iterator2()
{
	std::shared_ptr<ConcreateAggregate> aggregate = std::make_shared<ConcreateAggregate>( 4 );
	ConcreateIterater2<ConcreateAggregate> iteator( aggregate );
	while (!iteator.IsDone())
	{
		std::cout << iteator.CurrentItem() << std::endl;
		iteator.Next();
	}

}
#include "Iterator.h"
#include <iostream>
int main_Iterator()
{
	Aggregate* pAggregate = new ConcreateAggregate( 4 );
	Iterater* pIterater = new ConcreateIterater( pAggregate );
	for ( ; false == pIterater->IsDone(); pIterater->Next() )
	{
		std::cout << pIterater->CurrentItem() << std::endl;
	}
	return 0;
}

//测试=delete 在类中的作用
class Foo
{
public:
	void show(){ std::cout << "Foo\n"; }
	void* operator new(std::size_t) = delete;
};
void main_Foo()
{
	Foo f;
	f.show();
	//Foo ff = new Foo();//出错

}
////////////////////////////////////

//智能指针shared_ptr 的存在问题
#include <memory>
class TestB;
class TestA
{
public:
	TestA()
	{
		std::cout << "TestA()" << std::endl;
	}
	void ReferTestB( std::shared_ptr<TestB> test_ptr )
	{
		m_TestB_Ptr = test_ptr;
	}
	~TestA()
	{
		std::cout << "~TestA()" << std::endl;
	}
private:
	std::shared_ptr<TestB> m_TestB_Ptr; //TestB的智能指针
};

class TestB
{
public:
	TestB()
	{
		std::cout << "TestB()" << std::endl;
	}

	void ReferTestB( std::shared_ptr<TestA> test_ptr )
	{
		std::cout << "\n count:" << test_ptr.use_count();
		m_TestA_Ptr = test_ptr;
		std::cout << "\n m_T:" << m_TestA_Ptr;
		std::cout << "\n t_T:" << test_ptr;
		std::cout << "\n count:" << test_ptr.use_count();
	}
	~TestB()
	{
		std::cout << "~TestB()" << std::endl;
	}
	std::shared_ptr<TestA> m_TestA_Ptr; //TestA的智能指针
};


int main_shared()
{
	std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
	std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
	std::cout << "\n ptr_a:" << ptr_a.use_count();
	ptr_a->ReferTestB( ptr_b );
	ptr_b->ReferTestB( ptr_a );
	std::cout << "\n ptr_a:" << ptr_a.use_count();
	return 0;
}
//-----------------------------------------

//----------C---
#include<stdio.h>
void _scanf( float* i )
{
	scanf_s( "%f", i );
}


//备忘录模式学习
#include "Memento.h"
void main_Memento()
{
	// 创建一个原发器
	Originator* pOriginator = new Originator( "#1 state" );
	CareTaker* taker = new CareTaker();
	Memento* pMemento;
	/*pOriginator->PrintState();
	// 创建一个备忘录存放这个原发器的状态
	pMemento = pOriginator->CreateMemento();
	taker->add( pMemento );*/
	// 更改原发器的状态
	pOriginator->SetState( "#2 state" );
	//pOriginator->PrintState();
	taker->add( pOriginator->CreateMemento() );

	pOriginator->SetState( "#3 state" );
	//pOriginator->PrintState();
	taker->add( pOriginator->CreateMemento() );

	pOriginator->SetState( "#4 state" );
	pOriginator->PrintState();

	
	// 通过备忘录把原发器的状态还原到之前的状态
	pMemento = taker->get( 0 );
	pOriginator->RestoreState( pMemento );
	pOriginator->PrintState();

	pMemento = taker->get( 1 );
	pOriginator->RestoreState( pMemento );
	pOriginator->PrintState();
	delete pOriginator;
	delete taker;
}

//访问者模式的测试
#include "Visitor2.h"
void main_Visitor()
{
	ComputerPart* computer = new Computer();
	ComputerPartVisitor* visit = new ComputerPartDisplayVisitor();
	computer->accept( visit );

	delete visit;
	delete computer;
}


//外观模式Demo
#include "Facade.h"
void main_Facade()
{
	ShapeMaker* shapemaker = new ShapeMaker();
	shapemaker->drawCircle();
	shapemaker->drawRectangle();
	shapemaker->drawSquare();
}

int main( int argc, char* argv[] )
{
	main_Facade();
	//main_shared();
	std::cout << "\n main\n";

	/*//-----test c 
	float i = 0;
	_scanf( &i );
	std::cout << "i:" << i;*/
	
	//智能指针的学习。包含计数值学习，对应的指向地址学习，以及get()的学习。
	/*std::shared_ptr<StopState> stopstate = std::make_shared<StopState>();
	std::shared_ptr<StopState> stopstate1 = stopstate;
	std::shared_ptr<StopState> stopstate2 = std::make_shared<StopState>();
	std::shared_ptr<StopState> stopstate3 = stopstate2;
	/ *StopState* stopstate4 = new StopState();
	StopState stopstate5 = *stopstate4;* /
	std::cout << "\n" << stopstate << " ," << stopstate1 << " ,"
		<< stopstate2 << " ," << stopstate3 << " ,\n";
	std::cout << "\n" << stopstate.use_count() <<
		" ," << stopstate1.use_count() << " ,"
		<< stopstate2.use_count() << " ,"
		<< stopstate3.use_count() << " ,\n";

	std::cout << "-------------------"
		<<"---------------- ";
	stopstate = stopstate3;
	std::cout << "\n" << stopstate << " ," << stopstate1 << " ,"
		<< stopstate2 << " ," << stopstate3 << " ,\n";
	std::cout << "\n" << stopstate.use_count() <<
		" ," << stopstate1.use_count() << " ,"
		<< stopstate2.use_count() << " ,"
		<< stopstate3.use_count() << " ,\n";
	printf( "0x%x\n", stopstate.get() );
	printf( "0x%x\n", stopstate1.get() );
	printf( "0x%p\n", stopstate2.get() );
	printf( "0x%p\n", stopstate3.get() );*/
	/*delete stopstate4;*/
}