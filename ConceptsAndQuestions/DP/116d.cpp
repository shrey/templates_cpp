

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
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
ll mod = 1e8;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }

}

ll n1,n2,k1,k2;

const ll M = 101, N = 11;

ll dp[101][101][11][11] = {0};


int main(){
    KOBE;
    cin>>n1>>n2>>k1>>k2;
    for(int i = 0; i<=n1; i++){
        for(int j = 0; j<=n2; j++){
            for(int kf = 0; kf<=k1; kf++){
                for(int kh = 0; kh<=k2; kh++){
                    ll ans = 0;
                    if(i == 0 && j == 0){
                        ans = 1;
                    }else{
                        if(i>0 && kf>0){
                            ans = (ans+dp[i-1][j][kf-1][k2])%mod;
                        }
                        if(j>0 && kh>0){
                            ans = (ans+dp[i][j-1][k1][kh-1])%mod;
                        }
                    }
                    dp[i][j][kf][kh] = ans;
                }
            }
        }
    }
    cout<<dp[n1][n2][k1][k2]<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
