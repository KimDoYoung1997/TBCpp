/*
정규직 직원을 관리하기 위한 초기 급여 관리 시스템
*/

#include <cstring>
#include <iostream>

// 정규직 직원의 이름, 급여에 대한 정보가 PermanentWorker 클래스의 멤버변수로 선언됨
class PermanentWorker
{
private:
    char name[100];
    int salary;
public:
    PermanentWorker(const char* name, int money):salary(money)
    {
        strcpy(this->name,name);
    }

    int Getpay() const
    {
        return salary;
    }

    void ShowSalaryInfo() const
    {
        std::cout <<"name:" <<name<<std::endl;
        std::cout <<"salary: " <<Getpay() << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out,PermanentWorker& permanentworker)
    {
        out <<"name:" <<permanentworker.name<<std::endl;
        out <<"salary: "<<permanentworker.salary<<std::endl;
        return out;
    }



};

//이렇게 기능의 처리를 실제로 담당하느 클래스를 control class 또는 handler class 라고 한다.
class EmployeeHandler
{
private:
    //PermanentWorker 포인터 타입을 50개 담을 수 있는 arr 선언
    PermanentWorker* empList[50];   
    //PermanentWorker 의 숫자를 empNum이라 함
    int empNum;



public:
    EmployeeHandler():empNum(0)
    {}
    //새로운 직원정보의 등록
    void AddEmployee(PermanentWorker* emp)
    {
        empList[empNum++]=emp;
    }
    //모든 직원의 이번달 급여정보 출력
    void ShowAllSalaryInfo() const
    {
        for(int i=0; i<empNum; i++)
        {
            //empList[i]->ShowSalaryInfo();
            std::cout<<*(empList[i]);
        }
    }
    //이번 달 급여의 총액 출력
    void ShowTotalSalary() const
    {
        int sum=0;
        for(int i=0;i<empNum;i++)
        {
            sum += empList[i]->Getpay();
        }
        std::cout <<"salary sum: "<<sum<<std::endl;
    }

    ~EmployeeHandler()
    {
        for(int i=0;i<empNum;i++)
        {
            delete[] empList[i];
            empList[i]=nullptr;
        }
    }

};

int main()
{
    //직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
    EmployeeHandler handler;

    //직원 등록 (동적할당)
    handler.AddEmployee(new PermanentWorker("KIM",1000));
    handler.AddEmployee(new PermanentWorker("LEE",1500));
    handler.AddEmployee(new PermanentWorker("JUN",2000));

    //이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();
    return 0;
}   