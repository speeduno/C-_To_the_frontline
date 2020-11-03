#include "Battle.h"

Battle::~Battle()
{
    ButtonList.clear();
}

void Battle::Init()
{
    Button* sel_1 = new Button("����", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("����", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("���", 2, 20, 22);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("����", 3, 20, 24);
    ButtonList.push_back(sel_4);
    Button* sel_5 = new Button("����", 4, 20, 28);
    ButtonList.push_back(sel_5);

    CurrentButton = ButtonList.begin();

    OnOff = true;
    Draw();
}

void Battle::Update()
{
    int key;

    while (OnOff)
    {
        if (kbhit())
        {
            key = getch();

            switch (key)
            {
            case UP:
                if ((*CurrentButton)->num != 0)
                {
                    advance(CurrentButton, -1);
                    Draw();
                }
                break;

            case DOWN:
                if ((*CurrentButton)->num != ButtonList.size() - 1)
                {
                    advance(CurrentButton, 1);
                    Draw();
                }
                break;

            case ENTER:
                if ((*CurrentButton)->num == 0)    // �麴��
                {
                    DrawAttack();
                }
                if ((*CurrentButton)->num == 1)    // ����
                {

                }

                if ((*CurrentButton)->num == 2)    // ���
                {

                }
                if ((*CurrentButton)->num == 3)    // �ϻ�
                {

                }
                if ((*CurrentButton)->num == 4)    // ����
                {
                    GameManager::getInstance()->changeScene(LOBBY);
                }

                break;              
            }
        }
    }
}

void Battle::Draw()
{
    system("cls");

    DrawSceneName();
  
    //�Ʊ���Ȳ �׸���
    DrawArmyList();
    //�� ��Ȳ �׸���
    DrawEnermyList();
  
    PrintButtonList(ButtonList, CurrentButton);
}

void Battle::Destroy()
{
    OnOff = false;
}

void Battle::DrawEnermyList()
{
    SetTextColor(14);
    GoToXY(0, 14);
    for (int i = 0; i < 128; i++)
        printf("-");

    GoToXY(1, 2);
    SetTextColor(10);
    printf("[����]                                                 [�� Lv. %d]", GameManager::getInstance()->GetPlayerInfo()->catle +1);

    for (int i = 0; i < (int)GameManager::getInstance()->GetArmyList()->size(); i++)
    {
        (*GameManager::getInstance()->GetArmyList())[i]->PrintInfo(2 + i * 30, 4);
    }

    GameManager::getInstance()->GetEnermySpecialList()->PrintSpecial(92, 4);
}

void Battle::DrawAttack()
{
    system("cls");

    //�Ʊ���Ȳ �׸���
    DrawArmyList();
    //�� ��Ȳ �׸���
    DrawEnermyList();


    GoToXY(20, 16); printf("�Ʊ� �ú��� ���� -������-");
    _sleep(1000);
    GoToXY(20, 18); printf("�Ʊ� �⺴�� ���� -������-");
    _sleep(1000);
    GoToXY(20, 20); printf("�Ʊ� ������ ���� -������-");
    _sleep(1000);
    //���糢�� ���ǵ� ũ��� ���� ���� ����


    GoToXY(20, 22); printf("���� �ú��� ���� -������-");
    _sleep(1000);
    GoToXY(20, 24); printf("���� �ú��� ���� -������-");
    _sleep(1000);
    GoToXY(20, 26); printf("���� �ú��� ���� -������-");
    _sleep(2000);

    Init();

    //������ Enter or �ƹ�Ű �޴� ��ư ���
}
