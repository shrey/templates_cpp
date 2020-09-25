

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

using namespace std;
typedef long long ll;
typedef long double ld;

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
#define forn(x,n) for(ll x = 0; x<n; x++)
#define lmax LLONG_MAX


ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }

}

const ll M = 2e5+1;
string sarr[M];
string srev[M];
ll n;
ll c[M];
ll dp[M][2] = {0};

bool isGreater(string s1, string s2){
    if(lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end())){
        return false;
    }
    return true;
}


ll solve(){
    dp[0][0] = 0;
    dp[0][1] = c[0];
    for(ll i = 1; i<n; i++){
        dp[i][0] = lmax;
        dp[i][1] = lmax;
        if(isGreater(sarr[i],sarr[i-1]) && dp[i-1][0]!=lmax){
            dp[i][0] = dp[i-1][0];
        }
        if(isGreater(sarr[i],srev[i-1]) && dp[i-1][1]!=lmax){
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        }
        if(isGreater(srev[i],sarr[i-1]) && dp[i-1][0]!=lmax){
            dp[i][1] = dp[i-1][0] + c[i];
        }
        if(isGreater(srev[i],srev[i-1]) && dp[i-1][1]!=lmax){
            dp[i][1] = min(dp[i-1][1]+c[i],dp[i][1]);
        }
    }
    // forn(i,n){
    //     forn(j,2){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }
    if(dp[n-1][0] == lmax && dp[n-1][1] == lmax) return -1;
    return min(dp[n-1][0],dp[n-1][1]);
}

int main(){
    KOBE;
    cin>>n;
    fo(n) cin>>c[i];
    fo(n){
        cin>>sarr[i];
        srev[i] = sarr[i];
        reverse(srev[i].begin(),srev[i].end());
    }
    cout<<solve()<<"\n";


}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
