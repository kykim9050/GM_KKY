#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"


// 
// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.

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
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}

	// CurBody의 복사본
	// Head::Update의 지역변수
	Body* CurBody = BodyManager::GetCurBody();

	if (CurBody->GetPos() == GetPos())
	{
		BodyVector.push_back(CurBody);
		//// 여기에 CurBody와 Head의 관계를 이을 수 있도록 하며
		//// 재귀로 body의 끝에 붙일 수 있도록 하자.
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