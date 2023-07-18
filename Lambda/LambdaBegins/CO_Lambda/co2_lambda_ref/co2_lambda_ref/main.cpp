//
//  main.cpp
//  co2_lambda_ref
//
//  Created by Sathya Babu on 30/11/21.
//

#include <iostream>
#include <string>
using namespace std;

auto makeMeaDeveloper( const std::string& name)
{
    // capture name by ref and return lambda..
    return  [ & ] { cout << " I'm a developer, My name is "<< name << endl ; } ;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    auto sayName { makeMeaDeveloper("Sathya") };
    sayName();
    return 0;
}
/*
 Hello, World!
  I'm a developer, My name is Sathya
 Program ended with exit code: 0
 */
