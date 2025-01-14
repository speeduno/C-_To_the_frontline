#include "Scene.h"

#pragma once

class Start : public Scene
{
	string name; //자신의 이름
	bool chk;	 //입력값 대기
	vector<MyArmy*> MyArmyList;
	vector<EnermyArmy*> EnermyList;
	vector<Equip*> MyEquipList;

public:

public:
	Start(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Start();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

};