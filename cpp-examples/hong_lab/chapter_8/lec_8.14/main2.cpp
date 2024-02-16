#include <iostream>
using namespace std;





class Fruit
{
//FruitType의 enum 은 Fruit class 에서만 쓰일 가능성이 많으니, enum을 class안으로 집어넣어보자
public:
    enum FruitType
    {
        APPLE,BANANA,CHERRY,
    };


private:
    FruitType m_type;

public:
    Fruit(FruitType type)
    : m_type(type)
    {

    }

    FruitType getType()
    {
        return m_type;
    }

};





int main()
{
    cout <<"lec_8.14"<< endl;

    // Fruit apple(APPLE);
    Fruit apple(Fruit::FruitType::APPLE);

    // if (apple.getType()==APPLE)
    if (apple.getType()==Fruit::FruitType::APPLE)
    {
        std::cout << "Apple" << endl;
    }

    return 0;
}