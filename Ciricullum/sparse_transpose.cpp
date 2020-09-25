
#include <iostream>
#define size 20
struct sparse{
    int nrows;
    int ncols;
    int nz;
    int row[size];
    int col[size];
    int value[size];
};
typedef struct sparse mySparse;
mySparse addMatrix(mySparse A,mySparse B){
    mySparse C;
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
mySparse transposeMatrix(mySparse A){
    mySparse C;
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
mySparse multiplyMatrix(mySparse A,mySparse D){
    mySparse B= transposeMatrix(D);
    mySparse C;
    C.nrows=A.nrows;
    C.ncols=B.nrows;
    int k=0;
    for(int i=0;i<C.ncols*C.nrows;i++){
        C.value[i]=0;
    }
    for(int i=0;i<A.nz;i++){
        for(int j=0;j<B.nz;j++){
            if(A.col[i]==B.col[j]){
                C.row[k]=A.row[i];
                C.col[k]=B.row[j];
                C.value[k]+=A.value[i]*B.value[j];

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
void readMatrix(mySparse* A){
    printf("Enter the number of rows:\n");
    scanf("%d",&A->nrows);
    printf("Enter the number of columns:\n");
    scanf("%d",&A->ncols);
    printf("Enter the number of values:\n");
    scanf("%d",&A->nz);
    printf("Enter values in the table:\n");
    printf("Row no.     column no.      value\n");
    for(int i=0;i<A->nz;i++){
        scanf("%d",&A->row[i]);
        scanf("%d",&A->col[i]);
        scanf("%d",&A->value[i]);
    }
}
void printMatrix(mySparse A){
    printf("Row no.     column no.      value\n");
    for(int i=0;i<A.nz;i++){
        printf("%d\t\t",A.row[i]);
        printf("%d\t\t",A.col[i]);
        printf("%d\n",A.value[i]);
    }
    return;
}
int main() {
    mySparse A,B,C,D,E;
    readMatrix(&A);
    readMatrix(&B);
    if(A.nrows!=B.nrows || A.ncols!=B.ncols){
        printf("No. of rows and columns should be same to add matrices.\n");
        goto label;
    }
    C= addMatrix(A,B);
    D=transposeMatrix(C);
    printf("Matrix A: \n");
    printMatrix(A);
    printf("Matrix B: \n");
    printMatrix(B);
    printf("Matrix C=A+B: \n");
    printMatrix(C);
    printf("Matrix D=Transpose(C): \n");
    printMatrix(D);
    label:
    if(A.ncols!=B.nrows){
        printf("Given matrices can not be multiplied.\n");
        return 0;
    }
    E=multiplyMatrix(A,B);
    printMatrix(E);
}