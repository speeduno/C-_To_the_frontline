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
            player->pname = name;      //플레이어 정보 입력하기
            player->namesize = name.size();
            player->title = "용병단";
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
    printf("진격하여 성을 빼앗으십시오.\n");
    GoToXY(35, 7);
    printf("병영에서 병사 관리를 할 수 있습니다.\n");
    GoToXY(35, 8);
    printf("정찰을 통해 상대의 약점을 알 수 있습니다.\n");
    GoToXY(35, 9);
    printf("소집을 통해 군사를 모을 수 있습니다.\n");
    GoToXY(35, 10);
    printf("업그레이드를 통해 더 나은 무기를 얻을 수 있습니다.\n");
    GoToXY(35, 11);
    printf("한번의 전투가 끝나면 자동 저장되며, 메뉴에서도 저장할 수 있습니다.\n");

    GoToXY(35, 13);
    printf("계속하려면 이름을 입력하시고, ENTER키를 누르십시오.\n");

    SetTextColor(15);

    SetCursorVisible(true);
    string temp;
    GoToXY(35, 15);
    printf("당신의 이름은? : ");
    cin >> temp;
    name = temp;
    SetCursorVisible(false);

    GoToXY(55, 20);
    printf("당신의 군사입니다.");

    for (int i = 0; i < (int)MyArmyList.size(); i++)
    {
        MyArmyList[i]->PrintInfo(20 + i * 30, 24);
    }

}

void Start::Destroy()
{
    OnOff = false;
}
