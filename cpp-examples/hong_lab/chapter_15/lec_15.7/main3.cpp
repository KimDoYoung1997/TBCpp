#include <iostream>
#include <memory>
#include <string>

class Person
{
private:
    std::string m_name;
    // std::shared_ptr<Person> m_partner;   
    std::weak_ptr<Person> m_partner; // weak_pointer 사용

public:
    Person(const std::string &name):m_name(name)
    {
        std::cout <<"m_name : "<<m_name<<" created\n";
    }
    ~Person()
    {
        std::cout<<"m_name : "<<m_name<<" destroyed\n";
    }

    static bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if(!p1 || !p2) return false;

        // 의도적으로 순환 참조
        p1->m_partner = p2;
        p2->m_partner = p1;

        std::cout <<p1->m_name <<" is partnered with " << p2->m_name <<"\n";
        return true;
    }

    const std::shared_ptr<Person> getPartner() const
    {
        return m_partner.lock();    // weak_pointer 를 사용하려면, lock()을 사용해야 한다. lock함으로서 weak_pointer를 shared_pointer처럼 사용하는게 가능. weack_pointer는 직접 뭔갈 할수는 없고, lock을 검으로서 shared_pointer로  바꿔서 써야한다.
                                    // 순환 의존성 구조를 깨기 위해 이러한 트릭이 사용된다.
    }

    const std::string& getName() const
    {
        return m_name;
    }

};

int main()
{
    auto person1 = std::make_shared<Person>("doyoung");
    auto person2 = std::make_shared<Person>("jingu");

    Person::partnerUp(person1, person2);    // 순환참조 에러를 weak_pointer 사용함으로서 해결. 소멸자에 의해 포인터가 해제된다.
    std::cout<<person1->getPartner()->getName() <<std::endl;
    std::cout<<person2->getPartner()->getName() <<std::endl;

    std::cout <<"code end" <<std::endl;

    return 0;
}
