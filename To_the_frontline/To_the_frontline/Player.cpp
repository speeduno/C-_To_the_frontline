#include "Player.h"

Player::Player()
{
	pname = "�̸�";
	catle = 0;
	power = 0;
}

Player::~Player()
{
}

void Player::PrintPlayerInfo(SHORT x, SHORT y)
{
	SetTextColor(15);
	GoToXY(x, y);	printf("############################");
	GoToXY(x, y + 1);	printf("#                          #");

	GoToXY(x, y + 2);
	printf("#");

	for (int i = 0; i < 13; i++)
		printf(" ");

	SetTextColor(12);
	printf("�̸� : %s", pname.c_str());

	SetTextColor(15);
	for (int i = 0; i < (13); i++)
		printf(" ");
	printf("#");

	GoToXY(x, y + 3);	printf("#                          #");
	GoToXY(x, y + 4);	printf("#                          #");

	GoToXY(x, y + 5);	printf("# ���� �� ����   %d                 #", catle);
	


	GoToXY(x, y + 5);	printf("#                          #");
	GoToXY(x, y + 6);	printf("############################");
}
