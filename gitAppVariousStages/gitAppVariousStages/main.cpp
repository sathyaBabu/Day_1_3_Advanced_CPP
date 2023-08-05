//
//  main.cpp
//  gitAppVariousStages
//
//  Created by Sathya Babu on 04/08/23.
//

/*
 1.  This is my first remarks added after copying this file into this folder.
 
 */

#include <iostream>
#include<vector>
using namespace std ;

class MyNumber{
    
    public :
    
   
    
    MyNumber( int a , int b ){
        cout << " Normal constructor " << a << " " << b << endl ;
        
    }
    MyNumber( int a , int b , int c ){
        cout << " Normal constructor " << a << " " << b   << " " << c << endl ;

    }
    void print(){
        for(auto itm :  myVec){
            cout << itm << " " ;
            
        }
    }
    
    private :
    
    std::vector< int > myVec ;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Git code Basic one... With Constructors !\n";
    
//   depricated way of coding..
    
    
    MyNumber myNum(10,20);
    myNum.print();
    
    
    
    
    return 0;
}
/*
 
 Git code Basic one... With Constructors !
  Normal constructor 10 20
 
 */
