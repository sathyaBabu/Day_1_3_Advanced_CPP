//
//  main.cpp
//  co2_lambdaBreakup_3
//
//  Created by Sathya Babu on 30/11/21.
//
///////////////////////////  step 3**

#include <variant>
#include <cstdio>
#include <vector>

using var_t = std::variant<int, const char*>;

struct PrintInt {
    void operator() (int i) {
        printf("%d\n", i);
    }
};

struct PrintCString {
    void operator () (const char* str) {
        puts(str);
    }
};
            /*
            In (1) and (2), we define the same operators as before, but in separate structs.
             In (3), we are inherit from both of those structs, then explicitly use their operator().
            This results in exactly the same results as before. Next, we convert Print into a class template.
            IThis is a  a variadic template.
            */

//
//struct Print : PrintInt, PrintCString { // (3)
//    using PrintInt::operator();
//    using PrintCString::operator();
//};

template <class... Ts>   // **** replica of 5979 ***
struct Print : Ts... {  // PrintCString, PrintInt
    using Ts::operator()...;
};

int main() {
    std::vector<var_t> vars = {1, 2, "Hello, World!"};

    for (auto& v : vars) {
        std::visit(Print<PrintCString, PrintInt>{}, v);
    }

    return 0;
}
/*
 
 
 1
 2
 Hello, World!
 Program ended with exit code: 0
 */
