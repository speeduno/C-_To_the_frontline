#include "Recon.h"

Recon::~Recon()
{
    ButtonList.clear();
}

void Recon::Init()
{
    Button* sel_1 = new Button("�������� => (������ �� ü�� - 10%, ���н� ������ ����)", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("����ǰ ȸ�� => (������ ��� ����, ���н� ������ Hp ����)", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("���ư���", 2, 20, 24);
    ButtonList.push_back(sel_3);

    OnOff = true;
    CurrentButton = ButtonList.begin();

    Draw();
}

void Recon::Update()
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
                if ((*CurrentButton)->num == 0)    // ��������
                {

                }
                if ((*CurrentButton)->num == 1)    // ����ǰ ȸ��
                {

                }

                if ((*CurrentButton)->num == 2)    // ������
                {
                    GameManager::getInstance()->changeScene(LOBBY);
                }

                break;
            }
        }
    }
}

void Recon::Draw()
{
    system("cls");

    DrawSceneName();
    //DrawStageInfo();			//���������� ������Ʈ�� �������ְ� ����
    //DrawPlayerInfo();

    //�Ʊ���Ȳ �׸���
    DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Recon::Destroy()
{
    OnOff = false;
}
