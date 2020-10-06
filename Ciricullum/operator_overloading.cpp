#include <iostream>
using namespace std;


class Complex{
    float real,imaginary;
    public:
        Complex(){
            real = 0;
            imaginary = 0;
        }
        void input(){
            cout<<"Enter real part: ";cin>>real;
            cout<<"Enter Imaginary part: ";cin>>imaginary;
        }
        void display(){
            cout<<real<<" + "<<imaginary<<"i\n";
        }
        Complex operator+(Complex &c1){
            Complex res;
            res.real = real + c1.real;
            res.imaginary = imaginary + c1.imaginary;
            return res;
        }
        Complex operator-(Complex &c1){
            Complex res;
            res.real = real - c1.real;
            res.imaginary = imaginary - c1.imaginary;
            return res;
        }
        Complex operator*(Complex &c1){
            Complex res;
            res.real = real*c1.real - imaginary*c1.imaginary;
            res.imaginary = real*c1.imaginary + imaginary*c1.real;
            return res;
        }
        Complex operator/(Complex &c1){
            Complex res;
            float mod = (c1.real*c1.real) + (c1.imaginary*c1.imaginary);
            cout<<mod<<"\n";
            res.real = ((real*c1.real + imaginary*c1.imaginary)/mod);
            res.imaginary = ((c1.real*imaginary-c1.imaginary*real)/mod);
            return res;
        }
};

int main(){
    Complex c1,c2,c3;
    cout<<"First Complex Number: \n";
    c1.input();
    cout<<"Second Complex Number: \n";
    c2.input();
    cout<<"Sum: \n";
    c3 = c1+c2;
    c3.display();
    cout<<"Substraction: \n";
    c3 = c1-c2;
    c3.display();
    cout<<"Multiplication: \n";
    c3 = c1*c2;
    c3.display();
    cout<<"Division: \n";
    c3 = c1/c2;
    c3.display();
}