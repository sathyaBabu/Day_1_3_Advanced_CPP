//
//  main.cpp
//  co2_lambdaBreakup_4
//
//  Created by Sathya Babu on 30/11/21.
//

#include <variant>
#include <cstdio>
#include <vector>

using var_t = std::variant<int, const char*>;

template <class... Ts>
struct Print : Ts... {
    using Ts::operator()...;
};

template <class... Ts> // (1)
auto MakePrint(Ts... ts) {
    return Print<Ts...>{ts...};  // we r passing { ts...} to print struct hence calls the () operator
     // Compiler will not identify TS so we declare return type as follows -> Overload<Ts...>;
      // or {ts...};
 
}

int main() {
    std::vector<var_t> vars = {1, 2, "Hello, World!"};

    for (auto& v : vars) {
        std::visit(
            MakePrint( // (2)
                [](const char* str) { puts(str); },
                [](          int i) { printf("%d\n", i); }
                ),
            v);
    }

    return 0;
}
