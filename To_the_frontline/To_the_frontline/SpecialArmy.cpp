#include "SpecialArmy.h"
#include "Info.h"

SpecialArmy::SpecialArmy()
{
	general = 0;
	sniper = 0;
	recon = 5;
}

SpecialArmy::~SpecialArmy()
{
}


void SpecialArmy::Printspecal(SHORT x, SHORT y)
{
	SetTextColor(15);
	GoToXY(x, y);	printf("############################");
	GoToXY(x, y + 1);	printf("#                          #");

	GoToXY(x, y + 2);
	printf("#");

	for (int i = 0; i < 9; i++)
		printf(" ");

	SetTextColor(12);
	printf("특수");

	SetTextColor(15);
	for (int i = 0; i < 13; i++)
		printf(" ");
	printf("#");

	GoToXY(x, y + 3);	printf("#                          #");
	GoToXY(x, y + 4);	printf("# 보유 장  군 : %d          #",general);
	GoToXY(x, y + 5);	printf("#                          #");

	GoToXY(x, y + 6);	printf("# 보유 저격수 : %d          #", sniper);
	
	GoToXY(x, y + 7);	printf("# 보유 정찰병 : %d          #", recon);
	
	GoToXY(x, y + 8);	printf("#                          #");
	GoToXY(x, y + 9);	printf("############################");
}
