#pragma once
#include "info.h"

enum ARMY_TYPE
{
	FOOTMAN = 0,
	BOWMAN,
	KNIGHT,
};

class Army
{
public:
	string name;
	int name_length;
	int type; //0.보병 1.궁병 2.기병, 3정찰병, 4저격수, 5장군
	int level;
	int hp;		 //군사수
	int max_hp;
	float damage;
	float maxdamage;
	int speed;

	//추가사항
	int supplycost;
	int morale;			//사기치는 한계가 없다.


public:
	Army();
	~Army();
	Army(const Army& army);		// 깊은 복사 생성자

	virtual void PrintInfo(SHORT x, SHORT y) = 0 {};
};

