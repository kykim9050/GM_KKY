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
	//SetPrevPos(GetPos());
	int2 PrevHeadPos = GetPos();


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
		SetDirPos(Left);
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
		SetDirPos(Down);
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
		SetDirPos(Up);
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
		SetDirPos(Right);
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

	// CurBody�� ���纻
	// Head::Update�� ��������
	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		BodyVector.push_back(CurBody);
		//// ���⿡ CurBody�� Head�� ���踦 ���� �� �ֵ��� �ϸ�
		//// ��ͷ� body�� ���� ���� �� �ֵ��� ����.
		//Part* TailPtr = FindTail();

		/*TailPtr->SetBack(CurBody);
		CurBody->SetFront(TailPtr);*/
		BodyManager::ResetBody();
	}

	int BodyVectorLength = static_cast<int>(BodyVector.size());

	if (BodyVectorLength > 0) {
		int2 Temp1 = BodyVector[0]->GetPos();
		BodyVector[0]->SetPos(PrevHeadPos);

		for (int i = 0; i < BodyVectorLength; i++)
		{
			int2 Temp2 = BodyVector[i]->GetPos();
			BodyVector[i]->SetPos(Temp1);
			Temp1 = Temp2;
		}
	}

	
}