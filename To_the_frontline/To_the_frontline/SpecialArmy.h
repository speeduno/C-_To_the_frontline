#pragma once
#include "Player.h"

class SpecialArmy :public Player
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

