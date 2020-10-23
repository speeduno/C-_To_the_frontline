#include "Title.h"

Title::~Title()
{
    ButtonList.clear();
}

void Title::Init()
{
    Button* sel_1 = new Button("처음부터", 0, 10, 12);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("이어서", 1, 10, 14);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("종료", 2, 10, 16);
    ButtonList.push_back(sel_3);

    CurrentButton = ButtonList.begin();

    OnOff = true;
    SetCursorVisible(false);
    //CurrentButton = ButtonList.begin();

    Draw();
}

void Title::Update()
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
                if ((*CurrentButton)->num == 0)    // 처음부터
                    GameManager::getInstance()->changeScene(START);
                if ((*CurrentButton)->num == 1)    // 이어서
                    GameManager::getInstance()->changeScene(LOBBY);
                if ((*CurrentButton)->num == 2)    // 종료
                {
                    GameManager::getInstance()->Release();
                    exit(0);
                }
                break;
            }
        }
    }
}

void Title::Draw()
{
    system("cls");

    DrawSceneName();

    GoToXY(55, 8);
    SetTextColor(12);

    printf("To The FrontLine");

    PrintButtonList(ButtonList, CurrentButton);
}

void Title::Destroy()
{
    OnOff = false;
}