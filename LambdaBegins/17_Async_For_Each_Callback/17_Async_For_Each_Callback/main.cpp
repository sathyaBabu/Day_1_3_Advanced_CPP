//
//  main.cpp
//  17_Async_For_Each_Callback
//
//  Created by Sathya Babu on 31/07/23.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <future>



template <typename InputIt, typename Callback>
void for_each_async(InputIt first, InputIt last, Callback callback) {
    std::vector<std::future<void>> futures;

    for (; first != last; ++first) {
        futures.emplace_back(std::async(std::launch::async, callback, *first));
    }

    for (auto& future : futures) {
        future.wait();
    }
}
auto printSquare(int x )  {
    std::cout << "Square of " << x << " is " << x * x << std::endl;

}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Define the callback function
//    auto printSquare = [](int x) {
//        std::cout << "Square of " << x << " is " << x * x << std::endl;
//    };

    // Use for_each_async with the callback function
    for_each_async(numbers.begin(), numbers.end(), printSquare);

    return 0;
}

/*
 its eratic due to async call..
 
 Square of Square of 2 is 4
 1 is 1
 Square of 3 is 9
 Square of 4 is 16
 Square of 5 is 25
 */
