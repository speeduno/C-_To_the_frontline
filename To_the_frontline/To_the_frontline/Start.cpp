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
    printf("�����Ͽ� ���� �������ʽÿ�.\n");
    GoToXY(35, 7);
    printf("�������� ���� ������ �� �� �ֽ��ϴ�.\n");
    GoToXY(35, 8);
    printf("������ ���� ����� ������ �� �� �ֽ��ϴ�.\n");
    GoToXY(35, 9);
    printf("������ ���� ���縦 ���� �� �ֽ��ϴ�.\n");
    GoToXY(35, 10);
    printf("���׷��̵带 ���� �� ���� ���⸦ ���� �� �ֽ��ϴ�.\n");
    GoToXY(35, 11);
    printf("�ѹ��� ������ ������ �ڵ� ����Ǹ�, �޴������� ������ �� �ֽ��ϴ�.\n");

    GoToXY(35, 13);
    printf("����Ϸ��� ENTERŰ�� �����ʽÿ�.\n");

    //PrintButtonList(ButtonList, CurrentButton);
}

void Start::Destroy()
{
    OnOff = false;
}
