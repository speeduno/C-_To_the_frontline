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
	GoToXY(x, y + 4);	printf("#                          #");

	GoToXY(x, y + 5);	printf("# ·¹º§   %d                 #", level);
	GoToXY(x, y + 6);	printf("# HP     ");

	for (int i = 0; i < 18 - (hp / 5); i++)
	{
		if ((hp / 5) > i)
			printf("¡á");
		else
			printf(" ");
	}
	printf("#");


	GoToXY(x, y + 7);	printf("# DAMAGE ");
	for (int i = 0; i < 18 - damage; i++)
	{
		if (damage > i)
			printf("¡á");
		else
			printf(" ");
	}
	printf("#");

	GoToXY(x, y + 8);	printf("#                          #");
	GoToXY(x, y + 9);	printf("############################");
}


