// https://www.geeksforgeeks.org/maximum-path-sum-starting-cell-0-th-row-ending-cell-n-1-th-row/



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
int main(){
    int mat[4][4] = {   { 4, 2 , 3 , 4 },
                        { 2 , 9 , 1 , 10},
                        { 15, 1 , 3 , 0 },
                        { 16 ,92, 41, 44 }
    };
    int dp[4][4];
    int n = 4;
    for(int i = 0; i<n;i++){
        dp[0][i] = mat[0][i];
    }
    int result = 0;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<n; j++){
            if(j == 0){
                dp[i][j] = max(dp[i-1][j+1],dp[i-1][j]);
            }
            else if(j == n-1){
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = max(dp[i-1][j+1],max(dp[i-1][j],dp[i-1][j-1]));
            }
            dp[i][j]+=mat[i][j];
            result = max(result,dp[i][j]);
        }
    }
    cout<<result<<endl;

}