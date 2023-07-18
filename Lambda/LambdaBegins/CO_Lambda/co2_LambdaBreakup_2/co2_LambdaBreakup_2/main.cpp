//
//  main.cpp
//  co2_LambdaBreakup_2
//
//  Created by Sathya Babu on 30/11/21.
//
#include <variant>
#include <cstdio>
#include <vector>

using var_t = std::variant<int, const char*>;

struct PrintInt { //(1)
    void operator() (int i) {
        printf("%d\n", i);
    }
};

struct PrintCString { // (2)
    void operator () (const char* str) {
        puts(str);
    }
};

struct Print : PrintInt, PrintCString { // (3)
    using PrintInt::operator();
    using PrintCString::operator();
};

int main() {
    std::vector<var_t> vars = {1, 2, "Hello, World!"};

    for (auto& v : vars) {
        std::visit(Print{}, v);
    }

    return 0;
}


