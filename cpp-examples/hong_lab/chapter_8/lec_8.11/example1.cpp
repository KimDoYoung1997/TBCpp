#include <iostream>

class Test {
public:
    void memberFunction() {
        std::cout << "멤버 함수 호출" << std::endl;

    }
};

int main() {
    Test obj1, obj2;
    
    // 멤버 함수 포인터 선언 및 초기화
    void (Test::*funcPtr)() = &Test::memberFunction;
    
    // 멤버 함수 포인터를 통해 함수 주소 출력
    std::cout << "obj1의 멤버 함수 주소: " << funcPtr << std::endl;
    std::cout << "obj2의 멤버 함수 주소: " << (void*)funcPtr << std::endl;
		
		(obj1.*funcPtr)();
    (obj2.*funcPtr)();
    return 0;
}