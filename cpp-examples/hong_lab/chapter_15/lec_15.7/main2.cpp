#include <iostream>
#include <memory>
#include <string>

class Person
{
private:
    std::string m_name;
    std::shared_ptr<Person> m_partner;   
    // std::weak_ptr<Person> m_partner; // weak_

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
        // return m_partner.lock()
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

    Person::partnerUp(person1, person2);    // 순환참조 에러
    std::cout <<"code end" <<std::endl;

    // std::cout<<person1->getPartner()->
    return 0;
}
