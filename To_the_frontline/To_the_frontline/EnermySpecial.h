#pragma once
#include "SpecialArmy.h"

class EnermySpecial : public SpecialArmy
{
public:
	EnermySpecial();
	~EnermySpecial();
	EnermySpecial(const EnermySpecial& army);		// ���� ���� ������

public:
	virtual	void PrintSpecial(SHORT x, SHORT y);

};

