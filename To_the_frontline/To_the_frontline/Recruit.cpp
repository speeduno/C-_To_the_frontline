#include "Recruit.h"

Recruit::~Recruit()
{
    ButtonList.clear();
}

void Recruit::Init()
{
    Button* sel_1 = new Button("일반채용 => (보병, 포병, 기병 중 무작위로 하나를 획득)", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("특별채용 => (보병, 포병, 기병, 정찰병, 저격수중 하나를 획득)", 1, 20, 20);
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
