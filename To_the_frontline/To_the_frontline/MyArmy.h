#pragma once
#include "Player.h"

class MyArmy :public Player
{ 
public:
	string name;
	int name_length;
	int level;
	int hp;		//�����
	int max_hp;
	int damage;
	int type; //0.���� 1.���� 2.�⺴, 3������, 4���ݼ�, 5�屺


public:
	MyArmy();
	~MyArmy();
	MyArmy(const MyArmy& army);		// ���� ���� ������

	void PrintInfo(SHORT x, SHORT y);
};

