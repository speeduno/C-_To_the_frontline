#include "MyArmy.h"


MyArmy::MyArmy()
{
}

MyArmy::~MyArmy()
{
}

MyArmy::MyArmy(const MyArmy& myarmy)
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

	GoToXY(x, y + 4);	printf("# ����   %d                 #", level);
	GoToXY(x, y + 5);	printf("# �� �� �� : ");

	for (int i = 0; i < 14 - (ceil((float)max_hp / 100)); i++)
	{
		if (ceil((float)hp / 100) > i)
			printf("��");

		else if (max_hp / 100 > i)
			printf("��");

		else
			printf(" ");
	}

	printf("#");


	GoToXY(x, y + 6);	printf("# �� �� �� : ");
	for (int i = 0; i < 14 - ceil(damage * 2); i++)
	{
		if ((damage * 2) > i)
			printf("��");
		else
			printf(" ");
	}
	printf("#");

	GoToXY(x, y + 7);	printf("# �������� : ");
	for (int i = 0; i < 14 - speed; i++)
	{
		if (speed > i)
			printf("��");
		else
			printf(" ");
	}
	printf("#");

	GoToXY(x, y + 8);	printf("#                          #");
	GoToXY(x, y + 9);	printf("############################");

}
