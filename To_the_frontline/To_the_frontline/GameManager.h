#pragma once
#include "Info.h"
#include "player.h"
#include "MyArmy.h"
#include "EnermyArmy.h"
#include "MySpecial.h"
#include "EnermySpecial.h"
#include "Equip.h"

enum SCENE_TYPE
{
	TITLE = 0,
	START,
	LOBBY,
	BATTLE,
	BARRACKS,
	RECON,
	RECRUIT,
	UPGRADE,
};

class Scene;
class Plyaer;
class MyArmy;
class EnermyArmy;
class MySpecial;
class EnermySpecial;
class Equip;

class GameManager
{
private:
	static GameManager* instance;

	vector<Scene*>		SceneList;		// 전체 씬 리스트
	Scene* CurrScene;					// 현재 활성화된 씬. 이 변수의 내용을 초기화하면서 씬의 이동 구현

	vector<MyArmy*>* ArmyList;			// 소유 군사 리스트
	vector<EnermyArmy*>* EnermyList;	// 소유 군사 리스트
	MySpecial* MySpecialA;				// 스페셜리스트
	EnermySpecial* EnermySpecialA;		// 스페셜리스트
	vector<Equip*>* EquipList;			// 장비리스트
	Player* MyPlayer;					// 플레이어 정보
	GameManager();
	~GameManager();

public:

	static GameManager* getInstance()
	{
		if (instance == nullptr)
			instance = new GameManager();

		return instance;
	}

	vector<MyArmy*>* GetArmyList();
	void SetArmyList(vector<MyArmy*>* list);

	vector<EnermyArmy*>* GetEnermyList();
	void SetEnermyList(vector<EnermyArmy*>* list);

	MySpecial* GetMySpecialList();
	void SetMySpecailList(MySpecial*  special);

	EnermySpecial* GetEnermySpecialList();
	void SetEnermySpecailList(EnermySpecial* special);

	vector<Equip*>* GetEquipList();
	void SetEquipList(vector<Equip*>* list);

	Player* GetPlayerInfo();
	void SetPlayerInfo(Player* player);
	void AddPlayerGold(int g);

	Scene* GetCurrScene();
	void SetCurrScene(Scene* scene);

	void changeScene(SCENE_TYPE scType);		// 현재 위치한 씬을 특정 씬으로 바꾸는 함수 
	//void ReturnScene(SCENE_TYPE scType);		// 이전의 씬으로 바꾸는 함수

	void Init();
	void Update();
	void Draw();
	void Destroy();

	void Release();
};