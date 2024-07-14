#include <iostream>
#include <vector>
#include <chrono>

void add_numbers_sequential(std::vector<int>& vec, int total_numbers) {
    vec.reserve(total_numbers); // 벡터 크기를 미리 예약
    for (int i = 0; i < total_numbers; ++i) {
        vec.emplace_back(i);
    }
}

int main() {
    const int total_numbers = 100000000;

    // 최종 벡터 생성
    std::vector<int> final_vector;

    // 시간 측정 시작
    auto start_time = std::chrono::high_resolution_clock::now();

    // 순차적으로 데이터 추가
    add_numbers_sequential(final_vector, total_numbers);

    // 시간 측정 종료
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    // 확인: 벡터의 크기를 출력
    std::cout << "Total numbers added: " << final_vector.size() << std::endl;
    std::cout << "Time taken (sequential): " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
