#pragma once
#include "Army.h"

class SpecialArmy :public Army
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

