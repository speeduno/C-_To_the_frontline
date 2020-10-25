#pragma once
#include "info.h"

class Player
{
public:
	string pname;
	int catle;
	int power;

public:
	Player();
	~Player();

public:
	void PrintPlayerInfo(SHORT x, SHORT y);
};