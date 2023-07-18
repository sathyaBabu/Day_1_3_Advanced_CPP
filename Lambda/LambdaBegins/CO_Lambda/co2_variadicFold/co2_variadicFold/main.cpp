//
//  main.cpp
//  co2_variadicFold
//
//  Created by Sathya Babu on 30/11/21.
// c++11

#include <iostream>
#include<vector>
using namespace std;

void print(){
    cout << endl ;

}
//
//template<typename T>
//void print( const T& t ){
//    cout << t << endl ;
//
//}


template<typename First, typename ...  Rest>
void print( const First& first, const Rest&... rest ){
    cout << first << endl ;
    print( rest...);
    
}

// Phase II Fold expressions

template<typename  ...T>
auto letsDoSomeWork( T ... t){
    return( t + ...);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //print();
    print(1);
    
    print(10,20);
    print(100,200, 300);
    print("First",2,"Third",4.89,"Fifth");
    
    // fold expressions
    cout << letsDoSomeWork(1,2,3,4,5)<< endl;
    
    // emplace call back..
    
    std::vector< int > myvector = { 10,20,30};  // initilizer list
    
    myvector.emplace_back(100);
    myvector.emplace_back(200);
    myvector.emplace_back(300);
    myvector.emplace_back(400);
    
    cout << "My vector contains : ";
    
    for( auto& x : myvector){   // begin() end()
        cout << " data " << x << endl;
        
    }
    
    return 0;
}
/*
 
   class Media player(  Record played.. Casset Spoool tape cd vcd dvd br, avi mp3 mp4 >
 
       start stop play rev ff.. pause..  codec..   codec... codec.. codec..
 
 
 */
