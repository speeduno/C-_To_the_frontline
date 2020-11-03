#include "Recon.h"

Recon::~Recon()
{
    ButtonList.clear();
}

void Recon::Init()
{
    Button* sel_1 = new Button("�������� => (������ �� ü�� - 10%, ���н� ������ ����)", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("����ǰ ȸ�� => (������ ��� ����, ���н� ������ ����)", 1, 20, 20);
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
                    EnermySearch();
                }
                if ((*CurrentButton)->num == 1)    // ����ǰ ȸ��
                {
                    MunitionsCollection();
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
    DrawPlayerInfo();

    //�Ʊ���Ȳ �׸���
    DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Recon::Destroy()
{
    OnOff = false;
}

void Recon::EnermySearch()
{
    Draw();

    bool sucess = false;
    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<int> dis1(0, 1);
    sucess = dis1(gen);
 
    if (GameManager::getInstance()->GetMySpecialList()->recon <= 0)
    {
        GoToXY(40, 4);	printf("                 �������� �����ϴ�.                 ");
        return;
    }

    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!                  ���� ����                   !");
    GoToXY(40, 5);	printf("!                                              !");
   
    if (sucess == false)
    {
        GoToXY(40, 6);	printf("!                  **����**                    !");
        GoToXY(40, 8);	printf("!              **������ ���**                 !");
        GameManager::getInstance()->GetMySpecialList()->recon--;

    }
    if (sucess == true)
    {
        GoToXY(40, 6);	printf("!                  **����**                    !");
        GoToXY(40, 8);	printf("!        **������ ������ �ľ��ߴ�.**         !");
    }

    GoToXY(40, 7);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    //��ɱ���

    DrawArmyList();

}

void Recon::MunitionsCollection()
{
    Draw();

    if (GameManager::getInstance()->GetMySpecialList()->recon <= 0)
    {
        GoToXY(40, 4);	printf("                 �������� �����ϴ�.                 ");
        return;
    }

    bool sucess = false;
    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<int> dis1(0, 1);
    sucess = dis1(gen);

    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!                  ���� ����                   !");
    GoToXY(40, 5);	printf("!                                              !");

    if (sucess == false)
    {
        GoToXY(40, 6);	printf("!                  **����**                    !");
        GoToXY(40, 8);	printf("!              **������ ���**                 !");

        GameManager::getInstance()->GetMySpecialList()->recon--;
    }
    if (sucess == true)
    {
        GoToXY(40, 6);	printf("!                  **����**                    !");
        GoToXY(40, 8);	printf("!         **�����ϰ� ��带 ȸ���ߴ�**         !");
    }

    GoToXY(40, 7);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    GameManager::getInstance()->GetPlayerInfo()->gold += 2000;

    DrawArmyList();

}
