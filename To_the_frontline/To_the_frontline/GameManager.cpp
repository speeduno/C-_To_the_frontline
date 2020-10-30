#include "GameManager.h"
#include "Title.h"
#include "Start.h"
#include "Lobby.h"
#include "Battle.h"
#include "Barracks.h"
#include "Recon.h"
#include "Recruit.h"
#include "Upgrade.h"

GameManager::GameManager()
{
	ArmyList = new vector<MyArmy*>;
	LoadArmyList(ArmyList, "./data/Start_MyArmy.txt");
	
	EnermyList = new vector<EnermyArmy*>;
	LoadEnermyList(EnermyList, "./data/Start_EnermyArmy.txt");

	EquipList = new vector<Equip*>;
	LoadEquipList(EquipList, "./data/Start_Equip.txt");

	MySpecial = new SpecialArmy();

	MyPlayer = new Player();
	LoadPlayerInfo(MyPlayer, "./data/Player_Info.txt");

	SceneList.reserve(8);

	Title* title = new Title(TITLE, "< TITLE >");
	SceneList.push_back(title);

	Start* start = new Start(START, "< START >");
	SceneList.push_back(start);

	Lobby* lobby = new Lobby(LOBBY, "< LOBBY >");
	SceneList.push_back(lobby);

	Battle* battle = new Battle(BATTLE, "< BATTLE >");
	SceneList.push_back(battle);

	Barracks* barracks = new Barracks(BARRACKS, "< BARRACKS >");
	SceneList.push_back(barracks);

	Recon* recon = new Recon(RECON, "< RECON >");
	SceneList.push_back(recon);

	Recruit* recruit = new Recruit(RECRUIT, "< RECRUIT >");
	SceneList.push_back(recruit);

	Upgrade* upgrade = new Upgrade(UPGRADE, "< UPGRADE >");
	SceneList.push_back(upgrade);

	CurrScene = SceneList[(int)TITLE];		// TITLE æ¿¿∏∑Œ Ω√¿€
}

GameManager::~GameManager()
{
	for (int i = 0; i < (int)ArmyList->size(); i++)
	{
		if ((*ArmyList)[i] != NULL)
		{
			delete (*ArmyList)[i];
			(*ArmyList)[i] = NULL;
		}
	}
	ArmyList->clear();

	for (int i = 0; i < (int)EquipList->size(); i++)
	{
		if ((*EquipList)[i] != NULL)
		{
			delete (*EquipList)[i];
			(*EquipList)[i] = NULL;
		}
	}
	EquipList->clear();

	if (MyPlayer != NULL)
	{
		delete MyPlayer;
		MyPlayer = NULL;
	}
}

vector<MyArmy*>* GameManager::GetArmyList()
{
	return ArmyList;
}

void GameManager::SetArmyList(vector<MyArmy*>* list)
{
	ArmyList = list;
}

vector<EnermyArmy*>* GameManager::GetEnermyList()
{
	return EnermyList;
}

void GameManager::SetEnermyList(vector<EnermyArmy*>* list)
{
	EnermyList = list;
}

vector<Equip*>* GameManager::GetEquipList()
{
	return EquipList;
}

void GameManager::SetEquipList(vector<Equip*>* list)
{
	EquipList = list;
}

SpecialArmy* GameManager::GetSpecialList()
{
	return MySpecial;
}

void GameManager::SetSpecailList(SpecialArmy* special)
{
	MySpecial = special;
}

Player* GameManager::GetPlayerInfo()
{
	return MyPlayer;
}

void GameManager::SetPlayerInfo(Player* player)
{
	MyPlayer = player;
}

void GameManager::AddPlayerGold(int g)
{
	//MyPlayer->gold += g;
}

Scene* GameManager::GetCurrScene()
{
	return CurrScene;
}

void GameManager::SetCurrScene(Scene* scene)
{
	CurrScene = scene;
}

void GameManager::changeScene(SCENE_TYPE scType)
{
	CurrScene->Destroy();

	CurrScene = SceneList[(int)scType];
	CurrScene->Init();
	CurrScene->Update();
}

//void GameManager::ReturnScene(SCENE_TYPE scType)
//{
//	CurrScene->Destroy();
//
//	CurrScene = SceneList[(int)scType];
//	CurrScene->Init();
//	CurrScene->Update();
//}

void GameManager::Init()
{
	CurrScene->Init();
}

void GameManager::Update()
{
	CurrScene->Update();
}

void GameManager::Draw()
{
	CurrScene->Draw();
}

void GameManager::Destroy()
{
	CurrScene->Destroy();
}

void GameManager::Release()
{
	delete instance;
	instance = NULL;
}

GameManager* GameManager::instance = nullptr;