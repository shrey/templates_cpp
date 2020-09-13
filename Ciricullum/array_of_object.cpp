#include <iostream>
using namespace std;

class Student{
    char fname[100],lname[100],id[100];
    int grade;
    char section;
    public:
        void inputData(){
            cout<<"First Name: ";cin>>fname;
            cout<<"Last Name: ";cin>>lname;
            cout<<"Enrollment Id: ";cin>>id;
            cout<<"Class: ";cin>>grade;
            cout<<"Section: ";cin>>section;
        }
        void outputData(){
            cout<<"First Name: "<<fname<<endl;
            cout<<"Last Name: "<<lname<<endl;
            cout<<"Enrollment Id: "<<id<<endl;
            cout<<"Class: "<<grade<<endl;
            cout<<"Section: "<<section<<endl;
        }
};

int main(){
    int n;
    cout<<"Enter the Number of students: ";cin>>n;
    Student S[n];
    for(int i = 0; i<n; i++){
        cout<<"Student "<<(i+1)<<endl;
        S[i].inputData();
    }

    cout<<"STUDENT DATA: "<<endl;
    for(int i = 0; i<n; i++){
        cout<<"Student "<<(i+1)<<endl;
        S[i].outputData();
    }
}