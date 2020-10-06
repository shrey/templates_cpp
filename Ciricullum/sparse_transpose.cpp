#include <iostream>
#define size 20

using namespace std;
struct sparse{
    int nrows;
    int ncols;
    int nz;
    int row[size];
    int col[size];
    int value[size];
};

sparse addMatrix(sparse A,sparse B){
    sparse C;
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
sparse transposeMatrix(sparse A){
    sparse C;
    int mat[A.ncols];
    for(int i=0;i<A.ncols;i++){
        mat[i]=0;
    }
    C.nrows=A.ncols;
    C.ncols=A.nrows;
    C.nz=A.nz;
    for(int i=0;i<A.nz;i++){
        mat[A.col[i]]++;
    }
    for(int i=1;mat[i]!=0;i++){
        mat[i]+=mat[i-1];
    }
    for(int i=A.nz-1;i>=0;i--){
        C.row[mat[A.col[i]]-1]=A.col[i];
        C.col[mat[A.col[i]]-1]=A.row[i];
        C.value[mat[A.col[i]]-1]=A.value[i];
        mat[A.col[i]]--;
    }
    return C;

}
sparse multiplyMatrix(sparse A,sparse B){
    sparse D= transposeMatrix(B);
    sparse C;
    C.nrows=A.nrows;
    C.ncols=D.nrows;
    int k=0;
    for(int i=0;i<C.ncols*C.nrows;i++){
        C.value[i]=0;
    }
    for(int i=0;i<A.nz;i++){
        for(int j=0;j<D.nz;j++){
            int flag=0;
            if(A.col[i]==D.col[j]){
                int m=0;
                while(m<k){
                    if(C.row[m]==A.row[i] && C.col[m]==D.row[j]){
                        C.value[m]=C.value[m]+(A.value[i]*D.value[j]);
                        flag=1;
                        break;
                    }
                    m++;
                }
                if(flag==1) continue;
                C.row[k]=A.row[i];
                C.col[k]=D.row[j];
                C.value[k]=C.value[k]+(A.value[i]*D.value[j]);
                int t=k;
                while(t>0 && C.row[t]==C.row[t-1] && C.col[t]<C.col[t-1] ){
                    int c=C.row[t];
                    C.row[t]=C.row[t-1];
                    C.row[t-1]=c;
                    c=C.col[t];
                    C.col[t]=C.col[t-1];
                    C.col[t-1]=c;
                    c=C.value[t];
                    C.value[t]=C.value[t-1];
                    C.value[t-1]=c;
                    t--;
                }
                k++;
            }
        }
    }
    C.nz=k;
    return C;
}
void readMatrix(sparse* A){
    cout<<"Enter the number of rows:\n";
    cin>>A->nrows;
    cout<<"Enter the number of columns:\n";
    cin>>A->ncols;
    cout<<"Enter the number of non-zero values:\n";
    cin>>A->nz;
    cout<<"Enter values in the table:\n";
    cout<<"Row no.     column no.      value\n";
    for(int i=0;i<A->nz;i++){
        cin>>A->row[i];
        cin>>A->col[i];
        cin>>A->value[i];
    }
}
void printMatrix(sparse A){
    cout<<"Row no.     column no.      value\n";
    for(int i=0;i<A.nz;i++){
        cout<<A.row[i];
        cout<<"\t\t"<<A.col[i];
        cout<<"\t\t"<<A.value[i]<<"\n";
    }
    return;
}

void printNormal(sparse a){
    cout<<"Original Matrix was: "<<"\n";
    int mat[size+1][size+1] = {0};
    for(int i = 0; i<a.nz; i++){
        mat[a.row[i]][a.col[i]] = a.value[i];
    }
    for(int i = 0; i<a.nrows; i++){
        for(int j = 0; j<a.ncols; j++){
            cout<<mat[i][j]<<" ";
        }cout<<"\n";
    }
}

int main() {
    sparse A,B,C,D,E;
    readMatrix(&A);
    readMatrix(&B);
    printNormal(A);
    printNormal(B);
    if(A.nrows!=B.nrows || A.ncols!=B.ncols){
        cout<<"No. of rows and columns should be same to add matrices.\n";
        goto label;
    }
    C= addMatrix(A,B);
    D=transposeMatrix(C);
    cout<<"Matrix A: \n";
    printMatrix(A);
    cout<<"Matrix B: \n";
    printMatrix(B);
    cout<<"Matrix C=A+B: \n";
    printMatrix(C);
    cout<<"Transpose of C: \n";
    printMatrix(D);
    label:
    if(A.ncols!=B.nrows){
        cout<<"Given matrices can not be multiplied.\n";
        return 0;
    }
    E=multiplyMatrix(A,B);
    printMatrix(E);
}


/*
4 5 5
0 1 3
1 1 4
1 3 2
2 3 8
3 4 9
5 2 3
2 1 6
3 0 3
4 1 7

*/