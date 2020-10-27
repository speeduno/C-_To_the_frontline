#pragma once
#include "Player.h"

class MyArmy :public Player
{ 
public:
	string name;
	int name_length;
	int level;
	int hp;		 //군사수
	int max_hp;
	float damage;
	int speed;
	int type; //0.보병 1.궁병 2.기병, 3정찰병, 4저격수, 5장군

	int supplycost;


public:
	MyArmy();
	~MyArmy();
	MyArmy(const MyArmy& army);		// 깊은 복사 생성자

	void PrintInfo(SHORT x, SHORT y);
};

