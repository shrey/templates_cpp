

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

int dp[1000][1000];

int compute(int n, int r,int p){
    if(n<r){
        return 0;
    }
    if(n == r || r == 0){
        return 1;
    }
    if(dp[n][r]!=-1){
        return dp[n][r];
    }

    dp[n][r] = ((compute(n-1,r,p)%p + compute(n-1,r-1,p)%p)%p);
    return dp[n][r];
}

int main(){
    int n,r,p;
    cin>>n>>r>>p;
    if(r>(n-r)){
        r = n-r;
    }
    memset(dp,-1,sizeof dp);
    cout<<compute(n,r,p)<<endl;
}