#include "Barracks.h"

Barracks::~Barracks()
{
    ButtonList.clear();
}

void Barracks::Init()
{
   

    Button* sel_1 = new Button("보급량 늘리기 => 최대군사수 증가", 0, 20, 18);
    ButtonList.push_back(sel_1);   
    Button* sel_2 = new Button("정신교육 => 사기치 증가", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("휴식 => 부상자 치유, 전투력 감소", 2, 20, 22);
    ButtonList.push_back(sel_3);
    Button* sel_4 = new Button("훈련 => 전투력 증가, 확률적으로 부상자 발생", 3, 20, 24);
    ButtonList.push_back(sel_4);
    Button* sel_5 = new Button("나가기", 4, 20, 28);
    ButtonList.push_back(sel_5);

    OnOff = true;
    CurrentButton = ButtonList.begin();

    Draw();


    SetTextColor(15);
    //if (mindtraining == true)
        GoToXY(80, 20); printf("완료");
    //if (rest == true)
        GoToXY(80, 22); printf("완료");
    //if (training == true)
        GoToXY(80, 24); printf("완료");

    SetTextColor(10);
}

void Barracks::Update()
{
    int key;
    bool chk = false;

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
                    //if (chk)
                    //    Drawchoice();
                }
                break;

            case DOWN:
                if ((*CurrentButton)->num != ButtonList.size() - 1)
                {                
                    advance(CurrentButton, 1);
                    Draw();
                    //if(chk)
                    //    Drawchoice();
                }
                break;

            case ENTER:
                if ((*CurrentButton)->num == 0)    // 인원수 증가 //보병
                {
                    if(!chk)
                        Drawchoice();

                    if (chk)
                    {
                        ButtonList.clear();
                        Init();
                        IncreaseSupply(0);
                    }
                        
                    chk = !chk;
                }
                if ((*CurrentButton)->num == 1)    // 정신교육 //궁병
                {
                    if (chk)
                    {
                        ButtonList.clear();
                        Init();
                        IncreaseSupply(1);
                        chk = false;
                    }

                    mindtraining = true;
                        
                }

                if ((*CurrentButton)->num == 2)    // 휴식    //기병
                {
                    if (chk)
                    {
                        ButtonList.clear();
                        Init();
                        IncreaseSupply(2);
                        chk = false;
                    }

                    rest = true;

                }            

                if ((*CurrentButton)->num == 3)    // 훈련
                {
                    training = true;
                }

                if ((*CurrentButton)->num == 4)    // 나가기
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

void Barracks::IncreaseSupply(int idx)
{
    Draw();

    if (GameManager::getInstance()->GetPlayerInfo()->gold < (*GameManager::getInstance()->GetArmyList())[idx]->supplycost)
    {
        GoToXY(40, 4);	printf("골드가 부족합니다.");
        return;
    }

    GameManager::getInstance()->GetPlayerInfo()->gold -= (*GameManager::getInstance()->GetArmyList())[idx]->supplycost;
    (*GameManager::getInstance()->GetArmyList())[idx]->supplycost *= 2;

    (*GameManager::getInstance()->GetArmyList())[idx]->max_hp += 100;
   
    SetTextColor(10);
    GoToXY(40, 2);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    GoToXY(40, 3);	printf("!                                              !");
    GoToXY(40, 4);	printf("!             %s 최대 수용원 증가            !", (*GameManager::getInstance()->GetArmyList())[idx]->name.c_str());
    GoToXY(40, 5);	printf("!                                              !");
    GoToXY(40, 6);	printf("!                                              !");
    GoToXY(40, 7);	printf("!              최대 인원수 : %d               !", (*GameManager::getInstance()->GetArmyList())[idx]->max_hp);
    GoToXY(40, 8);	printf("!                                              !");
    GoToXY(40, 9);	printf("!                                              !");
    GoToXY(40, 10);	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");


    DrawArmyList();
}

void Barracks::Drawchoice()
{
    ButtonList.clear();

    Button* sel_1 = new Button("보 병", 0, 20, 18);
    ButtonList.push_back(sel_1);
    Button* sel_2 = new Button("궁 병", 1, 20, 20);
    ButtonList.push_back(sel_2);
    Button* sel_3 = new Button("기 병", 2, 20, 22);
    ButtonList.push_back(sel_3);

    CurrentButton = ButtonList.begin();

    Draw();
}

