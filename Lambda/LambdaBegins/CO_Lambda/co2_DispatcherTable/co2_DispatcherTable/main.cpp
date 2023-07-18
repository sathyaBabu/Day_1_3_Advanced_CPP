//
//  main.cpp
//  co2_DispatcherTable
//
//  Created by Sathya Babu on 30/11/21.
//

// Visit, visitor( double dispatch ), Acyclic dispatch( Dyn dispatch ) dispatch  Callable ( Single dispatch )

#include <cmath>
#include <functional>
#include <iostream>
#include <map>

int main(){

  std::cout << std::endl;

  // dispatch table                     ret     v1     v2
  std::map< const char , std::function<double(double,double)> > dispTable{
    {'+',    [](double a, double b){ return a + b;} },
    {'-',    [](double a, double b){ return a - b;} },
    {'*',    [](double a, double b){ return a * b;} },
    {'/',    [](double a, double b){ return a / b;} } };

  // do the math
  std::cout << "3.5+4.5= " << dispTable['+'](3.5,4.5) << std::endl;
  std::cout << "3.5-4.5= " << dispTable['-'](3.5,4.5) << std::endl;
  std::cout << "3.5*4.5= " << dispTable['*'](3.5,4.5) << std::endl;
  std::cout << "3.5/4.5= " << dispTable['/'](3.5,4.5) << std::endl;

  // add a new operation
  dispTable['^']=  [](double a, double b){ return std::pow(a,b);};
  std::cout << "3.5^4.5= " << dispTable['^'](3.5,4.5) << std::endl;

  std::cout << std::endl;

};


/*
 
 
 
 3.5+4.5= 8
 3.5-4.5= -1
 3.5*4.5= 15.75
 3.5/4.5= 0.777778
 3.5^4.5= 280.741

 Program ended with exit code: 0
 */
