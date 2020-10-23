#include "Barracks.h"

Barracks::~Barracks()
{
    ButtonList.clear();
}

void Barracks::Init()
{
    Button* sel_1 = new Button("�޽�", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("�Ʒ�", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("���ű���", 2, 20, 22);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("������", 3, 20, 26);
    ButtonList.push_back(sel_4);

    OnOff = true;
    CurrentButton = ButtonList.begin();

    Draw();
}

void Barracks::Update()
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

void Barracks::Draw()
{
    system("cls");

    DrawSceneName();
    //DrawStageInfo();			//���������� ������Ʈ�� �������ְ� ����
    //DrawPlayerInfo();

    //�Ʊ���Ȳ �׸���
    DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Barracks::Destroy()
{
    OnOff = false;
}
