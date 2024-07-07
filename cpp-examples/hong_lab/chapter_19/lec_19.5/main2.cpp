#include <iostream>
#include <future>   //async future promise
#include <thread>

int main()
{
/*     
    // multi-threading
    {
        int result;
        std:: thread t1([&]
        {
            result=1+2;
        }
        );
        t1.join();  // thread가 일을 끝날때까지 기다림
        std::cout<<result<<std::endl;
    }

    // task-based parallelism
    {
        // std::future<int> fut = ...
        // 마치 return값을 fut가 바로 받는 것 처럼 보임
        // 일반적으로 thread보다 async를 쓰는 방식을 더 선호함
        // thread 방식은 thread 를 관리(생성,소멸)에 좀 더 focus하는 반면 , async 방식은 "작업" 기반에 좀더 focus하는 측면이 있다.
        // 미래(future)에 async 작업이 끝나면 그 값을 fut에 받아 오겠다 라는 말. fut 객체는 async task와 정확히 결합됨
        // std::future<int> fut = std::async([]()->int 도 가능
        std::future<int> fut = std::async([]
        {
            // return = 1+2; 차이점
            return 1+2;
        }
        );
        std::cout<<fut.get()<<std::endl;    // fut.get()는 async fut 객체의 작업(return 계산)이 끝날때까지 기다린 후, 결과값을 받아온다.
    }

    // future and promise with thread
    {
        std::promise<int> prom;  // 1. promise 객체를 생성
        auto fut = prom.get_future();  // 2. promise 객체로부터 future 객체를 획득, std::future<int> fut = ...

         // 3. 새로운 스레드를 생성하고 promise 객체를 이동
        auto t1 = std::thread([](std::promise<int>&& prom) 
        {
            prom.set_value(3);  // 4. 스레드에서 promise 객체를 사용하여 값을 설정 , //set_value(): 비동기 작업의 결과를 설정합니다.
        }, std::move(prom));  // move를 통해 prom 객체의 소유권을 새로운 스레드로 이동

        // prom이 set_value 작업을 완료할때까지 fut.get() 이 하염없이 대기한다.
        std::cout << fut.get() << std::endl;  // 5. future 객체를 통해 비동기 작업의 결과를 얻음
        t1.join();  // 6. 스레드가 종료될 때까지 기다림

    }
 */
    // thread 와 async의 차이 : asyinc 는 join을 쓰지 않아도, 쓸 필요가 없다.
    // async를 받아주는 return type으로 future를 쓰면 비동기처리 해버림
    {
        std::future<void>  f1 = std::async([]
        {
            std::cout<<"async1 start"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout<<"async1 end"<<std::endl;
        });

        std::future<void> f2 = std::async([]
        {
            std::cout<<"async2 start"<<std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout<<"async2 end"<<std::endl;
        });
    
        std::cout <<"Main function"<<std::endl;
    
    }
    return 0;
}