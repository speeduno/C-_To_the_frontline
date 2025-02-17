#include "Scene.h"
#include "Army.h"
#include "Player.h"
#include "SpecialArmy.h"

Scene::Scene()
{
}

Scene::Scene(SCENE_TYPE scType, string name)
{
	SceneType = scType;
	SceneName = name;

	OnOff = false;
}

Scene::~Scene()
{
}

void Scene::DrawSceneName()
{
	GoToXY(SCName_X, SCName_Y);
	SetTextColor(15);
	printf("%s", GameManager::getInstance()->GetCurrScene()->SceneName.c_str());
}

void Scene::DrawPlayerInfo()
{
	GoToXY(SCName_X, SCName_Y + 2);
	SetTextColor(15);
	GameManager::getInstance()->GetPlayerInfo()->PrintPlayerInfo(2, 2);
}

void Scene::DrawEquipList()
{
	SetTextColor(15);
	GoToXY(0, 31);
	for (int i = 0; i < 128; i++)
		printf("-");

	GoToXY(1, 33);
	SetTextColor(14);
	printf("[���]");

	for (int i = 0; i < (int)GameManager::getInstance()->GetEquipList()->size(); i++)
	{
		(*GameManager::getInstance()->GetEquipList())[i]->PrintInfo(2 + i * 30, 35);
	}
}

void Scene::DrawArmyList()
{
	SetTextColor(15);
	GoToXY(0, 31);
	for (int i = 0; i < 128; i++)
		printf("-");

	GoToXY(1, 33);
	SetTextColor(14);
	printf("[�Ʊ�]");

	for (int i = 0; i < (int)GameManager::getInstance()->GetArmyList()->size(); i++)
	{
		(*GameManager::getInstance()->GetArmyList())[i]->PrintInfo(2 + i * 30, 35);
	}	

	GameManager::getInstance()->GetMySpecialList()->PrintSpecial(92, 35);
}

void Scene::PrintButtonList(list<Button*> ButtonList, list<Button*>::iterator CurrentButton)
{
	SetTextColor(15);

	for (int i = 0; i < (int)ButtonList.size(); i++)
	{
		list<Button*>::iterator iter = ButtonList.begin();
		advance(iter, i);

		GoToXY((*iter)->pos_x, (*iter)->pos_y);
			
		printf("%s", (*iter)->text.c_str());
	}

	GoToXY((*CurrentButton)->pos_x - 3, (*CurrentButton)->pos_y);
	printf("��");
}

Button::Button(string t, int n, int x, int y)
{
	text = t;
	num = n;
	pos_x = x;
	pos_y = y;
}

Button::~Button()
{
}