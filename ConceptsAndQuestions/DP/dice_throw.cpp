

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
    int n,m,x;
    cin>>m>>n>>x;
    int dp[n+1][x+1];
    memset(dp,0,sizeof dp);
    for(int i = 1; i<=m; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=x; j++){
            int k = 1;
            int sum = 0;
            for(int k = 1; k<=m; k++){
                if((j-k)>=1){
                    sum+=dp[i-1][(j-k)];
                }
            }
            dp[i][j] = sum;
        }
    }
    cout<<dp[n][x]<<endl;
}