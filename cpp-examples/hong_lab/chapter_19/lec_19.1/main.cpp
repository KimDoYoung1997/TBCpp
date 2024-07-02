#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void goodbye(const std::string& s)
{
    // 함수 본문
    std::cout<<"good bye "<<s<<std::endl;
}

class Object
{
    // 클래스 본문
public:
    void hello(const std::string& s,const std::string& s2)
    {
        std::cout<<"Hello "<< s <<s2<<std::endl;
    }
};

int main()
{
    // 람다 함수 정의 및 사용
    // 이 코드는 람다 함수를 정의하고, func는 이 람다 함수를 저장합니다.
    // 이 경우에는 func가 람다 함수 그 자체를 저장하므로 컴파일 에러가 발생하지 않습니다.
    auto func = [](const int&i) -> void { std::cout << "Hello,World!" << std::endl; };
    // 함수 포인터처럼 사용할 수 있다.
    func(123);

    // 이 코드는 람다 함수를 정의한 후 즉시 호출하려고 합니다.
    // 그러나 auto func로 선언했기 때문에, func는 람다 함수의 반환 값을 저장하려고 합니다.
    // 람다 함수는 void를 반환하도록 정의되었기 때문에, auto func는 void 타입을 저장하려고 하여 컴파일 에러가 발생합니다.
    /*  컴파일 에러 발생!  
        auto func = [](const int&i) -> void { std::cout << "Hello,World!" << std::endl; }(1234);
    */

    // 만약 바로 위 코드에서 람다 함수를 즉시 호출하고 그 결과를 저장하지 않으려면,
    // func를 선언(정의)하지 않고 단순히 람다 함수를 호출하면 됩니다:
    // 진정한 람다함수의 가치는 익명일때 발휘된다.
    // 아래의 경우 함수를 정의하고 (1234) 를 argument로 호출까지 동시에 실행한다.
    [](const int&i) -> void { std::cout << "Hello,World2!" << std::endl; }(1234);

    {
        std::string name = "JackJack";


        // 외부 변수를 복사로 캡처하여 출력하는 람다 함수
        // 여기서 `name`은 복사로 캡처되어 "JackJack"을 출력합니다.
        // 이후 name을 "TOM" 으로 바꿈
        [=]() 
        {
            std::cout <<"copy "<< name << std::endl; 
            // name="TOM"; 컴파일 에러 발생,  [=] 캡처 방식으로 캡처된 변수는 기본적으로 const로 간주되어 변경할 수 없습니다.
        }();


        // 외부 변수를 참조로 캡처하여 출력하는 람다 함수
        // 여기서 `name`은 참조로 캡처되어 "JackJack"을 출력합니다.
        [&]() 
        {
            std::cout <<"reference "<< name << std::endl; 
            name="TOM";
        }();

        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);


        //STL에도 lambda를 아래처럼 쓸 수 있다. 
        auto func2 =[](int val)
        {
            std::cout<< val <<std::endl;
        };
        for_each(v.begin(),v.end(),func2);  // <algorithm> 안에 for_each 가 있음

        //STL에도 lambda를 아래처럼 쓸 수 있다. 이 방법이 바로 위 방법보다 더 간결하다고 생각해서, 선호된다.
        for_each(v.begin(),v.end(),[](int val){std::cout<< val <<std::endl;});  // <algorithm> 안에 for_each 가 있음

        std::cout<<[]()->int{return 1;}()<<std::endl;   // 기괴해 보이나 1을 return해주는 int 타입의 함수를 정의하고, 호출하는 구문일 뿐이다.

        std::function<void(int)> func3 = func2;
        func3(123);
        // std::function<void()>func4 = std::bind(func)

        std::function<void()>func4 = std::bind(func3,456);  //func3 는 int 타입을 arg 로 받기로 했는데, 이 arg를 아예 456으로 bind해버림
        func4();

        std::function<void(const std::string)> func5 = goodbye;
        func5("sad");
        std::function<void()> func6 = std::bind(goodbye,"happy");
        func6();
    }


    {
        Object instance;
        auto f1 = std::bind(&Object::hello,&instance,std::placeholders::_1,std::placeholders::_2); // bind(사용할 메서드 주소,적용될 객체의 주소,함수 입력인자)
        f1(std::string("World"),std::string(" Im Good!"));
        auto f2 = std::bind(&Object::hello,&instance,std::placeholders::_2,std::placeholders::_1); // bind(사용할 메서드 주소,적용될 객체의 주소,함수 입력인자)
        f2(std::string("World"),std::string(" Im Good! "));
        
        f1("my name is ","doyoung ");
        f2("my name is ","doyoung ");

        auto f3 = std::bind(&goodbye,std::placeholders::_1); // bind(사용할 함수,함수 입력인자) ,여기선 goodbye가 주소값이 아니기에 &를 사용한다.
        f3("goodbye");


        std::function<void(const std::string)> func5 = goodbye;
        auto f4 = std::bind(func5,std::placeholders::_1); // bind(사용할 함수,함수 입력인자) , 여기선 func5가 이미 주소값이라 &를 사용하지 않는다.
        f4("goodbye func5");
    }

    return 0;
}
