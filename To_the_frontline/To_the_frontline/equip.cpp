#include "Equip.h"

Equip::Equip()
{
}

Equip::~Equip()
{
}

Equip::Equip(const Equip& equip)
{
}

void Equip::PrintInfo(SHORT x, SHORT y)
{
	SetTextColor(15);
	GoToXY(x, y);	printf("############################");
	GoToXY(x, y + 1);	printf("#                          #");

	GoToXY(x, y + 2);
	printf("#");

	for (int i = 0; i < (13 - name_length); i++)
		printf(" ");

	SetTextColor(12);
	printf("%s", name.c_str());

	SetTextColor(15);
	for (int i = 0; i < (13 - name_length); i++)
		printf(" ");
	printf("#");

	GoToXY(x, y + 3);	printf("#                          #");

	GoToXY(x, y + 4);	printf("# 레벨   %d                 #", level);
	GoToXY(x, y + 5);	printf("# 공격력 : ");

	for (int i = 0; i < 16 - atk * 10; i++)
	{
		if ((atk *10) > i)
			printf("■");

		else
			printf(" ");
	}

	printf("#");


	GoToXY(x, y + 6);	printf("# 방어력 : ");
	for (int i = 0; i < 16 - (def * 10); i++)
	{
		if ((def * 10) > i)
			printf("■");
		else
			printf(" ");
	}
	printf("#");

	GoToXY(x, y + 7);	printf("# 스피드 : ");
	for (int i = 0; i < 16 - speed * 10; i++)
	{
		if (speed * 10 > i)
			printf("■");
		else
			printf(" ");
	}
	printf("#");

	GoToXY(x, y + 8);	printf("#                          #");
	GoToXY(x, y + 9);	printf("############################");
}
