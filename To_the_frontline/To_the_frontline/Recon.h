#include "Scene.h"

#pragma once

class Recon : public Scene
{
public:

public:
	Recon(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Recon();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void EnermySearch();
	void MunitionsCollection();

};