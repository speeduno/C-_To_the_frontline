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
	SpecialArmy(const SpecialArmy& army);		// 깊은 복사 생성자

	void Printspecal(SHORT x, SHORT y);
};

