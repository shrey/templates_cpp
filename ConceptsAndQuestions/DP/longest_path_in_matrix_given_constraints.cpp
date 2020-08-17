//https://www.geeksforgeeks.org/find-the-longest-path-in-a-matrix-with-given-constraints/



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
#include<math.h>


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

int compute(int mat[][3], int dp[][100], int i, int j, int n){
    if(i<0 || j<0 || i>=n || j>=n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int val = mat[i][j];
    int x = INT_MIN,y = INT_MIN, w = INT_MIN, z = INT_MIN;

    if(i<n-1 && (mat[i+1][j]-val) == 1){
        x =(compute(mat,dp,i+1,j,n)+1);
    }
    if(i>=1 && (mat[i-1][j]-val) == 1){
        y =(compute(mat,dp,i-1,j,n)+1);
    }
    if(j<n-1 && (mat[i][j+1]-val) == 1){
        w =(compute(mat,dp,i,j+1,n)+1);
    }
    if(j>=1 && (mat[i][j-1]-val) == 1){
        z =(compute(mat,dp,i,j-1,n)+1);
    }
    // if(i == 1 && j == 2){
    //     cout<<mat[i][j]<<endl;
    //     cout<<mat[i-1][j]<<endl;
    //     cout<<x<<' '<<y<<' '<<w<<" "<<z<<endl;
    // }
    dp[i][j] = max(x,max(y,max(w,max(z,1))));
    return dp[i][j];
}

int main(){
    int mat[][3] = {{1, 2, 9},
                   {5, 3, 8},
                   {4, 6, 7}};
    int n = 3;
    int dp[100][100];
    memset(dp,-1,sizeof dp);
    int result = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(dp[i][j] == -1){
                compute(mat,dp,i,j,n);
            }
            result = max(result,dp[i][j]);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    cout<<result<<endl;
}