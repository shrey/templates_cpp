#include <iostream>
#include <string.h>
using namespace std;
class String
{
    char *s;
    int len;
    public:
    String()
    {
        s = NULL;
        len = 0;
    }
    String(const char *p)
    {
        len = strlen(p);
        s = new char[len + 1];
        strcpy(s, p);
    }
    void display()
    {
        cout << s <<"\n";
    }
    friend int operator <= (String & , String&);
    friend String operator+ (String &, String&);
};
String operator+ (String &c1, String &c2)
 {
    String ans;
    ans.len = strlen(c1.s) + + strlen(c2.s);
    ans.s = new char[ans.len + 1];
    strcpy(ans.s, strcat(c1.s, c2.s));
    return ans;
}
int operator<= (String &c1, String &c2)
{
    int n = strlen(c1.s);
    int m = strlen(c2.s);
    if(n <= m) {
        return 1;
    }
    return 0;
}
int main(){
    String s1 = "Shrey";
    String s2("Dubey");
    String s3("Amsterdam");
    cout<<"String number 1 is ";
    s1.display();
    cout<<"\nString number 2 is ";
    s2.display();
    cout<<"\nString number 3 is ";
    s3.display();
    String s4 = (s2 <= s3) ? s3 : s2;
    cout<<"\nConcatenation of s1 and longer of s2,s3 is : ";
    (s1 + s4).display();
    cout<<"\n";
    return 0;
}
