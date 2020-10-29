#pragma once
#include "Info.h"

enum EQUIP_TYPE
{
	SWORD = 0,
	BOW,
	SPEAR,
};

class Equip
{
public:
	string name;
	int name_length;
	int type;
	int level;
	float atk;
	float speed;
	float def;

public:
	Equip();
	~Equip();
	Equip(const Equip& equip);		// ���� ���� ������

public :
	void PrintInfo(SHORT x, SHORT y);

};

