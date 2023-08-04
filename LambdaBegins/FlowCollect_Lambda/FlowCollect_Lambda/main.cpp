//
//  main.cpp
//  FlowCollect_Lambda
//
//  Created by Sathya Babu on 20/07/23.
//

/*
 we create a Flow class that holds a sequence of elements. The collect function takes a lambda callback as an argument, and it calls the callback for each element in the flow. In the main function, we create a Flow of integers and use the collect function to print each element using the lambda callback.

 Note that this is a simplified version, and in a real-world scenario, you might want to handle more complex use cases and error handling. Additionally, in C++17, there is no built-in coroutine support like in Kotlin's Flow, so this example doesn't have the same capabilities as Kotlin's Flow. However, this illustrates a basic way to achieve similar behavior using C++17 and lambdas.






 */
#include <iostream>
#include <vector>
#include <functional>

template <typename T>
class Flow {
public:
    Flow(std::initializer_list<T> elements) : elements_(elements) {}

    void collect(const std::function<void(const T&)>& callback) {
        for (const auto& element : elements_) {
            callback(element);
        }
    }

private:
    std::vector<T> elements_;
};

int main() {
    Flow<int> flow = {1, 2, 3, 4, 5};

    flow.collect( [](const int& value) {
        std::cout << "Received value: " << value << std::endl;
    });

    return 0;
}
