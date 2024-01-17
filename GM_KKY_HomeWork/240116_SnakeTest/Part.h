#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	inline void SetFront(Part* _FrontPtr)
	{
		Front = _FrontPtr;
	}
	
	inline void SetBack(Part* _BackPtr)
	{
		Back = _BackPtr;
	}

	inline Part* GetBack() const
	{
		return Back;
	}

	Part* FindTail()
	{
		if (nullptr != this->Back)
		{
			return this->Back->FindTail();
		}
		return this;
	}

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
};

