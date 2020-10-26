#include "Player.h"

Player::Player()
{
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
	printf("이  름 : %s", pname.c_str());

	SetTextColor(15);
	for (int i = 0; i < 16 - namesize; i++)			
		printf(" ");

	printf("#");

	GoToXY(x, y + 3);	printf("#                          #");
	GoToXY(x, y + 4);	printf("#                          #");

	GoToXY(x, y + 5);	printf("# 성등급 : Lv. %d", catle);
	int temp = 1;
	for (int i = 1; i < catle; i = pow(10, temp))
	{
		temp++;
	}

	for (int i = 0; i < 12 - temp; i++)
		printf(" ");
	printf("#");

	GoToXY(x, y + 6);	printf("# 칭  호 : %s", title.c_str());
	for (int i = 0; i < 16 - titlesize; i++)			
		printf(" ");

	printf("#");

	GoToXY(x, y + 7);	printf("# 전투력 : %d", power);

	temp = 1;
	for (int i = 1; i <= power; i = pow(10, temp))
	{
		temp++;			
	}

	for (int i = 0; i < 16- temp; i++)
		printf(" ");
	printf("#");

	GoToXY(x, y + 8);	printf("# 골  드 : %d", gold);
	temp = 1;
	for (int i = 1; i <= gold; i = pow(10, temp))
	{
		temp++;		
	}

	for (int i = 0; i < 16 - temp; i++)
		printf(" ");
	printf("#");
		

	GoToXY(x, y + 9);	printf("#                          #");
	GoToXY(x, y + 10);	printf("############################");
}
