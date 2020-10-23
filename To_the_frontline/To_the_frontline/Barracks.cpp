#include "Barracks.h"

Barracks::~Barracks()
{
    ButtonList.clear();
}

void Barracks::Init()
{
    Button* sel_1 = new Button("휴식", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("훈련", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("정신교육", 2, 20, 22);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("나가기", 3, 20, 26);
    ButtonList.push_back(sel_4);

    OnOff = true;
    CurrentButton = ButtonList.begin();

    Draw();
}

void Barracks::Update()
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
                if ((*CurrentButton)->num == 0)    // 휴식
                {

                }
                if ((*CurrentButton)->num == 1)    // 훈련
                {

                }

                if ((*CurrentButton)->num == 2)    // 정신교육
                {

                }            
                if ((*CurrentButton)->num == 3)    // 나가기
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
    //DrawStageInfo();			//정보값들은 오브젝트를 생성해주고 설정
    //DrawPlayerInfo();

    //아군상황 그리기
    DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Barracks::Destroy()
{
    OnOff = false;
}
