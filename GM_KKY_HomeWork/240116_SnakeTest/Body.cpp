#include "Body.h"
#include "Head.h"

#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"



void Body::Update()
{

	if (nullptr != Front)
	{
		SetPos(Front->GetPrevPos());
		SetPrevPos(GetPos());
	}


}

