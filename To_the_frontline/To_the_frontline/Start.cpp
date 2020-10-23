#include "Start.h"

Start::~Start()
{
     ButtonList.clear();
}

void Start::Init()
{
    CurrentButton = ButtonList.begin();

    OnOff = true;
    SetCursorVisible(false);

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
    printf("계속하려면 ENTER키를 누르십시오.\n");

    //PrintButtonList(ButtonList, CurrentButton);
}

void Start::Destroy()
{
    OnOff = false;
}
