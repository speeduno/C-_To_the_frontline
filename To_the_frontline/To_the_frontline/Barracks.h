#include "Scene.h"

#pragma once

class Barracks : public Scene
{
public:
	bool mindtraining;
	bool training;
	bool rest;

public:
	Barracks(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Barracks();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Drawchoice();
	void DrawComplete();
	void IncreaseSupply(int idx);	
	void MindTraining(int idx);
	void Rest(int idx);
	void Training(int idx);
};