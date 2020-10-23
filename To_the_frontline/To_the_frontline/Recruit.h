#include "Scene.h"

#pragma once

class Recruit : public Scene
{
public:

public:
	Recruit(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Recruit();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

};