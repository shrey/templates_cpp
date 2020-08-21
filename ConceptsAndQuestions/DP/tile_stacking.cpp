

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
    int n,m,k;
    cin>>n>>m>>k;
    int dp[n+1][m+1], pre[n+1][m+1];
    memset(dp,0,sizeof dp);
    memset(pre,0,sizeof pre);
    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
        pre[i][0] = 1;
    }
    for(int i = 0; i<=m; i++){
        dp[0][i] = 1;
        pre[0][i] = 1;
    }
    for(int j = 1; j<=m; j++){
        for(int i = 1; i<=n; i++){
            dp[i][j] = pre[i][j-1];
            if(i>k){
                dp[i][j]-=pre[i-k-1][j-1];
            }
        }
        for(int i = 1; i<=n; i++){
            pre[i][j] = dp[i][j] + pre[i-1][j];
        }
    }
    cout<<dp[n][m]<<endl;

}

//pre has all the computations till ith height using jth max width so we don't have to add previous
//k values in order to compte the current dp[i][j] thereby improving time complexity