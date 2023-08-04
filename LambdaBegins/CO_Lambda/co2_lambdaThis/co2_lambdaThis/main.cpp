//
//  main.cpp
//  co2_lambdaThis
//
//  Created by Sathya Babu on 30/11/21.
//

#include <iostream>
using namespace std;


class Foo
{
public:
    Foo () : _x( 007 ) {}
    
    
    void foo() { { cout << " foo() called... .. .  "<<endl ; }}

    void func ()
    {
        // a very silly, but illustrative way of printing out the value of _x
        [this ] (        ) { foo(); cout <<  _x << " James Bond... .. .  "<<endl ; } ();
    }

private:
        int _x;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Foo f ;
    f.func();
    return 0;
}

/*
 
 foo() called... .. .
 7 James Bond... .. .
 Program ended with exit code: 0
 
 */
