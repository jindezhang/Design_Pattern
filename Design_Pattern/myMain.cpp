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

int main( int argc, char* argv[] )
{
	main_Tempalate2();
}