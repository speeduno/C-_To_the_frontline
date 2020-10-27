#include "Recruit.h"
#include "MyArmy.h"

Recruit::~Recruit()
{
    ButtonList.clear();
}

void Recruit::Init()
{
    Button* sel_1 = new Button("�Ϲ�ä�� => (����, ����, �⺴ �� �������� �ϳ��� ȹ��)  - 250G", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("Ư��ä�� => (����, ����, �⺴, ������, ���ݼ��� �ϳ��� ȹ��) - 1000G", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("���ư���", 2, 20, 24);
    ButtonList.push_back(sel_3);

    OnOff = true;
    CurrentButton = ButtonList.begin();

    Draw();
}

void Recruit::Update()
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
                if ((*CurrentButton)->num == 0)    // �Ϲ�ä��
                {
                    NormalGacha();

                    //���� ��������
                    //�������� ���簡 ���� ��...?
                }
                if ((*CurrentButton)->num == 1)    // Ư��ä��
                {
                    SpecialGacha();
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

void Recruit::Draw()
{
    system("cls");

    DrawSceneName();
    //DrawStageInfo();			//���������� ������Ʈ�� �������ְ� ����
    //DrawPlayerInfo();

    //�Ʊ���Ȳ �׸���
    DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Recruit::Destroy()
{
    OnOff = false;
}

void Recruit::NormalGacha()
{
    Draw();

    if (GameManager::getInstance()->GetPlayerInfo()->gold < 250)
    {
        GoToXY(40, 4);	printf("��尡 �����մϴ�.");
        return;
    }

    GameManager::getInstance()->GetPlayerInfo()->gold -= 250;
    int idx;
    int max;

    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<int> dis1(0, 2);
    idx = dis1(gen);

    int man = 0;
    if (idx == 0)
        man = 100;
    if(idx == 1)
        man = 50;
    if (idx == 2)
        man = 30;

    uniform_int_distribution<int> dis2(10, man);
    max = dis2(gen);
    
    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 3);	printf("!                   ���� ���                  !");
    GoToXY(40, 4);	printf("!                                              !");
    GoToXY(40, 5);	printf("!                  %s : %d��               !", name[idx].c_str(), max);
    GoToXY(40, 6);	printf("!                                              !");
    GoToXY(40, 7);	printf("!                                              !");
    GoToXY(40, 8);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    if ((*GameManager::getInstance()->GetArmyList())[idx]->hp != (*GameManager::getInstance()->GetArmyList())[idx]->max_hp)
    {
        (*GameManager::getInstance()->GetArmyList())[idx]->hp += max;

        if ((*GameManager::getInstance()->GetArmyList())[idx]->hp > (*GameManager::getInstance()->GetArmyList())[idx]->max_hp)
        {
            (*GameManager::getInstance()->GetArmyList())[idx]->hp = (*GameManager::getInstance()->GetArmyList())[idx]->max_hp;
            GoToXY(40, 8);	printf("! *���޸�ŭ ���簡 ä������ ������ �������ϴ�.*!");
        }
    }
    

    else
    {
        GoToXY(40, 7);	printf("!  *���޺��� ���� ���縦 ������ �� �����ϴ�.*  !");
    }

    DrawArmyList();
}

void Recruit::SpecialGacha()
{
    Draw();

    if (GameManager::getInstance()->GetPlayerInfo()->gold < 1000)
    {
        GoToXY(40, 4);	printf("��尡 �����մϴ�.");
       return;
    }

    GameManager::getInstance()->GetPlayerInfo()->gold -= 1000;
  
    int idx;
    int max;

    random_device random;
    mt19937 gen(random());
    uniform_int_distribution<int> dis1(0, 5);
    idx = dis1(gen);

    int man = 100;
    if (idx == 0)
        man = 100;
    if (idx == 1)
        man = 50;
    if (idx == 2)
        man = 30;
    uniform_int_distribution<int> dis2(10, man);
    max = dis2(gen);

    if (idx >= 3)
        max = 1;

    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 3);	printf("!                   ���� ���                  !");
    GoToXY(40, 4);	printf("!                                              !");
    GoToXY(40, 5);	printf("!                  %s : %d��               ", name[idx].c_str(), max);
    if(idx >=3) printf(" ");
    printf("!");
    GoToXY(40, 6);	printf("!                                              !");
    GoToXY(40, 7);	printf("!                                              !");
    GoToXY(40, 8);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                    

    if (idx < 3)
    {
        if ((*GameManager::getInstance()->GetArmyList())[idx]->hp != (*GameManager::getInstance()->GetArmyList())[idx]->max_hp)
        {
            (*GameManager::getInstance()->GetArmyList())[idx]->hp += max;

            if ((*GameManager::getInstance()->GetArmyList())[idx]->hp > (*GameManager::getInstance()->GetArmyList())[idx]->max_hp)
            {
                (*GameManager::getInstance()->GetArmyList())[idx]->hp = (*GameManager::getInstance()->GetArmyList())[idx]->max_hp;
                GoToXY(40, 8);	printf("! *���޸�ŭ ���簡 ä������ ������ �������ϴ�.*!");
            }
        }

        else
        {
            GoToXY(40, 7);	printf("!  *���޺��� ���� ���縦 ������ �� �����ϴ�.*  !");
        }
    }

    else
    {
        GoToXY(40, 7);	printf("!         *Ư��ä�뿡 �����Ͽ����ϴ�.*         !");

        if (idx == 3)
        {
            if (GameManager::getInstance()->GetSpecialList()->general >= 9)
            {
                GoToXY(40, 8);	printf("!   *��  ���� 9�� �̻� ä���� �� �����ϴ�.*   !");
            }
       
            else
            GameManager::getInstance()->GetSpecialList()->general += max;
        }
            
        if (idx == 4)
        {
            if (GameManager::getInstance()->GetSpecialList()->recon >= 9)
            {
                GoToXY(40, 8);	printf("!   *�������� 9�� �̻� ä���� �� �����ϴ�.*   !");
            }

            else
                GameManager::getInstance()->GetSpecialList()->recon += max;
        }
         
        if (idx == 5)
        {
            if (GameManager::getInstance()->GetSpecialList()->sniper >= 9)
            {
                GoToXY(40, 8);	printf("!   *���ݼ��� 9�� �̻� ä���� �� �����ϴ�.*   !");
            }

            else
                GameManager::getInstance()->GetSpecialList()->sniper += max;
        }
    }

    DrawArmyList();
}
