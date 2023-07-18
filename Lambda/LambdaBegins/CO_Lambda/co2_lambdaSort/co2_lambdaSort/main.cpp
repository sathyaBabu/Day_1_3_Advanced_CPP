//
//  main.cpp
//  co2_lambdaSort
//
//  Created by Sathya Babu on 30/11/21.
//

#include <algorithm>
#include <functional>
#include <array>
#include <iostream>
#include <string_view>
using namespace std;

int main(int argc, const char * argv[]) {
    
    std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
        // *** std::string_view is to avoid copying data which is already owned somewhere else
        auto print = [ &s ](std::string_view const rem) {
            for (auto a : s) {
                std::cout << a << ' ';
            }
            std::cout << ": " << rem << '\n';
        };
    
    
    std::sort(s.begin(), s.end());
    print("sorted with the default operator < ");
    
        std::sort(s.begin(), s.end(), std::greater<int>());
        print("sorted with the standard library compare function object");
    
     struct {
         
            bool operator()(int a, int b) const { return a < b; }
         
        } customLess;
     
    // check the duplicates..
    
    
    // Graph -> Least traffic roads, Toll free roads,
    
    std::sort(s.begin(), s.end() , customLess);  // adapter
    print("sorted with the custom less  object");
    
    
    //
    std::sort(s.begin(), s.end(), [](int a, int b) {
            return a > b;
        });
        print("sorted with a lambda expression");
    
    
    typedef int (*funPtr)();
    
    funPtr f = [] () -> int { cout << " lets return a val from a fnptr "<< endl; return 456; };
    
    cout << " Val from fnPTR " << f()<< endl ;
    
    
}

/*
 0 1 2 3 4 5 6 7 8 9 : sorted with the default operator <
 9 8 7 6 5 4 3 2 1 0 : sorted with the standard library compare function object
 0 1 2 3 4 5 6 7 8 9 : sorted with the custom less  object
 9 8 7 6 5 4 3 2 1 0 : sorted with a lambda expression
  Val from fnPTR  lets return a val from a fnptr
 456
 Program ended with exit code: 0
 */

   


