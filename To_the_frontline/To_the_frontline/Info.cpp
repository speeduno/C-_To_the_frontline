#include "Info.h"
#include "Player.h"
#include "Army.h"
#include "Equip.h"

void GoToXY(SHORT x, SHORT y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetCursorVisible(bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bVisible;			// true 보임, false 안보임
	ConsoleCursor.dwSize = 1;					// 커서사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void SetTextColor(int num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

void LoadArmyList(vector<Army*>* ArmyList, string FileName)
{
	FILE* pRead = fopen(FileName.c_str(), "rt");

	if (pRead != NULL)
	{
		int count = 0;
		fscanf(pRead, "%d", &count);

		for (int i = 0; i < count; i++)
		{
			Army* p = new Army();

			fscanf(pRead, "%d %s %d %d %d %d %f %f %d %d %d",
				&(p->name_length), p->name.c_str(), &(p->type) ,&(p->level), &(p->hp), &(p->max_hp), 
				&(p->damage), &(p->maxdamage), &(p->speed), &(p->supplycost), &(p->morale));

			ArmyList->push_back(p);
		}
	}

	else
	{
		FILE* pWrite = fopen(FileName.c_str(), "wt");
		fprintf(pWrite, "%d\n", 0);
		fclose(pWrite);
	}

	fclose(pRead);
}

//void SavePoketmonList(vector<Poketmon*>* PoketmonList, string FileName)
//{
//	FILE* pWrite = fopen(FileName.c_str(), "wt");
//	if (pWrite != NULL)
//	{
//		fprintf(pWrite, "%d\n", (int)PoketmonList->size());
//
//		for (int i = 0; i < (int)PoketmonList->size(); i++)
//		{
//			fprintf(pWrite, "%d %s %d %d %d %d %d %d %d %d %d\n",
//				(*PoketmonList)[i]->name_length, (*PoketmonList)[i]->name.c_str(),
//				(*PoketmonList)[i]->level, (*PoketmonList)[i]->hp, (*PoketmonList)[i]->max_hp,
//				(*PoketmonList)[i]->damage, (*PoketmonList)[i]->origin_price, (*PoketmonList)[i]->exp,
//				(*PoketmonList)[i]->damage_up, (*PoketmonList)[i]->hp_up, (*PoketmonList)[i]->drop_rate);
//		}
//	}
//	else
//	{
//		printf("PlayerInfo.txt파일을 저장할 수 없습니다\n");
//	}
//
//	fclose(pWrite);
//}

void LoadPlayerInfo(Player* player, string FileName)
{
	FILE* pRead = fopen(FileName.c_str(), "rt");

	if (pRead != NULL)
	{
		//Player* p = new Player();

		fscanf(pRead, "%d %d %d %d %d %s %s",
			&(player->catle), &(player->gold), &(player->power), &(player->namesize), &(player->titlesize),
			player->pname.c_str(), player->title.c_str());
	}

	else
	{
		FILE* pWrite = fopen(FileName.c_str(), "wt");
		fprintf(pWrite, "%d\n", -1);
		fclose(pWrite);
	}

	fclose(pRead);
}

//void SavePlayerInfo(Player* player, string FileName)
//{
//	FILE* pWrite = fopen(FileName.c_str(), "wt");
//	if (pWrite != NULL)
//	{
//		fprintf(pWrite, "%d %d %d %d %d %s %s",
//			player->level, player->gold, player->exp, player->next_exp, player->stage_num, player->title.c_str(), player->name.c_str());
//	}
//	else
//	{
//		printf("PlayerInfo.txt파일을 저장할 수 없습니다\n");
//	}
//
//	fclose(pWrite);
//}

void LoadEquipList(vector<Equip*>* EquipList, string FileName)
{
	FILE* pRead = fopen(FileName.c_str(), "rt");

	if (pRead != NULL)
	{
		int count = 0;
		fscanf(pRead, "%d", &count);

		for (int i = 0; i < count; i++)
		{
			Equip* p = new Equip();

			fscanf(pRead, "%d %s %d %d %f %f %f",
				&(p->name_length), p->name.c_str(), &(p->type), &(p->level),
				&(p->atk), &(p->def), &(p->speed));

			EquipList->push_back(p);
		}
	}

	else
	{
		FILE* pWrite = fopen(FileName.c_str(), "wt");
		fprintf(pWrite, "%d\n", 0);
		fclose(pWrite);
	}

	fclose(pRead);

}
