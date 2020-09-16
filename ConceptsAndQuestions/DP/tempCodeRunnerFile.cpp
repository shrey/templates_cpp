

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
const ll M = 2e5 +1;
ll dp[M];

int main(){
    KOBE;
    ll t,k;
    dp[0] = 1;
    cin>>t>>k;
    for(int i = 1; i<k; i++){
        dp[i] = 1;
    }
    for(int i = k; i<M-1; i++){
        dp[i] = dp[i-1] + dp[i-k];
    }
    // for(int i = 1; i<=10; i++){
    //     cout<<dp[i]<<" ";
    // }cout<<"\n";
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll ans = 0;
        for(ll i = a; i<=b; i++){
            ans+=dp[i];
        }
        cout<<ans<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
