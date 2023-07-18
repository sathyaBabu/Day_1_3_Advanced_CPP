//
//  main.cpp
//  co2_LambdaBreakup_1
//
//  Created by Sathya Babu on 30/11/21.
//

//////////////////////////    step 1
#include <variant>
#include <cstdio>
#include <vector>

using var_t = std::variant<int, const char*>; // (1)

struct Print { // (2)
    void operator() (int i) {
        printf("%d\n", i);
    }

    void operator () (const char* str) {
        puts(str);
    }
};

int main() {
    std::vector<var_t> vars = {1, 2, "Hello, World!"}; // (3)

    for (auto& v : vars) {
        std::visit(Print{}, v); // (4)
    }

    return 0;
}
/*
 1
 2
 Hello, World!
 Program ended with exit code: 0
 */
