#pragma once
#include "SpecialArmy.h"

class MySpecial : public SpecialArmy
{
public:
	MySpecial();
	~MySpecial();
	MySpecial(const MySpecial& army);		// 깊은 복사 생성자

public:
	virtual	void PrintSpecial(SHORT x, SHORT y);

};

