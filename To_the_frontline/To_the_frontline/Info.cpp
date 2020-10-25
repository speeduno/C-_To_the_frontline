#include "Info.h"
#include "MyArmy.h"

void GoToXY(SHORT x, SHORT y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetCursorVisible(bool bVisible)
{
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bVisible;		// true 보임, false 안보임
	ConsoleCursor.dwSize = 1;					// 커서사이즈
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}

void SetTextColor(int num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

void LoadArmyList(vector<MyArmy*>* ArmyList, string FileName)
{
	FILE* pRead = fopen(FileName.c_str(), "rt");

	if (pRead != NULL)
	{
		int count = 0;
		fscanf(pRead, "%d", &count);

		for (int i = 0; i < count; i++)
		{
			MyArmy* p = new MyArmy();

			fscanf(pRead, "%d %s %d %d %d %d %d",
				&(p->name_length), p->name.c_str(), &(p->level), &(p->hp), &(p->max_hp), &(p->damage), &(p->type));

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
		fscanf(pRead, "%d %d %d %d %d %s %s",
			&(player->level), &(player->gold), &(player->exp), &(player->next_exp), &(player->stage_num), player->title.c_str(), player->name.c_str());
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
//
//void LoadStageList(vector<Stage*>* StageList, string FileName)
//{
//	FILE* pRead = fopen(FileName.c_str(), "rt");
//
//	if (pRead != NULL)
//	{
//		int count = 0;
//		fscanf(pRead, "%d", &count);
//
//		for (int i = 0; i < count; i++)
//		{
//			Stage* s = new Stage();
//
//			char temp[MAX_STRING_SIZE];
//			fscanf(pRead, "%s %d %s", s->name.c_str(), &(s->required_level), temp);
//
//			string EnemyList_FileName = temp;
//			LoadPoketmonList(s->EnemyList, EnemyList_FileName);
//
//			StageList->push_back(s);
//		}
//	}
//
//	else
//	{
//		FILE* pWrite = fopen(FileName.c_str(), "wt");
//		fprintf(pWrite, "%d\n", 0);
//		fclose(pWrite);
//	}
//
//	fclose(pRead);
//}
//
//void LoadExpTable(vector<Exp*>* ExpTable, string FileName)
//{
//	FILE* pRead = fopen(FileName.c_str(), "rt");
//
//	if (pRead != NULL)
//	{
//		int count = 0;
//		fscanf(pRead, "%d", &count);
//
//		for (int i = 0; i < count; i++)
//		{
//			Exp* e = new Exp();
//
//			fscanf(pRead, "%d %d",
//				&(e->level), &(e->required_exp));
//
//			ExpTable->push_back(e);
//		}
//	}
//
//	else
//	{
//		FILE* pWrite = fopen(FileName.c_str(), "wt");
//		fprintf(pWrite, "%d\n", 0);
//		fclose(pWrite);
//	}
//
//	fclose(pRead);
//}
