#include "GameManager.h"

int main()
{
	system("mode con: cols=128 lines=46");

	GameManager::getInstance()->Init();
	GameManager::getInstance()->Update();

	return 0;
}