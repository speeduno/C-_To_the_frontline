#pragma once
#include "SpecialArmy.h"

class EnermySpecial : public SpecialArmy
{
public:
	EnermySpecial();
	~EnermySpecial();
	EnermySpecial(const EnermySpecial& army);		// 깊은 복사 생성자

public:
	virtual	void PrintSpecial(SHORT x, SHORT y);

};

