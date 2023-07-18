//
//  main.cpp
//  co2_VisitorMCpp
//
//  Created by Sathya Babu on 30/11/21.
//

//*****************
// http://www.cplusplus.com/forum/general/136902/

#include <iostream>
#include <memory>
#include <vector>

struct Animal;
struct Cat;
struct Dog;
struct Llama;
struct AnimalVisitor
{
    virtual void Visit(Animal*) = 0;
    virtual void Visit(Cat*) = 0;
    virtual void Visit(Dog*) = 0;
    virtual void Visit(Llama*) = 0;
    virtual ~AnimalVisitor() = default;
};

struct Animal
{
    virtual ~Animal() = default;
    virtual void Visit(AnimalVisitor*) = 0;
};

// Acyclic visitor..
template<class T>
struct VisitableAnimal : Animal
{
   void Visit(AnimalVisitor* _visitor) override
   {
      _visitor->Visit(static_cast<T*>(this));  // logical BUG?????
                    //   dynamic_cast<<#type#>>(<#expression#>)
       // rat which falls out of the inheritance
   }
};

struct Cat : VisitableAnimal<Cat>   // red   housing loan
{
};

struct Dog : VisitableAnimal<Dog>   // blue    study loan
{
};

struct Llama : VisitableAnimal<Llama>
{};

struct DefaultAnimalVisitor : AnimalVisitor
{
    void Visit(Animal*) override{}
    void Visit(Cat* _cat) override{Visit(static_cast<Animal*>(_cat));}
    void Visit(Dog* _dog) override {Visit(static_cast<Animal*>(_dog));}
    void Visit(Llama* _llama) override {Visit(static_cast<Animal*>(_llama));}
};

struct AllButCatFilter : DefaultAnimalVisitor
{
    using DefaultAnimalVisitor::Visit;
    void Visit(Animal* _animal) override
    {
        animals_.push_back(_animal);
    }
    void Visit(Cat*) override{/*intentionally left empty*/}
    std::vector<Animal*> animals_;
};

int main()
{
    std::vector<std::unique_ptr<Animal>> animals;
    for(size_t i = 0; i < 10; ++i)
    {
        if(i < 8)
        {
            if (i % 2 == 0)
                animals.push_back(std::make_unique<Dog>());
            else
                animals.push_back(std::make_unique<Llama>());
        }
        else
            animals.push_back(std::make_unique<Cat>());
    }
    AllButCatFilter visitor;
    for (auto& animalPtr : animals)
    {
        animalPtr->Visit(&visitor);
    }
    std::cout << "visitor encountered " << visitor.animals_.size() << " non-cats\n";
}
//visitor encountered 8 non-cats
//Program ended with exit code: 0


// RIGHT CODE impliment this logic with the above code
//#include <iostream>
//#include <string>
//
//struct A
//{
//    struct visitor { virtual ~visitor() = default ; virtual bool accept( A* ) { return false ; } };
//    virtual ~A() = default ;
//    virtual bool accept( visitor& ) = 0 ;
//    bool accept( visitor&& v ) { return accept(v) ; }
//};
//
//template < typename BASE > struct base : BASE
//{
//    struct visitor { virtual ~visitor() = default ; virtual bool accept( base* ) = 0 ; };
//    virtual bool accept( A::visitor& av ) override
//    {
//        auto dv = dynamic_cast< base::visitor* >( std::addressof(av) ) ;
//        return dv ? dv->accept(this) : av.accept(this) ;
//    }
//};
//
//struct B : base<A> {};
//struct C : base<A> {};
//struct D : base<B> {};
//struct E : base<C> {};
//struct F : base<D> {};
//
//template < typename T > struct counting_visitor : A::visitor
//{
//    virtual bool accept( A* p ) { return dynamic_cast< T* >(p) ? ++cnt : false ; }
//    operator int () const { return cnt ; }
//    private: int cnt = 0 ;
//};
//
//int main()
//{
//    A* seq[] { new B, new C, new D, new E, new F, new C, new B, new F, new E, new B } ;
//
//    counting_visitor<B> cvb ;
//    counting_visitor<C> cvc ;
//    counting_visitor<D> cvd ;
//    for( A* p : seq ) { p->accept(cvb) ; p->accept(cvc) ; p->accept(cvd) ; }
//
//    std::cout << "B: " << cvb // 6
//              << "\nC: " << cvc // 4
//              << "\nD: " << cvd << '\n' ; // 3
//}
