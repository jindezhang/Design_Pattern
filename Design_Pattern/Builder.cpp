#include "Builder.h "
#include < iostream >

void ConcreateBuilder1::BuilderPartA()
{
	std::cout << " BuilderPartA by ConcreateBuilder1\n ";
}
void ConcreateBuilder1::BuilderPartB()
{
	std::cout << " BuilderPartB by ConcreateBuilder1\n ";
}
void ConcreateBuilder2::BuilderPartA()
{
	std::cout << " BuilderPartA by ConcreateBuilder2\n ";
}
void ConcreateBuilder2::BuilderPartB()
{
	std::cout << " BuilderPartB by ConcreateBuilder2\n ";
}
Director::Director( Builder * pBuilder )
	: m_pBuilder( pBuilder )
{
}
Director:: ~Director()
{
	delete m_pBuilder;
	m_pBuilder = NULL;
}
// Construct ������ʾһ�������������������,��ͬ�Ĳ���֮���װ�䷽ʽ����һ�µ�,
// ���ȹ���PartA�����PartB,ֻ�Ǹ��ݲ�ͬ�Ĺ����߻��в�ͬ�ı�ʾ
void Director::Construct()
{
	m_pBuilder->BuilderPartA();
	m_pBuilder->BuilderPartB();
}


