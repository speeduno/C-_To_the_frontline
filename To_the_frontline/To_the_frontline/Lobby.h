#include "Scene.h"

#pragma once

class Lobby : public Scene
{
public:
	Lobby(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Lobby();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

};