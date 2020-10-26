#include "Recruit.h"
#include "MyArmy.h"

Recruit::~Recruit()
{
    ButtonList.clear();
}

void Recruit::Init()
{
    Button* sel_1 = new Button("일반채용 => (보병, 포병, 기병 중 무작위로 하나를 획득)  - 250G", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("특별채용 => (보병, 포병, 기병, 정찰병, 저격수중 하나를 획득) - 1000G", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("돌아가기", 2, 20, 24);
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
                if ((*CurrentButton)->num == 0)    // 일반채용
                {
                    NormalGacha();

                    //돈이 빠져나감
                    //랜덤으로 군사가 나옴 끝...?
                }
                if ((*CurrentButton)->num == 1)    // 특별채용
                {

                }

                if ((*CurrentButton)->num == 2)    // 나가기
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
    //DrawStageInfo();			//정보값들은 오브젝트를 생성해주고 설정
    //DrawPlayerInfo();

    //아군상황 그리기
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
        GoToXY(40, 4);	printf("골드가 부족합니다.");
        return;
    }

    GameManager::getInstance()->GetPlayerInfo()->gold -= 250;
    string name;
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
    GoToXY(40, 3);	printf("!                   모집 결과                  !");
    GoToXY(40, 4);	printf("!                                              !");
    GoToXY(40, 5);	printf("!                  %s : %d명                 !", (*GameManager::getInstance()->GetArmyList())[idx]->name.c_str(), max);
    GoToXY(40, 6);	printf("!                                              !");
    GoToXY(40, 7);	printf("!                                              !");
    GoToXY(40, 8);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    if ((*GameManager::getInstance()->GetArmyList())[idx]->hp != (*GameManager::getInstance()->GetArmyList())[idx]->max_hp)
    {
        (*GameManager::getInstance()->GetArmyList())[idx]->hp += 100;

        if ((*GameManager::getInstance()->GetArmyList())[idx]->hp > (*GameManager::getInstance()->GetArmyList())[idx]->max_hp)
        {
            (*GameManager::getInstance()->GetArmyList())[idx]->hp = (*GameManager::getInstance()->GetArmyList())[idx]->max_hp;
            GoToXY(40, 8);	printf("! *보급만큼 군사가 채워지며 나머진 버려집니다.*!");
        }
    }

    else
    {
        GoToXY(40, 7);	printf("!  *보급보다 많은 군사를 모집할 수 없습니다.*  !");
    }
}

void Recruit::SpecialGacha()
{
}
