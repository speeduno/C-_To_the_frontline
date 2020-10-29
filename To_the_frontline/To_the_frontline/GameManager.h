#pragma once
#include "Info.h"
#include "player.h"
#include "Army.h"
#include "SpecialArmy.h"
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
class Army;
class SpecialArmy;
class Equip;

class GameManager
{
private:
	static GameManager* instance;

	vector<Scene*>		SceneList;		// ��ü �� ����Ʈ
	Scene* CurrScene;					// ���� Ȱ��ȭ�� ��. �� ������ ������ �ʱ�ȭ�ϸ鼭 ���� �̵� ����

	vector<Army*>* ArmyList;			// ���� ���� ����Ʈ
	SpecialArmy* MySpecial;				// ����ȸ���Ʈ
	vector<Equip*>* EquipList;			// ��񸮽�Ʈ
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

	vector<Army*>* GetArmyList();
	void SetArmyList(vector<Army*>* list);

	SpecialArmy* GetSpecialList();
	void SetSpecailList(SpecialArmy*  special);

	vector<Equip*>* GetEquipList();
	void SetEquipList(vector<Equip*>* list);

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