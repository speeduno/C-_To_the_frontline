#pragma once
#include "SpecialArmy.h"

class MySpecial : public SpecialArmy
{
public:
	MySpecial();
	~MySpecial();
	MySpecial(const MySpecial& army);		// ���� ���� ������

public:
	virtual	void PrintSpecial(SHORT x, SHORT y);

};

