#include "Scene.h"
#include "MyArmy.h"
#include "Player.h"

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
	//GameManager::getInstance()->GetPlayerInfo()->PrintPlayerInfo();
}

void Scene::DrawStageInfo()
{
	GoToXY(Stage_X, Stage_Y);
	SetTextColor(13);
	//printf("[ 현재 위치 : %s ]", GameManager::getInstance()->GetCurrStage()->name.c_str());
}

void Scene::DrawArmyList()
{
	SetTextColor(15);
	GoToXY(0, 31);
	for (int i = 0; i < 128; i++)
		printf("-");

	GoToXY(1, 33);
	SetTextColor(14);
	printf("[아군]");

	for (int i = 0; i < (int)GameManager::getInstance()->GetArmyList()->size(); i++)
	{
		(*GameManager::getInstance()->GetArmyList())[i]->PrintInfo(2+i *30, 35);
	}
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
	printf("▶");
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