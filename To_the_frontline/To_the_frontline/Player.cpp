#include "Player.h"

Player::Player()
{
	catle  = 0;
	power = 1000;
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

	
	printf(" ");

	SetTextColor(12);
	printf("이름 : %s          ", pname.c_str());
	
	SetTextColor(15);
	for (int i = 0; i < 8-pname.size(); i++)
		printf(" ");

	printf("#");

	GoToXY(x, y + 3);	printf("#                          #");
	GoToXY(x, y + 4);	printf("#                          #");

	GoToXY(x, y + 5);	printf("# 성 정복 : Lv. ");
	for (int i = 0; i < 11; i++)
		printf(" ");
	
	printf("#");
	

	GoToXY(x, y + 6);	printf("#                          #");
	GoToXY(x, y + 7);	printf("############################");
}
