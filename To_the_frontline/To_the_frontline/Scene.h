#pragma once
#include "GameManager.h"

class Button
{
public:
	string		text;			// 버튼에 쓰여진 텍스트
	int			num;			// 버튼 리스트에서의 버튼 인덱스
	int			pos_x;			// 버튼이 그려질 x 좌표
	int			pos_y;			// 버튼이 그려질 y 좌표

public:
	Button() {};
	Button(string t, int n, int x, int y);
	~Button();
};


class Scene
{
public:
	SCENE_TYPE		SceneType;						// SCENE_TYPE(정수 = 씬 리스트의 인덱스)을 통해 씬의 이동 처리
	string			SceneName;
	bool			OnOff = false;					// 이 씬이 현재 가동 중인지 여부

	list<Button*>				ButtonList;			// 이 씬이 가지고 있는 버튼(유저의 선택지) 리스트
	list<Button*>::iterator		CurrentButton;		// 현재 선택된 버튼

public:
	Scene();
	Scene(SCENE_TYPE scType, string name);
	~Scene();

	virtual void Init() = 0 { }			// 씬이 처음 가동될 때 호출
	virtual void Update() = 0 { }		// 유저의 키보드 입력 등을 대기받음
	virtual void Draw() = 0 { }			// 유저의 선택으로 인한 정보 변화를 참조하여 씬의 전체 텍스트들을 다시 그림
	virtual void Destroy() = 0 { }		// 씬이 종료될 때 호출 (다른 씬으로 이동)


	void DrawSceneName();						// 현재 씬의 이름을 출력하는 함수
	void DrawPlayerInfo();						// 플레이어 정보를 출력하는 함수
	void DrawStageInfo();						// 현재 스테이지의 이름을 출력하는 함수
	void DrawArmyList();						// 플레이어가 가지고 있는 군사 리스트를 출력하는 함수

														
	// 해당 씬의 ButtonList를 출력하고 ▶ 커서를 출력하는 함수
	void PrintButtonList(list<Button*> ButtonList, list<Button*>::iterator CurrentButton);
};

