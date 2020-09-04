#include <iostream>
using namespace std;

struct poly{
    int degree;
    int coeff[30];
};

void displayPoly(poly *x){
    for(int i = 0; i<=x->degree; i++){
        cout<<x->coeff[i]<<"x^"<<i<<" + ";
    }cout<<endl;
}

void addPolynomial(poly *a, poly *b){
    poly c;
    if(a->degree>b->degree){
        c.degree = a->degree;
    }
    else{
        c.degree = b->degree;
    }
    for(int i = 0; i<=c.degree; i++){
        c.coeff[i] = (a->coeff[i]+b->coeff[i]);
    }
    cout<<"Sum of Polynomial is:- "<<endl;
    displayPoly(&c);
}

void multiplyPolynomial(poly *a, poly *b){
    poly c;
    int maxdegree = a->degree+b->degree;
    for(int i = 0; i<=maxdegree; i++){
        c.coeff[i] = 0;
    }
    c.degree = maxdegree;
    for(int i = 0; i<=a->degree; i++){
        for(int j =0 ; j<=b->degree;j++){
            c.coeff[i+j] += a->coeff[i]*b->coeff[j];
        }
    }
    displayPoly(&c);
}
