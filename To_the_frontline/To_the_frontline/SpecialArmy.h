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
	SpecialArmy(const SpecialArmy& army);		// 깊은 복사 생성자

public:
	virtual void PrintSpecial(SHORT x, SHORT y) = 0 {}
};

