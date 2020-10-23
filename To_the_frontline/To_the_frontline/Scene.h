#pragma once
#include "GameManager.h"

class Button
{
public:
	string		text;			// ��ư�� ������ �ؽ�Ʈ
	int			num;			// ��ư ����Ʈ������ ��ư �ε���
	int			pos_x;			// ��ư�� �׷��� x ��ǥ
	int			pos_y;			// ��ư�� �׷��� y ��ǥ

public:
	Button() {};
	Button(string t, int n, int x, int y);
	~Button();
};


class Scene
{
public:
	SCENE_TYPE		SceneType;						// SCENE_TYPE(���� = �� ����Ʈ�� �ε���)�� ���� ���� �̵� ó��
	string			SceneName;
	bool			OnOff = false;					// �� ���� ���� ���� ������ ����

	list<Button*>				ButtonList;			// �� ���� ������ �ִ� ��ư(������ ������) ����Ʈ
	list<Button*>::iterator		CurrentButton;		// ���� ���õ� ��ư

public:
	Scene();
	Scene(SCENE_TYPE scType, string name);
	~Scene();

	virtual void Init() = 0 { }			// ���� ó�� ������ �� ȣ��
	virtual void Update() = 0 { }		// ������ Ű���� �Է� ���� ������
	virtual void Draw() = 0 { }			// ������ �������� ���� ���� ��ȭ�� �����Ͽ� ���� ��ü �ؽ�Ʈ���� �ٽ� �׸�
	virtual void Destroy() = 0 { }		// ���� ����� �� ȣ�� (�ٸ� ������ �̵�)


	void DrawSceneName();						// ���� ���� �̸��� ����ϴ� �Լ�
	void DrawPlayerInfo();						// �÷��̾� ������ ����ϴ� �Լ�
	void DrawStageInfo();						// ���� ���������� �̸��� ����ϴ� �Լ�
	void DrawArmyList();						// �÷��̾ ������ �ִ� ���� ����Ʈ�� ����ϴ� �Լ�

														
	// �ش� ���� ButtonList�� ����ϰ� �� Ŀ���� ����ϴ� �Լ�
	void PrintButtonList(list<Button*> ButtonList, list<Button*>::iterator CurrentButton);
};

