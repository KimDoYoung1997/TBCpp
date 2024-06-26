#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <utility>
void sequence_containers()  //vector, deque
{
    //vector
/*     {
        std::vector<int> vec;   // #include <vector>
    for (int i=0;i<10;i++)
    {
        // vector는 연속된 메모리 블록을 사용하는 동적 배열로, 임의 접근이 매우 빠르며, 주로 후미에서 요소를 추가/제거할 때 효율적입니다.
        vec.push_back(i);   
    }
    for (auto &e : vec)
    {
        std::cout<<e<<" ";
    }std::cout <<std::endl;
    }
 */    
    
    //deque
/*     {
    std::deque<int> deq;
    for(int i=0;i<10;i++)
    {
        // deque는 두 개의 끝이 있는 큐로, 여러 메모리 블록을 사용하여 양 끝에서 요소를 효율적으로 추가/제거할 수 있습니다.
        deq.push_back(i);
        deq.push_front(i);
    }
    for(auto &e : deq)
    {
        std::cout <<e <<" ";
    }std::cout<<std::endl;
    } */
}

void associative_containers()
{
    //set : 집합 , 동일 원소는 중복되지 않음
/*     // 중복 허용 안 함: 동일한 값의 중복 요소를 저장할 수 없습니다.
    // 자동 정렬: 요소들이 항상 정렬된 상태로 유지됩니다.
    // 효율적인 검색: 이진 탐색 트리 구조로 인해 삽입, 삭제, 검색 연산이 평균 O(log n)의 시간 복잡도를 가집니다.
    {
        std::set<std::string> str_set;
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello"); // 중복된 원소는 버림

        std::cout <<str_set.size() << std::endl;    // 중복된 원소는 버림 , size는 3이 아닌 2가 출력됨
    
        for(auto&e : str_set)
        {
            std::cout<<e<<" ";
        }std::cout<<std::endl;

        if (str_set.find("World") != str_set.end()) 
        {
        std::cout << "World 이 있습니다." << std::endl;
        }
        if (str_set.find("world") == str_set.end()) 
        {
        std::cout << "world 이 없습니다." << std::endl;
        }     

    } */

    // multiset : duplication is allowed
/*     {
        std::multiset<std::string> str_multiset;
        str_multiset.insert("Hello");
        str_multiset.insert("World");
        str_multiset.insert("Hello"); // 중복된 원소는 버림

        std::cout <<str_multiset.size() << std::endl;    // 중복된 원소를 버리지 않음 , size는 3
    
        for(auto&e : str_multiset)
        {
            std::cout<<e<<" ";
        }std::cout<<std::endl;

        if (str_multiset.find("World") != str_multiset.end()) 
        {
        std::cout << "World 이 있습니다." << std::endl;
        }
        if (str_multiset.find("world") == str_multiset.end()) 
        {
        std::cout << "world 이 없습니다." << std::endl;
        }     

    }
 */

    // map : key/value 
/*     {
        std::map<char,int> map;
        map['c']=50;
        map['a']=10;
        map['b']=20;

        std::cout <<map['a']<<std::endl;
        map['a']=100;
        std::cout <<map['a']<<std::endl;

        for(auto &e:map)
        {
            std::cout<<e.first<<" "<<e.second<<" ";
        }std::cout<<std::endl;
    }
 */

    // multimap : duplicated keys
/*         {
        std::multimap<char,int> multimap;
        multimap.insert(std::pair('c',10));
        multimap.insert(std::pair('a',10));
        multimap.insert(std::pair('b',10));
        multimap.insert(std::pair('a',100));

        std::cout <<multimap.count('a')<<std::endl;
        for(auto &e:multimap)
        {
            std::cout<<e.first<<" "<<e.second<<" ";
        }std::cout<<std::endl;
    }
 */
}

void container_adapters()
{
    //stack
/*     {
        std::cout <<"Stack"<<std::endl;
        std::stack<int> stack;
        stack.push(1);   // push adds a copy , push는 복사 생성자나 이동 생성자를 호출할 수 있습니다.

        stack.emplace(2);   // emplace constructs a new object , emplace는 직접 생성하기 때문에 불필요한 복사나 이동을 피할 수 있어 더 효율적일 수 있습니다.
        stack.emplace(3);
        std::cout<<stack.top() <<std::endl;
        stack.pop();
        std::cout <<stack.top()<<std::endl;
    } 
*/

    // queue
/*     {
        // std::queue는 C++ 표준 템플릿 라이브러리(STL)의 컨테이너 어댑터 중 하나로, FIFO(First-In-First-Out) 구조를 구현합니다. 
        // 즉, 먼저 들어간 요소가 먼저 나오는 구조입니다. 이는 일반적인 대기열(queue)의 동작 방식과 같습니다.
        // 먼저 추가된게 먼저 pop됨
        std::cout<<"Queue"<<std::endl;
        std::queue<int> queue;
        queue.push(1);
        queue.push(2);
        queue.push(3);

        std::cout<<queue.front() <<" "<<queue.back() << std::endl;
        queue.pop();  // 맨 앞의 요소 1을 제거
        std::cout<<queue.front() <<" "<<queue.back() << std::endl;

    }
 */    

    // Priority queue
    {
        std::cout<<"Priority Queue"<<std::endl;
        std::priority_queue<int>priority_queue;

        for(const int n : {1,8,5,6,3,4,0,9,7,2})
        {
            priority_queue.push(n);
        }
        for(int i=0;i<10;i++)
        {
            std::cout<<priority_queue.top() << std::endl;
            priority_queue.pop();
        }

    }

}


int main()
{
    sequence_containers();
    associative_containers();
    container_adapters();


    return 0;
}