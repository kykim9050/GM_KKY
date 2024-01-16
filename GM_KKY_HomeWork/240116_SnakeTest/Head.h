#pragma once
#include "Part.h"

class Head : public Part
{

protected:
	void Update() override;

	inline int2 ReversePos() const
	{
		return CurPos * (-1);
	}

private:
	int2 CurPos = { 0, 0 };
};

