//
//  main.cpp
//  co2_TrailingReturnType
//
//  Created by Sathya Babu on 30/11/21.
//
/*
   Day 2 :
    Trailing return type
    Alias typedef -> using
    variadic expressions - varg... only one data type..
    emplace callback - vectors..
    
    lambda..
 
    unions.. variants
    visit
 
    visitor design patterns ( double dispatch ), Acyclic visitors, Dispatching mach..
    Assignments ..
 
    Range based for loops..
    
 
 
 */

#include <iostream>
using namespace std;
//
//template<typename T, typename U>  // we donot know for now about the data type
//U  sum( T a, T b ){
//    return a+b ;
//}


//
//template<typename T>  // we donot know for now about the data type
//decltype( a+b ) sum( T a, T b ){ // a and b are used before the defining it..
//    return a+b ;
//}




template<class T>
class tmp{
public:
    int i ;
};


int funn()
{
    int a = 123 ;
    return a ;
    
}

auto fun() -> int  // Function with trailing return type must specify return type 'auto', not 'int'
{ return 123 ;}

// data type for a function ptr..
int (*myFunptr)( );


      //  tmp<int>   (*     (*foo())()  ) () {

        auto foo() ->auto(*)() -> tmp<int>(*)() {
         
                    return 0;
                }


//   showw(12,3,4,5,6,7,8)

template<typename T1, typename  T2>  // we donot know for now about the data type
auto sum( T1& t1, T2& t2 ) ->decltype(t1+t2) { // a and b are used before the defining it..
    return t1 + t2  ;
}

int main(int argc, const char * argv[]) {
    
    
    auto a = 10 ;
    auto b = 23.12 ;
    
    auto c = sum( a , b );
    cout << " Sum = " << c << endl;
    auto foo = fun ;
    
    cout << " Foo returns " << foo();
    
    myFunptr = fun;
    
    cout << " Simple Foo returns " <<  myFunptr();
    
    return 0;
}
