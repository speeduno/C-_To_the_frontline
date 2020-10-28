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
}

void Barracks::Update()
{
    int key;
    int menu = -1;
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
                if ((*CurrentButton)->num == 0)    // �ο��� ���� //����
                {
                    chk = !chk;
                
                    if (chk)
                    {
                        menu = 0;
                        Drawchoice();
                    }               

                    if (!chk)
                    {
                        ButtonList.clear();
                        Init();                     
                    }                                       
                }
                if ((*CurrentButton)->num == 1)    // ���ű��� //�ú�
                {                   
                    if (mindtraining == true)
                        continue;

                    chk = !chk;
                
                    if (chk)
                    {
                        menu = 1;
                        Drawchoice();
                    }
                       

                    if (!chk)
                    {
                        ButtonList.clear();
                        Init();                                   
                    }                                                                   
                }

                if ((*CurrentButton)->num == 2)    // �޽�    //�⺴
                {
                    if (rest == true)
                        continue;

                    chk = !chk;

                    if (chk)
                    {
                        menu = 2;
                        Drawchoice();
                    }
                       
                    if (!chk)
                    {
                        ButtonList.clear();
                        Init();
                    }
                }            

                if ((*CurrentButton)->num == 3)    // �Ʒ�
                {           
                    if (training == true)
                        continue;

                    chk = true;
                    menu = 3;
                  
                    Drawchoice();
                }

                if ((*CurrentButton)->num == 4)    // ������
                {
                    GameManager::getInstance()->changeScene(LOBBY);
                }
                
                if (!chk)            // ����� ���� ȭ��
                {
                    switch (menu)
                    {
                    case 0:                       
                        IncreaseSupply((*CurrentButton)->num);
                        break;

                    case 1:
                        MindTraining((*CurrentButton)->num);
                        mindtraining = true;
                        break;

                    case 2:
                        Rest((*CurrentButton)->num);
                        rest = true;
                        break;

                    case 3:
                        Training((*CurrentButton)->num);
                        training = true;
                        break;
                    }
                }

                DrawComplete();

                break;
            }
        }
    }
}

void Barracks::Draw()
{
    system("cls");

    DrawSceneName();  
    DrawArmyList(); //�Ʊ���Ȳ �׸���

    PrintButtonList(ButtonList, CurrentButton);

    DrawComplete();
}

void Barracks::Destroy()
{
    OnOff = false;
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

void Barracks::DrawComplete()
{
    SetTextColor(15);
    if (mindtraining == true)
    {
        GoToXY(80, 20); printf("�Ϸ�");
    }

    if (rest == true)
    {
        GoToXY(80, 22); printf("�Ϸ�");
    }

    if (training == true)
    {
        GoToXY(80, 24); printf("�Ϸ�");
    }
    SetTextColor(10);
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
    (*GameManager::getInstance()->GetArmyList())[idx]->level += 1;

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

void Barracks::MindTraining(int idx)
{ 
    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!                ���� ���� ����                !");
    GoToXY(40, 5);	printf("!                                              !");
    GoToXY(40, 6);	printf("!                                              !");
    GoToXY(40, 7);	printf("!                 ���ġ ����                  !");
    GoToXY(40, 8);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    (*GameManager::getInstance()->GetArmyList())[idx]->morale += 30;

    DrawArmyList();
}

void Barracks::Rest(int idx)
{  
    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!                  �޽�  ����                  !");
    GoToXY(40, 5);	printf("!                                              !");
    GoToXY(40, 6);	printf("!                                              !");
    GoToXY(40, 7);	printf("!                 �λ��� ġ��                  !");
    GoToXY(40, 8);	printf("!                 ������ ����                  !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    (*GameManager::getInstance()->GetArmyList())[idx]->hp += 20;
    if ((*GameManager::getInstance()->GetArmyList())[idx]->max_hp < (*GameManager::getInstance()->GetArmyList())[idx]->hp)
        (*GameManager::getInstance()->GetArmyList())[idx]->hp = (*GameManager::getInstance()->GetArmyList())[idx]->max_hp;

    (*GameManager::getInstance()->GetArmyList())[idx]->damage -= 0.2f;

    DrawArmyList();
}

void Barracks::Training(int idx)
{
    bool wound= false;
    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<int> dis1(0, 1);
    wound = dis1(gen);

    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!                  �Ʒ� ����                   !");
    GoToXY(40, 5);	printf("!                                              !");
    GoToXY(40, 6);	printf("!                 ������ ����                  !");
    GoToXY(40, 7);	printf("!                                              !");
    if (wound == false)
    {
        GoToXY(40, 8);	printf("!              **�λ��� �̹߻�**               !");

    }
    if (wound == true)
    {
        GoToXY(40, 8);	printf("!               **�λ��� �߻�**                !");
        (*GameManager::getInstance()->GetArmyList())[idx]->hp -= 10;
    } 
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    (*GameManager::getInstance()->GetArmyList())[idx]->damage = (*GameManager::getInstance()->GetArmyList())[idx]->maxdamage;

    DrawArmyList();
}

