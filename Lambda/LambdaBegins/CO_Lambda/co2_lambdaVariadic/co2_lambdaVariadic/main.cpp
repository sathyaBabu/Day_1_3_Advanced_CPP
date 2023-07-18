//
//  main.cpp
//  co2_lambdaVariadic
//
//  Created by Sathya Babu on 30/11/21.
//

#include <iostream>
using namespace std;


void print(){}
//                 o(n)
template<typename First, typename ...  Rest>
void print( const First& first, const Rest&... rest ){
    cout << first << endl ;
    print( rest...);
    
}
//
//template<typename  T>
//fun( T t ){
//
//}

int main(int argc, const char * argv[]) {
                  //  [ capture list ] ( paramater ) -> return type
    auto variadic_generic_Lambda =[] ( auto... param){ print(param...); };
    variadic_generic_Lambda(1,"Bangalore",23,22,"Sathya",987);
    
    
    // fold expr
    
    constexpr auto add = [] <class... T>( T ...args){
        return ( args +...);
    };
    
    cout << " sum from fold expressios  " << add(1,2,3) << endl ;
    
    return 0;
}
