#include "Scene.h"

#pragma once
enum ButtonCode
{
	NEW_GAME = 0,
	LOAD_GAME,
	EXIT
};

class Title : public Scene
{
public:

public:
	Title(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Title();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

};