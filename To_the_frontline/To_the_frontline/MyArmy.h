#pragma once
#include "Army.h"

class MyArmy :public Army
{


public:
	MyArmy();
	~MyArmy();
	MyArmy(const MyArmy& myarmy);		// 깊은 복사 생성자

public:
	void PrintInfo(SHORT x, SHORT y);
};

