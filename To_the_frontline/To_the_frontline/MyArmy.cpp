#include "MyArmy.h"
#include "Info.h"

MyArmy::MyArmy()
{
}

MyArmy::~MyArmy()
{
}

MyArmy::MyArmy(const MyArmy& army)
{
}

void MyArmy::PrintInfo(SHORT x, SHORT y)
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
	GoToXY(x, y + 5);	printf("# 군 사 수 : ");

	for (int i = 0; i <14-(hp / 100); i++)
	{
		if ((hp / 100) > i)
			printf("■");
		else
			printf(" ");
	}
	printf("#");


	GoToXY(x, y + 6);	printf("# 전 투 력 : ");
	for (int i = 0; i < 14-(damage*2); i++)
	{
		if ((damage*2) > i)
			printf("■");
		else
			printf(" ");
	}
	printf("#");

	GoToXY(x, y + 7);	printf("# 선제공격 : ");
	for (int i = 0; i < 14 - speed; i++)
	{
		if (speed > i)
			printf("■");
		else
			printf(" ");
	}
	printf("#");

	GoToXY(x, y + 8);	printf("#                          #");
	GoToXY(x, y + 9);	printf("############################");
}

