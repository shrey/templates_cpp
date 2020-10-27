#include<iostream>
#include <string.h>

using namespace std;

class Student {
    protected: int rn;
    char * name;

    public :
    void get(int r, const char * n) {
        rn = r;
        name = new char[strlen(n) + 1]; strcpy(name, n);
    }
    void showrn() {
        cout<<"\nRoll No. : "<<rn<<"\n";
        cout<<"\nName : "<<name<<"\n";
    }
};
class Test : public Student {
    protected:
    int s1, s2;
    public:
    void getM(int m1, int m2)
    {
        s1 = m1;
        s2 = m2;
    }
    void showM() {
        cout<<"\nMarks in subject 1 : "<<s1<<"\n";
        cout<<"\nMarks in subject 2 : "<<s2<<"\n"; }
    };
class Result : public Test {
    protected: int total;
    public :
    void display()
    {
        total = s1 + s2;
        showrn();
        showM();
        cout<<"\nTotal marks : "<<total<<"\n";
    }
};
int main () {
    Result res1; res1.get(164, "Shrey"); res1.getM(29 , 30); res1.display();
    return 0;
}
