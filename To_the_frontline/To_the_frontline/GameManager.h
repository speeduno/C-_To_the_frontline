#pragma once
#include "Info.h"

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

class GameManager
{
private:
	static GameManager* instance;

	vector<Scene*>		SceneList;		// 전체 씬 리스트
	Scene* CurrScene;					// 현재 활성화된 씬. 이 변수의 내용을 초기화하면서 씬의 이동 구현

	vector<Stage*>* StageList;			// 전체 스테이지 리스트
	Stage* CurrStage;					// 현재 위치한 스테이지

	vector<Poketmon*>* PoketmonList;	// 소유 포켓몬 리스트
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

	vector<Poketmon*>* GetPoketmonList();
	void SetPoketmonList(vector<Poketmon*>* list);

	vector<Stage*>* GetStageList();
	Stage* GetCurrStage();
	void SetCurrStage();

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