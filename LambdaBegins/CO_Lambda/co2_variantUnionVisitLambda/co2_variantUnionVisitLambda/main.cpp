//
//  main.cpp
//  co2_variantUnionVisitLambda
//
//  Created by Sathya Babu on 30/11/21.
//

#include <variant>
#include <iostream>
#include <cassert>
using namespace std;




// Union Phase I

union Value{
    int i;
    double d;
};
//
Value v;


// variant Phase II

struct S
{
    S(int i) : i(i) {}
    int i;
};

class Derived : public std::variant<int, std::string> {
  };

// Phase VI



class MyType
{
public:
    MyType() { std::cout << "MyType::MyType \n"; }
    ~MyType() { std::cout << "MyType::~MyType\n"; }
};

class OtherType
{
public:
    OtherType() { std::cout << "OtherType::OtherType \n"; }
    OtherType(const OtherType&) {
        std::cout << "OtherType::OtherType(const OtherType&) \n";
    }
    ~OtherType() { std::cout << "OtherType::~OtherType \n"; }
};


int main(int argc, const char * argv[]) {
    
    
    // Phase 1
        
        v.d = 76.12345;  // v now holds a double
        cout << v.d << endl; // 76.12345;
        
        cout << v.i << endl; // bad access: 1346901744
        
    
    
    // Phase 2
        variant<int, float> vv{99};

        // access by index
        cout << "access by index "<<(get<0>(vv)) << endl;  // 99
     // access by index 99
        // access by type
        cout <<  "access by index " << (get<int>(vv)) << endl;  // 99
       // access by index 99
    
   // cout <<  "BADDDDDD  access by index " << (get<1>(vv)) << endl;  // 99
    
    
    // visit...
    
    //  Phase 3
        std::variant<int, std::string> vvv{78};  // visitor..
        //   container(        visitable/lambda ,visitor/variant);
        std::visit( [](auto&& elem){std::cout << "lambda is visited by variant v ! "<< elem << endl; },    vvv );
         // lambda is visited by variant v ! 78
      
    
    // Phase 4
        //  variants are unions
        std::variant<int, std::string> var5{120},var6{"hi"};
        // index      0          1
        
        std::cout << "  var 5 int   "<< std::get<0>(var5) << '\n';  //  var 5 int   120
        std::cout << "  var 6 data  "<< std::get<1>(var6) << '\n';  //  var 6 data  hi
        std::cout << "  var 5 index "<< var5.index() << '\n';       // var 5 index 0
        std::cout << "  var 6 index "<< var6.index() << '\n';       // var 6 index 1
        std::cout << "  fetch data from Union  0 " << std::get<0>(var5);   // fetch data from Union  0 120
       
    
           std::variant<MyType, OtherType> v;

             v = OtherType();  //  MyType::~MyType Other type gets constructed: OtherType::OtherType(const OtherType&)
    
    v = MyType();

    // a generic lambda:
       auto PrintVisitor = [](const auto& t) { std::cout << t << "\n"; };

       std::variant<int, float, std::string> intFloatString { "Hello" };
      
        std::visit(PrintVisitor, intFloatString);
    
    
    return 0;
}
