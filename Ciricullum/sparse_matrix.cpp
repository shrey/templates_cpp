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

Sparse addMatrix(Sparse a, Sparse b){
    Sparse C;
    int i,j,k;
    i = 0; j = 0; k = 0;
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
    int m = 4, n = 6;
    Sparse s;
    convert(s,mat,m,n);
    printSparse(s);

}