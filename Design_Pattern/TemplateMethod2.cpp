#include "TemplateMethod2.h"

void Game::play()
{
	initialize();
	startPlay();
	endPlay();

}

void Cricket::initialize()
{
	std::cout << "Cricket Game init.\n";

}

void Cricket::startPlay()
{
	std::cout << "Cricket start playing\n";

}

void Cricket::endPlay()
{
	std::cout << "Cricket ending play\n";
}

void Football::initialize()
{
	std::cout << "football init\n";

}

void Football::startPlay()
{
	std::cout << "football startplay\n";

}

void Football::endPlay()
{
	std::cout << "football endplay\n";
}
