#include "Scene.h"

#pragma once

class Start : public Scene
{
	string name; //�ڽ��� �̸�
	vector<MyArmy*> MyArmyList;

public:

public:
	Start(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Start();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

};