#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void goodbye(const std::string& s)
{
    // 함수 본문
}

class Object
{
    // 클래스 본문
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
    [](const int&i) -> void { std::cout << "Hello,World!" << std::endl; }(1234);

    {
        std::string name = "JackJack";

        // 외부 변수를 참조로 캡처하여 출력하는 람다 함수
        // 여기서 `name`은 참조로 캡처되어 "JackJack"을 출력합니다.
        [&]() { std::cout << name << std::endl; }();          

        name = "BellBell";

        // `name` 변수를 참조로 캡처하여 출력하는 람다 함수
        // 여기서 `name`은 참조로 캡처되어 "BellBell"을 출력합니다.
        [&name]() { std::cout << name << std::endl; }();

        name = "AliceAlice";

        // 외부 변수를 참조로 캡처하고, 매개변수로 받은 `capturedName`을 출력하는 람다 함수
        // 이 람다 함수는 매개변수 `capturedName`을 받아 "AliceAlice"를 출력합니다.
        // 여기서 `capturedName`은 외부 변수 `name`의 값을 참조합니다.
        [&](std::string& capturedName) { std::cout << capturedName << std::endl; }(name);

        std::string name2 = "ALI";

        // 매개변수 `capturedName`과 외부 변수 `name`을 참조로 캡처하여 출력하는 람다 함수
        // 여기서 `capturedName`은 외부 변수 `name2`의 값을 참조하고,
        // `name`은 참조로 캡처되어 "AliceAlice"를 출력합니다.
        [&](std::string& capturedName) {
            std::cout << capturedName <<" "<<name<< std::endl;  // 매개변수 `capturedName` 출력
        }(name2);

        name = "BobBob";

        // 로컬 변수 `localName`을 참조로 받아서 출력하고 값을 변경하는 람다 함수
        // `localName`이 "BobBob"에서 "BANBAN"으로 변경됩니다.
        [](std::string& localName) -> std::string& { 
            std::cout << localName << std::endl; 
            localName = "BANBAN"; 
            return localName; 
        }(name);

        // `name` 변수를 참조로 캡처하고 값을 "SAM"으로 변경하는 람다 함수
        // 여기서 `name`은 참조로 캡처되어 "SAM"으로 변경됩니다.
        [&name]() -> std::string& { 
            std::cout << name << std::endl; 
            name = "SAM"; 
            return name; 
        }();

        // `name`을 참조로 캡처하여 현재 값을 출력하는 람다 함수
        // 여기서 `name`은 참조로 캡처되어 최종 값 "SAM"을 출력합니다.
        [&]() { std::cout << name << std::endl; }();
    }

    return 0;
}
