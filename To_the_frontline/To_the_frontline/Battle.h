#include "Scene.h"

#pragma once

class Battle : public Scene
{
public:

public:
	Battle(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Battle();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

public:
	void DrawEnermyList();

};