#include <iostream>
using namespace std;

class first {
  public:
   virtual void print() {
       cout << "first Class" << endl;
   }
};

class second : public first {
  public:
   void print() {
       cout << " second Class" << endl;
   }
};

int main() {
   second derived1;
   first* base1 = &derived1;
   base1->print();
   return 0;
}
