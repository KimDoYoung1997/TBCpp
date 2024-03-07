/*
제휴관계(Has-a) : 어느쪽이 주가 되고, 어느쪽이 부가되는 확실한 관계가 없는 애매한 경우
    관계의 형태 : 용도외에 무관
    다른 클래스에 속할 수 있음
    멤버의 존재를 클래스가 관리하지 않음
    단방향 or 양방향 모두 가능

    제휴관계에선 두 클래스가 서로를 멤버로 갖고 있어야 한다.
*/

// 의사와 환자

#include <iostream>
#include <vector>
#include <string>

//Forward declation for line 27 "std::vector<Doctor*> m_doctors;"
//Doctor도 Patient에 대해 알아야하고, Patiend도 Doctor에 대해 알아야하는 거의 동등한 관계.

class Doctor;

class Patient
{
private:
    std::string m_name;
    std::vector<Doctor*> m_doctors;    // 환자 입장에서 어떤 의사들을 만나는지 Vector를 통해 기록(저장)해보자.

public:
    Patient(const std::string name_in):m_name(name_in)
    {}


    void addDoctor(Doctor* new_doctor)
    {
        m_doctors.push_back(new_doctor);
    }

    void meetDoctor();
    // void meetDoctor()
    // {
    //     for(auto &doctor: m_doctors)
    //     {
    //         std::cout <<doctor->m_name << std::endl;
    //     }
    // }

    friend class Doctor;

};

class Doctor
{
private:
    std::string m_name;
    std::vector<Patient*> m_patients;    //의사 입장에서 어떤 환자들을 만나는지 Vector를 통해 기록(저장)해보자.

public:
    Doctor(const std::string name_in):m_name(name_in)
    {}

    void addPatients(Patient* new_patient)  // vector에 pushback 할때는 copy가 되므로, 주소값을 push_back한다. 이때문에 입력 인자로 포인터를 받는다.
    {
        m_patients.push_back(new_patient);

    }

    void meetPatient()
    {
        for(auto& patient:m_patients)
        {
            std::cout <<patient->m_name<<std::endl;
        }
    }

    friend class Patient;
};


void Patient::meetDoctor()
{
    for(auto &doctor: m_doctors)
    {
        std::cout <<doctor->m_name << std::endl;
    }
}

int main()
{
    Patient* p1 = new Patient("Jack Jack");
    Patient* p2 = new Patient("Dash");
    Patient* p3 = new Patient("Violet");
    Doctor * d1 = new Doctor("Doctor K");
    Doctor * d2 = new Doctor("Doctor L");


    d1->addPatients(p1);
    p1->addDoctor(d1);

    p2->addDoctor(d2);
    d2->addPatients(p2);
    
    
    p2->addDoctor(d1);
    d1->addPatients(p2);
    
    p1->meetDoctor();

    delete p1;
    p1 =nullptr;
    delete p2;
    p2 =nullptr;
    delete p3;
    p3 =nullptr;
    delete d1;
    d1 =nullptr;
    delete d2;
    d2 =nullptr;

    return 0;
}