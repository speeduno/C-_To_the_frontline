#pragma once
#include "info.h"

enum ARMY_TYPE
{
	FOOTMAN = 0,
	BOWMAN,
	KNIGHT,
	GENERAL,
	SNIPER,
	SCOUT,
};


class Player
{
public:
	string pname;
	int namesize;
	string title;
	int titlesize;
	int catle;
	int gold;
	int power;

public:
	Player();
	~Player();

public:
	void PrintPlayerInfo(SHORT x, SHORT y);
};