#pragma once
#include "Army.h"

class EnermyArmy : public Army
{


public:
	EnermyArmy();
	~EnermyArmy();
	EnermyArmy(const EnermyArmy& enermyarmy);		// ���� ���� ������

public:
	void PrintInfo(SHORT x, SHORT y);
};


