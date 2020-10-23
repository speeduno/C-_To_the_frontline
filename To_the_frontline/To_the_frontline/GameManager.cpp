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
	//PoketmonList = new vector<Poketmon*>;
	//LoadPoketmonList(PoketmonList, "./data/PoketmonList.txt");

	//StageList = new vector<Stage*>;
	//LoadStageList(StageList, "./data/StageList.txt");

	//MyPlayer = new Player();
	//LoadPlayerInfo(MyPlayer, "./data/PlayerInfo.txt");

	//CurrStage = (*StageList)[MyPlayer->stage_num];

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

	CurrScene = SceneList[(int)TITLE];		// TITLE ������ ����
}

GameManager::~GameManager()
{
	for (int i = 0; i < (int)PoketmonList->size(); i++)
	{
		if ((*PoketmonList)[i] != NULL)
		{
			delete (*PoketmonList)[i];
			(*PoketmonList)[i] = NULL;
		}
	}
	PoketmonList->clear();

	if (MyPlayer != NULL)
	{
		delete MyPlayer;
		MyPlayer = NULL;
	}
}

vector<Poketmon*>* GameManager::GetPoketmonList()
{
	return PoketmonList;
}

void GameManager::SetPoketmonList(vector<Poketmon*>* list)
{
	PoketmonList = list;
}

vector<Stage*>* GameManager::GetStageList()
{
	return StageList;
}

Stage* GameManager::GetCurrStage()
{
	return CurrStage;
}

void GameManager::SetCurrStage()
{
	//CurrStage = (*GetStageList())[MyPlayer->stage_num];
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