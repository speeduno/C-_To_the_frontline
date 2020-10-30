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
	int type; //0.���� 1.�ú� 2.�⺴, 3������, 4���ݼ�, 5�屺
	int level;
	int hp;		 //�����
	int max_hp;
	float damage;
	float maxdamage;
	int speed;

	//�߰�����
	int supplycost;
	int morale;			//���ġ�� �Ѱ谡 ����.


public:
	Army();
	~Army();
	Army(const Army& army);		// ���� ���� ������

	virtual void PrintInfo(SHORT x, SHORT y) = 0 {};
};

