#include "Scene.h"

#pragma once

class Recruit : public Scene
{
public:
	string name[6] = { "��  ��", "��  ��", "��  ��", "��  ��", "������", "���ݼ�" };

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