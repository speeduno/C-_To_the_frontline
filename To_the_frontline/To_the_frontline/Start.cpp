#include "Start.h"
#include "Player.h"

Start::~Start()
{
     ButtonList.clear();
}

void Start::Init()
{
    CurrentButton = ButtonList.begin();

    OnOff = true;
    SetCursorVisible(false);

    LoadArmyList(&MyArmyList, "./data/Start_Army.txt");
    LoadEquipList(&MyEquipList, "./data/Start_Equip.txt");

    Draw();
}

void Start::Update()
{
    int key;

    while (OnOff)
    {
        key = getch();

        switch (key)
        {
        case ENTER:
            vector<Army*>* Alist = new vector<Army*>;
            vector<Equip*>* Elist = new vector<Equip*>;
            
            for(int i = 0; i< MyArmyList.size(); i++)
            {
                Alist->push_back(MyArmyList[i]);
            }

            for (int i = 0; i < MyEquipList.size(); i++)
            {
                Elist->push_back(MyEquipList[i]);
            }
           
            GameManager::getInstance()->SetArmyList(Alist);
            GameManager::getInstance()->SetEquipList(Elist);

            Player* player = new Player();
            player->pname = name;      //�÷��̾� ���� �Է��ϱ�
            player->namesize = name.size();
            player->title = "�뺴��";
            player->titlesize = 6;
            player->catle = 0;
            player->power = 625;
            player->gold = 1000;

            GameManager::getInstance()->SetPlayerInfo(player);

            GameManager::getInstance()->changeScene(LOBBY);           
            break;       
        }
    }
}

void Start::Draw()
{
    system("cls");

    DrawSceneName();

    GoToXY(35, 5);
    SetTextColor(10);
    printf("�����Ͽ� ���� �������ʽÿ�.\n");
    GoToXY(35, 7);
    printf("�������� ���� ������ �� �� �ֽ��ϴ�.\n");
    GoToXY(35, 8);
    printf("������ ���� ����� ������ �� �� �ֽ��ϴ�.\n");
    GoToXY(35, 9);
    printf("������ ���� ���縦 ���� �� �ֽ��ϴ�.\n");
    GoToXY(35, 10);
    printf("���׷��̵带 ���� �� ���� ���⸦ ���� �� �ֽ��ϴ�.\n");
    GoToXY(35, 11);
    printf("�ѹ��� ������ ������ �ڵ� ����Ǹ�, �޴������� ������ �� �ֽ��ϴ�.\n");

    GoToXY(35, 13);
    printf("����Ϸ��� �̸��� �Է��Ͻð�, ENTERŰ�� �����ʽÿ�.\n");

    SetTextColor(15);

    SetCursorVisible(true);
    string temp;
    GoToXY(35, 15);
    printf("����� �̸���? : ");
    cin >> temp;
    name = temp;
    SetCursorVisible(false);

    GoToXY(55, 20);
    printf("����� �����Դϴ�.");

    for (int i = 0; i < (int)MyArmyList.size(); i++)
    {
        MyArmyList[i]->PrintInfo(20 + i * 30, 24);
    }

}

void Start::Destroy()
{
    OnOff = false;
}
