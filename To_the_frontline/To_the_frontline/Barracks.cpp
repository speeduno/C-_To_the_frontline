#include "Barracks.h"

Barracks::~Barracks()
{
    ButtonList.clear();
}

void Barracks::Init()
{
   

    Button* sel_1 = new Button("���޷� �ø��� => �ִ뱺��� ����", 0, 20, 18);
    ButtonList.push_back(sel_1);   
    Button* sel_2 = new Button("���ű��� => ���ġ ����", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("�޽� => �λ��� ġ��, ������ ����", 2, 20, 22);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("�Ʒ� => ������ ����, Ȯ�������� �λ��� �߻�", 3, 20, 24);
    ButtonList.push_back(sel_4);
    Button* sel_5 = new Button("������", 4, 20, 28);
    ButtonList.push_back(sel_5);

    OnOff = true;
    CurrentButton = ButtonList.begin();

    Draw();


    SetTextColor(15);
    //if (mindtraining == true)
        GoToXY(80, 20); printf("�Ϸ�");
    //if (rest == true)
        GoToXY(80, 22); printf("�Ϸ�");
    //if (training == true)
        GoToXY(80, 24); printf("�Ϸ�");

    SetTextColor(10);
}

void Barracks::Update()
{
    int key;
    bool chk = false;

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
                    //if (chk)
                    //    Drawchoice();
                }
                break;

            case DOWN:
                if ((*CurrentButton)->num != ButtonList.size() - 1)
                {                
                    advance(CurrentButton, 1);
                    Draw();
                    //if(chk)
                    //    Drawchoice();
                }
                break;

            case ENTER:
                if ((*CurrentButton)->num == 0)    // �ο��� ���� //����
                {
                    if(!chk)
                        Drawchoice();

                    if (chk)
                    {
                        ButtonList.clear();
                        Init();
                        IncreaseSupply(0);
                    }
                        
                    chk = !chk;
                }
                if ((*CurrentButton)->num == 1)    // ���ű��� //�ú�
                {
                    if (chk)
                    {
                        ButtonList.clear();
                        Init();
                        IncreaseSupply(1);
                        chk = false;
                    }

                    mindtraining = true;
                        
                }

                if ((*CurrentButton)->num == 2)    // �޽�    //�⺴
                {
                    if (chk)
                    {
                        ButtonList.clear();
                        Init();
                        IncreaseSupply(2);
                        chk = false;
                    }

                    rest = true;

                }            

                if ((*CurrentButton)->num == 3)    // �Ʒ�
                {
                    training = true;
                }

                if ((*CurrentButton)->num == 4)    // ������
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

void Barracks::IncreaseSupply(int idx)
{
    Draw();

    if (GameManager::getInstance()->GetPlayerInfo()->gold < (*GameManager::getInstance()->GetArmyList())[idx]->supplycost)
    {
        GoToXY(40, 4);	printf("��尡 �����մϴ�.");
        return;
    }

    GameManager::getInstance()->GetPlayerInfo()->gold -= (*GameManager::getInstance()->GetArmyList())[idx]->supplycost;
    (*GameManager::getInstance()->GetArmyList())[idx]->supplycost *= 2;

    (*GameManager::getInstance()->GetArmyList())[idx]->max_hp += 100;
   
    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!             %s �ִ� ����� ����            !", (*GameManager::getInstance()->GetArmyList())[idx]->name.c_str());
    GoToXY(40, 5);	printf("!                                              !");
    GoToXY(40, 6);	printf("!                                              !");
    GoToXY(40, 7);	printf("!              �ִ� �ο��� : %d               !", (*GameManager::getInstance()->GetArmyList())[idx]->max_hp);
    GoToXY(40, 8);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");


    DrawArmyList();
}

void Barracks::Drawchoice()
{
    ButtonList.clear();

    Button* sel_1 = new Button("�� ��", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("�� ��", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("�� ��", 2, 20, 22);
    ButtonList.push_back(sel_3);

    CurrentButton = ButtonList.begin();

    Draw();
}

