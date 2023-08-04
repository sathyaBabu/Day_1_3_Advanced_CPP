//
//  main.cpp
//  17_agggregateExtension
//
//  Created by Sathya Babu on 09/07/23.
//
#include <iostream>

struct Point {
    int x;
    int y;
};


// Phae II

struct Data_a {
     std::string name;
     double      age;
};
   struct PData : Data_a {
     bool critical;
       
       // Phase  I     ***---> next Phase Aggregation needs no constructor
       
    PData (const std::string& s, double d, bool b) : Data_a{ s,d }, critical{b} {}
       
       
     void print( ) const {
           std::cout << '[' << name << ',' << age <<  ' ' <<  critical << "]\n"; }
};



int main() {
    
    
    
    // Legacy way
    Point pp;
    pp.x = 12 ;
    pp.y = 13 ;

    std::cout << "Point: (" << pp.x << ", " << pp.y << ")" << std::endl;
    
    //Point p1{ x = 10, y = 20}; // x = 10, y = 20 Use of undeclared identifier 'x', 'y'
    Point p2{ 10,  20 }; // ok
    
    // Phase I  c++ 17
    Point p{ .x = 10, .y = 20 };
    std::cout << "Point: (" << p.x << ", " << p.y << ")" << std::endl;
    
    
    
    // Phase I
    
    //Phase  I
    // Goes well with constructor as well as  Aggregate too
      PData data_y{ "Suresh ", 26.778, true};


                
    data_y.print();  // neds constructor
    
    // Phase II
    
    // Goes wellonly  with Aggregate
    // put A REM FOR CONSTRUCTOR  //Phase  I
     
//      PData data_y_Aggregate{ {"Samarnika ", 46.778}, true};
//    data_y_Aggregate.print();  // Constructor is not required for Aggregete init
//
    
    PData pd( "bangalore. ", 560043, true);
    pd.print();

    return 0;
}

/*
 
 Point: (12, 13)
 Point: (10, 20)
 [Suresh ,26.778 1]
 [Samarnika ,46.778 1]
 Program ended with exit code: 0
 
 // Phase II open the constructor remark
 
 Point: (12, 13)
 Point: (10, 20)
 [Suresh ,26.778 1]
 [bangalore. ,560043 1]
 Program ended with exit code: 0
 */
