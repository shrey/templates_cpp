

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
#include<bitset>
#include<cstring>
#include<numeric>
#include<array>


using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)
#define all(x) x.begin(),x.end()

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

ll mod = 1e9 + 7;

ll cl(ld a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll flr(ld a){
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

//code starts here

void solve(){
    ll n,m; re n; re m;
    ll mat[n+1][n+1];
    string s;
    fo(n){
        re s;
        for(ll j = 0; j<s.length(); j++){
            if(j != i) mat[i+1][j+1] = s[j] - 'a';
        }
    }
    if(m%2 == 0 && n == 2 && mat[1][2] != mat[2][1]){
        NO;
        return;
    }
    if(m%2){
        YES;
        ll flag = 0;
        fo(m+1){
            cout<<flag+1<<" ";
            flag ^= 1;
        }nl;
        return;
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n; j++){
            if(j!=i){
                if(mat[i][j] == mat[j][i]){
                    YES;
                    forn(k,m/2) cout<<i<<" "<<j<<" "; cout<<i<<"\n";
                    return;
                }
            }
        }
    }
    for(ll i = 1; i<=n; i++){
        vl a; vl b;
        for(ll j = 1; j<=n; j++){
            if(j != i){
                if(mat[i][j] == 0) a.pb(j);
                else b.pb(j);
            }
        }
        // if(i == n-1) cout<<b.size()<<"()"<<a.size()<<"\n";
        if(a.size() && b.size()){
            ll c1 = a[0], c2 = b[0];
            YES;
            if(m % 4){
                ll flag = 0;
                forn(k,(m/2+1)/2){
                    cout<<c1<<" "<<i<<" ";
                }
                forn(k,(m/2-1)/2){
                    cout<<c2<<" "<<i<<" ";
                }
                cout<<c2<<"\n";
                return;
            }else{
                ll flag = 1;
                forn(k,m/4){
                    cout<<i<<" "<<c1<<" ";
                }
                cout<<i<<" ";
                flag = 0;
                forn(k,m/4){
                    cout<<c2<<" "<<i<<" ";
                }
                nl;
                return;
            }
        }
    }
    NO;
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
    while(t--) solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
