

//Shrey Dubey

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
#include<climits>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define sec second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll n,m;
const ll M = 31;
ll mat[M][M];

ll solve(){
    ll dist = n+m-2;
    map<ll,vector<pair<ll,ll> > > sdist;
    map<ll,vector<pair<ll,ll> > > edist;
    ll dp[M][M] = {0};
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            sdist[i+j].pb(mp(i,j));
            edist[dist-(i+j)].pb(mp(i,j));
        }
    }
    ll ans = 0;
    if(mat[0][0]!=mat[n-1][m-1]) ans++;
    for(ll i = 1; i<=dist/2; i++){
        ll a1 = 0,b1 = 0,a2 = 0,b2 = 0;
        if(i == dist-i) continue;
        for(auto x: sdist[i]){
            if(mat[x.first][x.second]){
                b1++;
            }else{
                a1++;
            }
        }
        for(auto x: edist[i]){
            if(mat[x.first][x.second]){
                b2++;
            }else{
                a2++;
            }
        }
        // cout<<i<<"()"<<a1<<" "<<b1<<" "<<a2<<" "<<b2<<"\n";
        ans+=(min(a1+a2,b1+b2));
        // cout<<i<<"()"<<min(a1+a2,b1+b2)<<"\n";
    }
    return ans;
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        forn(i,n){
            forn(j,m){
                cin>>mat[i][j];
            }
        }
        cout<<solve()<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
