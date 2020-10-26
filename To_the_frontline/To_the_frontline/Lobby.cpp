#include "Lobby.h"

Lobby::~Lobby()
{
    ButtonList.clear();
}

void Lobby::Init()
{
    Button* sel_1 = new Button("전투로", 0, 40, 14);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("병영", 1, 40, 16);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("정찰", 2, 40, 18);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("소집", 3, 40, 20);
    ButtonList.push_back(sel_4);
    Button* sel_5 = new Button("업그레이드", 4, 40, 22);
    ButtonList.push_back(sel_5);
    Button* sel_6 = new Button("저장", 5, 40, 24);
    ButtonList.push_back(sel_6);
    Button* sel_7 = new Button("종료", 6, 40, 26);
    ButtonList.push_back(sel_7);
   
    OnOff = true;
    CurrentButton = ButtonList.begin();

    //SetCursorVisible(false);  

    Draw();
}

void Lobby::Update()
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
                if ((*CurrentButton)->num == 0)    // 전투로
                {                   
                    GameManager::getInstance()->changeScene(BATTLE);
                }                    
                if ((*CurrentButton)->num == 1)    // 병영
                {
                    GameManager::getInstance()->changeScene(BARRACKS);
                }
                if ((*CurrentButton)->num == 2)    // 정찰
                {
                    GameManager::getInstance()->changeScene(RECON);
                }
                if ((*CurrentButton)->num == 3)    // 소집
                {
                    GameManager::getInstance()->changeScene(RECRUIT);
                }
                if ((*CurrentButton)->num == 4)    // 업그레이드
                {
                    GameManager::getInstance()->changeScene(UPGRADE);
                }
                if ((*CurrentButton)->num == 5)    // 저장
                {
                        // SavePoketmonList(GameManager::getInstance()->GetPoketmonList(), "./data/PoketmonList.txt");
                        // SavePlayerInfo(GameManager::getInstance()->GetPlayerInfo(), "./data/PlayerInfo.txt");

                        GoToXY(75, 14);
                        SetTextColor(12);
                        printf("저장 완료!");                                      
                }

                if ((*CurrentButton)->num == 6)    // 종료
                {
                    GameManager::getInstance()->Release();
                    exit(0);
                }

                break;
            }
        }
    }
}

void Lobby::Draw()
{
    system("cls");

    DrawSceneName();
    //DrawStageInfo();			//정보값들은 오브젝트를 생성해주고 설정
    DrawPlayerInfo();
    DrawArmyList();

    PrintButtonList(ButtonList, CurrentButton);
}

void Lobby::Destroy()
{
    OnOff = false;
}

