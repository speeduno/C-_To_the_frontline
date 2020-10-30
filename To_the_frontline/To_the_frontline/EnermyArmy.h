#pragma once
#include "Army.h"

class EnermyArmy : public Army
{


public:
	EnermyArmy();
	~EnermyArmy();
	EnermyArmy(const EnermyArmy& enermyarmy);		// 깊은 복사 생성자

public:
	void PrintInfo(SHORT x, SHORT y);
};


