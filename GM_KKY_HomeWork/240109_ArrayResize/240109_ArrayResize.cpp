#include <iostream>
#include <ConsoleEngine/EngineDebug.h>


class IntArray
{
    // private: 디폴트 접근제한 지정자
public:
    // 디폴트 생성자
    IntArray(int _Size)
    {
        ReSize(_Size);
    }

    // 디폴트 복사 생성자
    IntArray(const IntArray& _Other)
    {
        Copy(_Other);

        //NumValue = _Other.NumValue;
        //ArrPtr = _Other.ArrPtr;
    }
    // 디폴트 소멸자
    ~IntArray()
    {
        Release();
    }
    // 디폴트 대입연산자
    void operator=(const IntArray& _Other)
    {
        Copy(_Other);
    }

    int& operator[](int _Count)
    {
        return ArrPtr[_Count];
    }

    int& Test(int _Count)
    {
        return ArrPtr[_Count];
    }

    int Num()
    {
        return NumValue;
    }

    void Copy(const IntArray& _Other)
    {
        NumValue = _Other.NumValue;

        // 깊은 복사를 해줘야 합니다.
        ReSize(NumValue);
        for (int i = 0; i < NumValue; i++)
        {
            ArrPtr[i] = _Other.ArrPtr[i];
        }
    }

    void ReSize(int _Size)
    {
        if (0 >= _Size)
        {
            MsgBoxAssert("배열의 크기가 0일수 없습니다");
        }

        int OriginNum = NumValue <= _Size ? NumValue : _Size;

        NumValue = _Size;
        
        int* Ptr = ArrPtr;
        ArrPtr = new int[_Size];

        for (int i = 0; i < OriginNum; i++)
        {
            ArrPtr[i] = Ptr[i];
        }

        if (nullptr != Ptr)
        {
            delete[] Ptr;
            Ptr = nullptr;
        }
    }

    void Release()
    {
        if (nullptr != ArrPtr)
        {
            delete[] ArrPtr;
            ArrPtr = nullptr;
        }
    }

private:
    int NumValue = 0;
    int* ArrPtr = nullptr;
};





int main()
{
    LeckCheck;

    IntArray NewArray = IntArray(5);
    // [?][?][?][?][?]

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }

    // 리사이즈 값은 얼마든지 변경될 수 있다.
    NewArray.ReSize(10);
    // ?는 무슨값이 들어가 있어도 괜찮다.
    // [0][1][2][3][4][?][?][?][?][?]

    for (size_t i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }

}
