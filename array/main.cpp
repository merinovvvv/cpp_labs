#include <iostream>
#include "Array.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main() {
    spdlog::set_level(spdlog::level::debug);
    try {
        spdlog::info("Welcome to spdlog!");
        std::initializer_list<int> list1 = {1, 2, 3};
        std::initializer_list<int> list2 = {4, 5, 6};
        Array <int> arr1 (list1);
        Array <int> arr2(list2);
        Array <int> arr3 = arr1 + arr2;
        std::cout << arr3 << '\n';

        Array<int> arr(list1);
        Array<int> result = ++arr;
        std::cout << result << '\n';

        result.getItem(10);

    }catch (const std::exception& e) {
        std::cerr << "Error occured: " << e.what() << std::endl;
        exit(0);
    }
    return 0;
}
