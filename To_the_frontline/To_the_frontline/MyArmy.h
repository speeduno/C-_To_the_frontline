#pragma once
#include "Army.h"

class MyArmy :public Army
{


public:
	MyArmy();
	~MyArmy();
	MyArmy(const MyArmy& myarmy);		// ���� ���� ������

public:
	void PrintInfo(SHORT x, SHORT y);
};

