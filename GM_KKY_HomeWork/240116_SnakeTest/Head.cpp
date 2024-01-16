#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"


// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

void Head::Update()
{
	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int Select = _getch();

	// InputCount = _kbhit();

	// X Y
	// 1 0
	SetPrevPos(GetPos());

	switch (Select)
	{
	case 'A':
	case 'a':
	{
		if (Left == ReversePos())
		{
			break;
		}
		AddPos(Left);
		DirPos = Left;
		break;
	}
	case 'S':
	case 's':
	{
		if (Down == ReversePos())
		{
			break;
		}
		AddPos(Down);
		DirPos = Down;
		break;
	}
	case 'W':
	case 'w':
	{
		if (Up == ReversePos())
		{
			break;
		}
		AddPos(Up);
		DirPos = Up;
		break;
	}
	case 'D':
	case 'd':
	{
		if (Right == ReversePos())
		{
			break;
		}
		AddPos(Right);
		DirPos = Right;
		break;
	}
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}
	


	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}

	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		Back = CurBody;
		BodyManager::ResetBody();
	}
	
}