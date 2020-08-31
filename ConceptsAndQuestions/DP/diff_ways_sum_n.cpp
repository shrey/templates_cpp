//https://www.geeksforgeeks.org/different-ways-sum-n-using-numbers-greater-equal-m/


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
#define mp make_pair

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int main(){
    int n,m;
    cin>>n>>m;
    int dp[n+2][n+2];
    // dp[i][j] sum i using nos greater than equal to j
    memset(dp,0,sizeof dp);
    dp[0][n+1] = 1;
    for(int k = n; k>=m; k--){
        for(int i = 0; i<=n; i++){
            dp[i][k] = dp[i][k+1];
            if((i-k)>=0){
                dp[i][k] += dp[i-k][k];
            }
        }
    }
    cout<<dp[n][m]<<endl;
}