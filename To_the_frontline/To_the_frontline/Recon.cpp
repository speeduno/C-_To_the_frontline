#include "Recon.h"

Recon::~Recon()
{
    ButtonList.clear();
}

void Recon::Init()
{
    Button* sel_1 = new Button("적지정찰 => (성공시 적 체력 - 10%, 실패시 정찰병 죽음)", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("군수품 회수 => (성공시 골드 증가, 실패시 정찰병 죽음)", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("돌아가기", 2, 20, 24);
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
                if ((*CurrentButton)->num == 0)    // 적지정찰
                {
                    EnermySearch();
                }
                if ((*CurrentButton)->num == 1)    // 군수품 회수
                {
                    MunitionsCollection();
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

void Recon::Draw()
{
    system("cls");

    DrawSceneName();   
    DrawPlayerInfo();

    //아군상황 그리기
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
        GoToXY(40, 4);	printf("                 정찰병이 없습니다.                 ");
        return;
    }

    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!                  정찰 종료                   !");
    GoToXY(40, 5);	printf("!                                              !");
   
    if (sucess == false)
    {
        GoToXY(40, 6);	printf("!                  **실패**                    !");
        GoToXY(40, 8);	printf("!              **정찰병 사망**                 !");
        GameManager::getInstance()->GetMySpecialList()->recon--;

    }
    if (sucess == true)
    {
        GoToXY(40, 6);	printf("!                  **성공**                    !");
        GoToXY(40, 8);	printf("!        **상대방의 약점을 파악했다.**         !");
    }

    GoToXY(40, 7);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    //기능구현

    DrawArmyList();

}

void Recon::MunitionsCollection()
{
    Draw();

    if (GameManager::getInstance()->GetMySpecialList()->recon <= 0)
    {
        GoToXY(40, 4);	printf("                 정찰병이 없습니다.                 ");
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
    GoToXY(40, 4);	printf("!                  정찰 종료                   !");
    GoToXY(40, 5);	printf("!                                              !");

    if (sucess == false)
    {
        GoToXY(40, 6);	printf("!                  **실패**                    !");
        GoToXY(40, 8);	printf("!              **정찰병 사망**                 !");

        GameManager::getInstance()->GetMySpecialList()->recon--;
    }
    if (sucess == true)
    {
        GoToXY(40, 6);	printf("!                  **성공**                    !");
        GoToXY(40, 8);	printf("!         **안전하게 골드를 회수했다**         !");
    }

    GoToXY(40, 7);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

    GameManager::getInstance()->GetPlayerInfo()->gold += 2000;

    DrawArmyList();

}
