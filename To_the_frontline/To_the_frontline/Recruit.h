#include "Scene.h"

#pragma once

class Recruit : public Scene
{
public:
	string name[6] = { "보  병", "궁  병", "기  병", "장  군", "정찰병", "저격수" };

public:
	Recruit(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Recruit();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void NormalGacha();
	void SpecialGacha();

};