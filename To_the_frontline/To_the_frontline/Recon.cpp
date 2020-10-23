#include "Recon.h"

Recon::~Recon()
{
    ButtonList.clear();
}

void Recon::Init()
{
    Button* sel_1 = new Button("적지정찰 => (성공시 적 체력 - 10%, 실패시 정찰병 죽음)", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("군수품 회수 => (성공시 골드 증가, 실패시 정찰병 Hp 감소)", 1, 20, 20);
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

                }
                if ((*CurrentButton)->num == 1)    // 군수품 회수
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

void Recon::Draw()
{
    system("cls");

    DrawSceneName();
    //DrawStageInfo();			//정보값들은 오브젝트를 생성해주고 설정
    //DrawPlayerInfo();

    //아군상황 그리기
    DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Recon::Destroy()
{
    OnOff = false;
}
