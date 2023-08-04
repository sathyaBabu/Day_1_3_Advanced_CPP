//
//  main.cpp
//  co2_lambdaMutable
//
//  Created by Sathya Babu on 30/11/21.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    int ammo{ 10 };
    
    auto shoot{
        
        // add mutable after the param list
        [ ammo] () mutable {
            --ammo ;
            cout << " Fired.. "<< ammo  <<" Shots left.."  << endl;
            
        }
        
    };
    
    shoot();
    shoot();
    shoot();
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
/*
 Fired.. 9 Shots left..
 Fired.. 8 Shots left..
 Fired.. 7 Shots left..
Hello, World!
Program ended with exit code: 0
 */
