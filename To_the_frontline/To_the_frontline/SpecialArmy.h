#pragma once
#include "Info.h"

class SpecialArmy
{
public:
	int general;
	int recon;
	int sniper;	

public:
	SpecialArmy();
	~SpecialArmy();
	SpecialArmy(const SpecialArmy& army);		// ���� ���� ������

public:
	virtual void PrintSpecial(SHORT x, SHORT y) = 0 {}
};

