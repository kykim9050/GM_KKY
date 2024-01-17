#pragma once
#include "Part.h"
#include <vector>

class Head : public Part
{

protected:
	void Update() override;

private:
	std::vector<class Body*> BodyVector;
};

