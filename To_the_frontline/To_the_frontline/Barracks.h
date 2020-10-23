#include "Scene.h"

#pragma once

class Barracks : public Scene
{
public:

public:
	Barracks(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Barracks();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

};