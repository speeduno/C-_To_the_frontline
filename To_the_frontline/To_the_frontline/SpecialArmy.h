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

	void Printspecal(SHORT x, SHORT y);
};

