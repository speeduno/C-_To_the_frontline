#include "Scene.h"

class Upgrade : public Scene
{
public:

public:
	Upgrade(SCENE_TYPE scType, string name) : Scene(scType, name) {}
	~Upgrade();

	virtual void Init();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

};