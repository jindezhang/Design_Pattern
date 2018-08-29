#include <iostream>

class Game
{
public:
	Game(){}
	virtual ~Game(){}
	virtual void play() final;
protected:
	virtual void initialize() = 0;
	virtual void startPlay() = 0;
	virtual void endPlay() = 0;
};

class Cricket
	:public Game
{
public:
	
	virtual void initialize();
	virtual void startPlay();
	virtual void endPlay();
};

class Football :
	public Game
{
public:
	virtual void initialize();
	virtual void startPlay();
	virtual void endPlay();

};

#pragma once
