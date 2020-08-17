

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

int matrixChainMultiplication(int p[], int n){
    int dp[n+1][n+1];
    for(int i = 1; i<n; i++){
        dp[i][i] = 0;
    }
    for(int l = 2; l<n; l++){
        for(int i = 1; i<n-l+1; i++){
            int j = i + l -1;
            dp[i][j] = INT_MAX;
            for(int k = i; k<=j-1; k++){
                int count = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                if(count<dp[i][j]){
                    dp[i][j] = count;
                }
            }
        }
    }

    return dp[1][n-1];
}

int main(){
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    cout<<matrixChainMultiplication(arr,n)<<endl;
}