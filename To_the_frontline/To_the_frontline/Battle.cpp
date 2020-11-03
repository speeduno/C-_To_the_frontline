#include "Battle.h"

Battle::~Battle()
{
    ButtonList.clear();
}

void Battle::Init()
{
    Button* sel_1 = new Button("전투", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("견제", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("기습", 2, 20, 22);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("저격", 3, 20, 24);
    ButtonList.push_back(sel_4);
    Button* sel_5 = new Button("도망", 4, 20, 28);
    ButtonList.push_back(sel_5);

    CurrentButton = ButtonList.begin();

    OnOff = true;
    Draw();
}

void Battle::Update()
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
                if ((*CurrentButton)->num == 0)    // 백병전
                {
                    DrawAttack();
                }
                if ((*CurrentButton)->num == 1)    // 견제
                {

                }

                if ((*CurrentButton)->num == 2)    // 기습
                {

                }
                if ((*CurrentButton)->num == 3)    // 암살
                {

                }
                if ((*CurrentButton)->num == 4)    // 도망
                {
                    GameManager::getInstance()->changeScene(LOBBY);
                }

                break;              
            }
        }
    }
}

void Battle::Draw()
{
    system("cls");

    DrawSceneName();
  
    //아군상황 그리기
    DrawArmyList();
    //적 상황 그리기
    DrawEnermyList();
  
    PrintButtonList(ButtonList, CurrentButton);
}

void Battle::Destroy()
{
    OnOff = false;
}

void Battle::DrawEnermyList()
{
    SetTextColor(14);
    GoToXY(0, 14);
    for (int i = 0; i < 128; i++)
        printf("-");

    GoToXY(1, 2);
    SetTextColor(10);
    printf("[적군]                                                 [성 Lv. %d]", GameManager::getInstance()->GetPlayerInfo()->catle +1);

    for (int i = 0; i < (int)GameManager::getInstance()->GetArmyList()->size(); i++)
    {
        (*GameManager::getInstance()->GetArmyList())[i]->PrintInfo(2 + i * 30, 4);
    }

    GameManager::getInstance()->GetEnermySpecialList()->PrintSpecial(92, 4);
}

void Battle::DrawAttack()
{
    system("cls");

    //아군상황 그리기
    DrawArmyList();
    //적 상황 그리기
    DrawEnermyList();


    GoToXY(20, 16); printf("아군 궁병의 공격 -데미지-");
    _sleep(1000);
    GoToXY(20, 18); printf("아군 기병의 공격 -데미지-");
    _sleep(1000);
    GoToXY(20, 20); printf("아군 보병의 공격 -데미지-");
    _sleep(1000);
    //병사끼리 스피드 크기로 공격 순서 정함


    GoToXY(20, 22); printf("적군 궁병의 공격 -데미지-");
    _sleep(1000);
    GoToXY(20, 24); printf("적군 궁병의 공격 -데미지-");
    _sleep(1000);
    GoToXY(20, 26); printf("적군 궁병의 공격 -데미지-");
    _sleep(2000);

    Init();

    //끝나고 Enter or 아무키 메뉴 버튼 출력
}
