#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	void SetFront(Part* _FrontPtr)
	{
		Front = _FrontPtr;
	}

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
};

