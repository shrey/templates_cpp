//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

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
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int maxwt = 50;
    int n = sizeof(val)/sizeof(int);
    int dp[n+1][maxwt+1];
    memset(dp,0,sizeof dp);
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=50; j++){
            dp[i][j] = dp[i-1][j];
            if(wt[i-1]<=j){
                dp[i][j] = max(dp[i][j],dp[i-1][j-wt[i-1]] + val[i-1]);
            }
        }
    }
    cout<<dp[n][maxwt]<<endl;

}