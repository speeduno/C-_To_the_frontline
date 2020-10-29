#pragma once

#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <time.h>
#include <random>

using namespace std;

#pragma warning (disable:4996)

// �ִ� ���� ��
#define MAX_STRING_SIZE 64

// Ű���� ������� ó���ϱ� ���� ���� ��ȣ
#define LEFT	75
#define RIGHT	77
#define UP		72
#define DOWN	80
#define ENTER	13

// ���� ���� �̸��� ����� ��ġ
#define SCName_X	0
#define SCName_Y	0

// �÷��̾� ������ ����� ��ġ
#define Info_X 4
#define Info_Y 4

// �������� ������ ����� ��ġ
#define Stage_X 10
#define Stage_Y 0


// �ܼ� ȭ�� ���� �Լ�
extern void GoToXY(SHORT x, SHORT y);			// ���� �ؽ�Ʈ�� ��µ� �ܼ� ��ǥ(x,y)�� �����ϴ� �Լ�
extern void SetTextColor(int num);					// ���� �ؽ�Ʈ�� ����� �ٲ��ִ� �Լ� (0 ~ 15��)
extern void SetCursorVisible(bool bVisible);			// �Է� Ŀ���� ���̰�/�Ⱥ��̰� �ϴ� �Լ�

// ���� �����
class Army;
class Player;
class Equip;
class Button;

// ��ŸƮ ���� ����Ʈ, �� ������ �ؽ�Ʈ ���Ϸκ��� �ҷ���
extern void LoadArmyList(vector<Army*>* ArmyList, string FileName);

//���� ����Ʈ�� �ؽ�Ʈ ���Ϸ� ����
//extern void SavePoketmonList(vector<Poketmon*>* PoketmonList, string FileName);

// �÷��̾� ������ �ؽ�Ʈ ���Ϸκ��� �ҷ���
extern void LoadPlayerInfo(Player* player, string FileName);

// �÷��̾� ������ �ؽ�Ʈ ���Ϸ� ����
//extern void SavePlayerInfo(Player* player, string FileName);
//
// �������� ������ �ؽ�Ʈ ���Ϸκ��� �ҷ���
extern void LoadEquipList(vector<Equip*>* EquipList, string FileName);
//
// ��� ������ �ؽ�Ʈ ���Ϸ� ����
//extern void SaveEquipInfo(ector<Equip*>* EquipList, string FileName);