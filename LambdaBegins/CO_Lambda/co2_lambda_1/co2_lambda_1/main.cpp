//
//  main.cpp
//  co2_lambda_1
//
//  Created by Sathya Babu on 30/11/21.
//

#include <iostream>
using namespace std;

constexpr auto sum = [] ( const auto &a , const auto &b){ return a+b; };

class Anonymous{   // function objects...
    public :
    
    template<class T1,class T2>
    constexpr auto operator()( T1 a , T2 b) {
        return a + b ;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    Anonymous an ;
    auto res = an(10,12);
    
    std::cout << "res = " << res<< endl;
    
    std::cout << "Lambda sum  = " <<sum(12,32);
    
    
    return 0;
}
/*
 res = 22
 Lambda sum  = 44
 
 Program ended with exit code: 0
 */
