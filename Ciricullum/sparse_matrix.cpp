#include<iostream>

using namespace std;

#define SIZE 20

struct Sparse{
    int nrows;
    int ncols;
    int nz;
    int row[SIZE];
    int col[SIZE];
    int value[SIZE];
};

Sparse addMatrix(Sparse A, Sparse B){
    Sparse C;
    int i=0,j=0,k=0;
    C.nrows=A.nrows;
    C.ncols=A.ncols;
    while(i<A.nz && j<B.nz){
        if(A.row[i]==B.row[j] && A.col[i]==B.col[j]){
            if(A.value[i]+B.value[j]!=0){
                C.row[k]=A.row[i];
                C.col[k]=A.col[i];
                C.value[k]=A.value[i]+B.value[j];
            }
            i++;
            j++;
            k++;
        }
        else if(A.row[i]<B.row[j] || (A.row[i]==B.row[j] && A.col[i]<B.col[j])){
            C.row[k]=A.row[i];
            C.col[k]=A.col[i];
            C.value[k]=A.value[i];
            i++;
            k++;
        }
        else{
            C.row[k]=B.row[j];
            C.col[k]=B.col[j];
            C.value[k]=B.value[j];
            j++;
            k++;
        }

    }
    while(i<A.nz){
        C.row[k]=A.row[i];
        C.col[k]=A.col[i];
        C.value[k]=A.value[i];
        i++;
        k++;
    }
    while(j<B.nz){
        C.row[k]=B.row[j];
        C.col[k]=B.col[j];
        C.value[k]=B.value[j];
        j++;
        k++;
    }
    C.nrows=A.nrows;
    C.ncols=A.ncols;
    C.nz=k;
    return C;
}

void convert(Sparse &s, int mat[][6], int m, int n){
    int k = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j]!=0){
                s.row[k] = i;
                s.col[k] = j;
                s.value[k] = mat[i][j];
                k++;
            }
        }
    }
    s.nz = k;
    s.ncols = n;
    s.nrows = m;
}

void printSparse(Sparse s){
    for(int i = 0; i<s.nz; i++){
        cout<<s.row[i]<<" "<<s.col[i]<<" "<<s.value[i]<<endl;
    }
}

int main(){
    int mat[][6] = {
        {0,0,0,5,0,0},
        {0,0,7,0,8,0},
        {0,0,6,0,0,0},
        {0,8,6,0,0,9}
        };
    int mat2[][6] = {
        {0,0,0,5,6,0},
        {0,0,7,0,8,0},
        {0,0,6,0,0,0},
        {0,8,6,0,0,9}
        };
    int m = 4, n = 6;
    Sparse s;
    Sparse t;
    convert(s,mat,m,n);
    convert(t,mat2,m,n);
    Sparse d = addMatrix(s,t);
    printSparse(d);
    // printSparse(s);

}