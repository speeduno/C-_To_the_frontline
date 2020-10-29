#include "Upgrade.h"

Upgrade::~Upgrade()
{
    ButtonList.clear();
}

void Upgrade::Init()
{
    Button* sel_1 = new Button("�� ���� ��", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("�� ���� ����", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("Ư�� �Ʒ� (������, ���ݼ� ����)", 2, 20, 22);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("������", 3, 20, 24);
    ButtonList.push_back(sel_4);

    OnOff = true;
    CurrentButton = ButtonList.begin();

    Draw();
}

void Upgrade::Update()
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
                if ((*CurrentButton)->num == 0)    // �޽�
                {

                }
                if ((*CurrentButton)->num == 1)    // �Ʒ�
                {

                }

                if ((*CurrentButton)->num == 2)    // ���ű���
                {

                }
                if ((*CurrentButton)->num == 3)    // ������
                {
                    GameManager::getInstance()->changeScene(LOBBY);
                }

                break;
            }
        }
    }
}

void Upgrade::Draw()
{
    system("cls");

    DrawSceneName();
    //DrawStageInfo();			//���������� ������Ʈ�� �������ְ� ����
    //DrawPlayerInfo();

    //�Ʊ���Ȳ �׸���
    DrawEquipList();
    //DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Upgrade::Destroy()
{
    OnOff = false;
}
