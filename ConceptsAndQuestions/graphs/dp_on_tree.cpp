

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

const int N = 100;
vector<int> gr[N];
int dp[N];

void dfs(int cur, int par){
    dp[cur] = cur;
    for(auto x: gr[cur]){
        if(x!=par){
            dfs(x,cur);
            dp[cur] = min(dp[cur],dp[x]);
        }
    }
}

int main(){
    int n,x,y;
    cin>>n;
    fo(n-1){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    //root is 1
    dfs(1,0);
    fo(n){
        cout<<i+1<<" "<<dp[i+1]<<endl;
    }
}

/*
    10
    1 2
    1 4
    2 8
    8 6
    8 10
    6 9
    4 3
    4 5
    5 7
*/