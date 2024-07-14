#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void add_numbers(std::vector<int>& vec, int start, int end) {
    vec.reserve(end - start); // 벡터 크기를 미리 예약
    for (int i = start; i < end; ++i) {
        vec.emplace_back(i);
    }
    std::cout<<"temp_vector size : "<<vec.size()<<std::endl;
}

int main() {
    const int total_numbers = 100000000;
    const int num_threads = 4;
    const int range = total_numbers / num_threads;

    // 각 스레드가 데이터를 추가할 별도의 벡터 생성
    std::vector<std::vector<int>> temp_vectors(num_threads);

    // 시간 측정 시작
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;

    // 스레드를 생성하고 데이터 추가 작업 시작
    for (int i = 0; i < num_threads; ++i) {
        int start = i * range;
        int end = (i + 1) * range;
        threads.emplace_back(add_numbers, std::ref(temp_vectors[i]), start, end);
    }

    // 모든 스레드가 작업을 완료할 때까지 기다림
    for (auto& thread : threads) {
        thread.join();
    }

    // 최종 벡터에 데이터를 병합
    std::vector<int> final_vector;
    final_vector.reserve(total_numbers); // 최종 벡터의 크기를 미리 예약

    for (const auto& vec : temp_vectors) {
        final_vector.insert(final_vector.end(), vec.begin(), vec.end());
    }

    // 시간 측정 종료
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    // 확인: 벡터의 크기를 출력
    std::cout << "Total numbers added: " << final_vector.size() << std::endl;
    std::cout << "Time taken (parallel): " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
