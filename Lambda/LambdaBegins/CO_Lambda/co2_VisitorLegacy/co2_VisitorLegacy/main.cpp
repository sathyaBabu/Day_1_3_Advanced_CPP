//
//  main.cpp
//  co2_VisitorLegacy
//
//  Created by Sathya Babu on 30/11/21.
//


#include<iostream>
using namespace std;
// Visitor Accept
class Color   /// red  - blue
{
  public:
    virtual void accept(class Visitor*) = 0;
};

//class Visitor    // countVisitor -  CallVisitor call_operation;
//{
//  public:
//    virtual void visit(Red*) = 0;
//    virtual void visit(Blu*) = 0;
//};
///////////////////////////////////////////////////////////////////////////////////////////
class Red: public Color
{
  public:
     /*virtual*/void accept(Visitor*);
    void eye()
    {
        cout << "Red::eye\n";
    }
};
class Blu: public Color
{
  public:
     /*virtual*/void accept(Visitor*);
    void sky()
    {
        cout << "Blu::sky\n";
    }
};
// 2nd Visitor

class Visitor
{
  public:
    virtual void visit(Red*) = 0;   // ladies
    virtual void visit(Blu*) = 0;   // gents cycle
};

class CountVisitor: public Visitor
{
  public:
    CountVisitor()
    {
        m_num_red = m_num_blu = 0;
    }
     /*virtual*/void visit( Red* )   // this  red
    {
        ++m_num_red;
    }
     /*virtual*/void visit(Blu*)
    {
        ++m_num_blu;
    }
    void report_num()
    {
        cout << "Reds " << m_num_red << ", Blus " << m_num_blu << '\n';
    }
  private:
    int m_num_red, m_num_blu;
};

//class SubClassCountVisitor : public CountVisitor , Visitor{
//
//    /*virtual*/void visit( Red* )   // this  red
//   {
//       ++m_num_red;
//   }
//    /*virtual*/void visit(Blu*)
//   {
//       ++m_num_blu;
//   }
//   void report_num()
//   {
//       cout << "Reds " << m_num_red << ", Blus " << m_num_blu << '\n';
//   }
//};

class CallVisitor: public Visitor
{
  public:
     /*virtual*/void visit(Red *r)
    {
        r->eye();
    }
     /*virtual*/void visit(Blu *b)
    {
        b->sky();
    }
};

// Subway : getCostVisitor   getCalVisitor

void Red::accept(Visitor *v) // countVisitor..
{
    
    // redirecting back to countVisitor.. By passing his obj address
    v->visit(this);    // proxy
    // countVisitor->visit(this)  // this( RED)
}

void Blu::accept(Visitor *v)
{
  v->visit(this);
}

int main(int argc, const char * argv[]) {
    
    Color *set[] =
      {
        new Red,  new Blu, new Blu, new Red, new Red, 0  // number of times it has to be called
      };
    
    // Visitor Unkonwn objects for red and Blue
    // tax visitor..
      CountVisitor count_operation;  // implementing public Visitor :
                                     // virtual void visit(Red*) = 0;  Blue  // ladies
      CallVisitor call_operation;
    
      for (int i = 0; set[i]; i++)
      {
        set[i]->accept(&count_operation);
          //   red->accept(&count_operation);
        set[i]->accept(&call_operation);
      }
      count_operation.report_num();
    }
/*
 Red::eye
 Blu::sky
 Blu::sky
 Red::eye
 Red::eye
 Reds 3, Blus 2
 Program ended with exit code: 0
 */
