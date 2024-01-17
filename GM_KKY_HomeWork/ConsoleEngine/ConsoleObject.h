#pragma once
#include "ConsoleMath.h"
#include "ConsoleUpdater.h"

// ���漱�� 
class ConsoleObject : public ConsoleUpdater
{
	friend class EngineCore;

public:
	ConsoleObject();
	ConsoleObject(const int2& _StartPos, char _RenderChar);
	// �Ҹ��� virtual 
	virtual ~ConsoleObject();

	int2 GetPos() const;
	char GetRenderChar() const;

	inline void SetRenderChar(char _Ch)
	{
		RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos)
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir)
	{
		Pos += _Dir;
	}

	inline int2 GetPrevPos() const
	{
		return PrevPos;
	}

	inline void SetPrevPos(const int2 _Pos)
	{
		PrevPos = _Pos;
	}

	inline int2 GetDirPos() const
	{
		return DirPos;
	}

	inline void SetDirPos(const int2 _Pos)
	{
		DirPos = _Pos;
	}

	inline int2 GetPrevDirPos() const
	{
		return PrevDirPos;
	}

	inline void SetPrevDirPos(const int2 _Pos)
	{
		PrevDirPos = _Pos;
	}

	template<typename EnumType>
	ConsoleObject* Collision(EnumType _UpdateOrder)
	{
		return Collision(static_cast<int>(_UpdateOrder));
	}

	// ���� �浹�� ������Ʈ
	ConsoleObject* Collision(int _UpdateOrder);

	inline int2 ReversePos()
	{
		return DirPos * (-1);
	}
protected:



private:
	// ���� ������Ʈ�� �̵��� ����
	// Left, Right, Up, Down
	int2 DirPos = { 0, 0 };
	int2 PrevDirPos = { 0, 0 };
	// �̵� �� �� ��ǥ�� ����� ����
	int2 PrevPos = { 0, 0 };
	int2 Pos = { 0, 0 };
	char RenderChar = '@';
};


