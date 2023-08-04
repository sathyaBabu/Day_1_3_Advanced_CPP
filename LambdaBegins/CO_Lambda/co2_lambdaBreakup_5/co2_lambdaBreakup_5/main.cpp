//
//  main.cpp
//  co2_lambdaBreakup_5
//
//  Created by Sathya Babu on 30/11/21.
//

#include <variant>
#include <cstdio>
#include <vector>

using var_t = std::variant<int, const char*>;
// Phase I
template <class... Ts>
struct Print : Ts... {
    using Ts::operator()...;
};

template <class... Ts> // (1)
auto MakePrint(Ts... ts) {  // we created a MakePrint wrapper...
    return Print<Ts...>{ts...};  // we r passing { ts...} to print struct hence calls the () operator
}

// Phase II  Boiler plate code..  c++20 this gets depricated..
template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;


int main() {
    std::vector<var_t> vars = {1, 2, "Hello, World!"};

    for (auto& v : vars) {
        std::visit(
                   overload{ // (2)  //  MakePrint(    // (2) phase i
                [](const char* str) { puts(str); },
                [](          int i) { printf("%d\n", i); }
                   },               // ), // phase i
            v);
    }

    return 0;
}

/*
 
 1
 2
 Hello, World!
 Program ended with exit code: 0
 */


/*
 
 for (auto& v : vars) {
     std::visit(
         MakePrint( // (2)
             [](const char* str) { puts(str); },
             [](          int i) { printf("%d\n", i); }
             ),
         v);
 }
 */
