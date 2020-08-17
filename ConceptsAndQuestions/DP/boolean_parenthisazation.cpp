//https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>
#include<iomanip>
#include<queue>
#include<stack>
#include <math.h>



#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int main(){
    char s[] = "TTFT";
    char op[] = "|&^";
    int n = 4;
    // cout<<"hery"<<endl;
    int T[n+1][n+1], F[n+1][n+1];
    memset(T,0,sizeof T);
    memset(F,0,sizeof F);
    for(int i = 0; i<n; i++){
        T[i][i] = s[i] == 'T'? 1 : 0;
        F[i][i] = s[i] == 'F'? 1: 0;
    }
    for(int gap = 1; gap<n; gap++){
        for(int i = 0, j = gap; j<n; j++, i++){

            T[i][j] = F[i][j] = 0;
            for(int g = 0; g<gap; g++){
                int k = i+g;
                int toti = T[i][k] + F[i][k];
                int totk = T[k+1][j] + F[k+1][j];
                if(op[k] == '&'){
                    T[i][j] += T[i][k]*T[k+1][j];
                    F[i][j] += (toti * totk - T[i][k]*T[k+1][j]);
                }
                else if(op[k] == '|'){
                    T[i][j] += (toti * totk - F[i][k] * F[k+1][j]);
                    F[i][j] += F[i][k] * F[k+1][j];
                }
                else if(op[k] == '^'){
                    T[i][j] += T[i][k] * F[k+1][j] + F[i][k]* T[k+1][j];
                    F[i][j] += T[i][k] * T[k+1][j] + F[i][k] * F[k+1][j];
                }
            }
        }
    }
    fo(n){
        for(int j = 0; j<n; j++){
            cout<<T[i][j]<<" ";
        }cout<<endl;
    }
    cout<<T[0][n-1]<<endl;
}