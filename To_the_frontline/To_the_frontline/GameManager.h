#pragma once
#include "Info.h"
#include "player.h"
#include "MyArmy.h"

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

class GameManager
{
private:
	static GameManager* instance;

	vector<Scene*>		SceneList;		// ��ü �� ����Ʈ
	Scene* CurrScene;					// ���� Ȱ��ȭ�� ��. �� ������ ������ �ʱ�ȭ�ϸ鼭 ���� �̵� ����

	//vector<Stage*>* StageList;		// ��ü �������� ����Ʈ
	//Stage* CurrStage;					// ���� ��ġ�� ��������

	vector<MyArmy*>* ArmyList;			// ���� ���� ����Ʈ
	Player* MyPlayer;					// �÷��̾� ����
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

	//vector<Stage*>* GetStageList();
	//Stage* GetCurrStage();
	//void SetCurrStage();

	Player* GetPlayerInfo();
	void SetPlayerInfo(Player* player);
	void AddPlayerGold(int g);

	Scene* GetCurrScene();
	void SetCurrScene(Scene* scene);

	void changeScene(SCENE_TYPE scType);		// ���� ��ġ�� ���� Ư�� ������ �ٲٴ� �Լ� 
	//void ReturnScene(SCENE_TYPE scType);		// ������ ������ �ٲٴ� �Լ�

	void Init();
	void Update();
	void Draw();
	void Destroy();

	void Release();
};