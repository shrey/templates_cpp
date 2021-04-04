

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
#define LG 20

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

ll n,m,k;

void solve(){
    re n; re m; re k;
    ll tot = 0;
    ll cur = 0;
    if(k > 4*n*m - 2*n - 2*m){
        NO;
        return;
    }
    vector<pair<ll,string> > res;
    if(m == 1){
        if(cur + (n-1) <= k){
            res.pb(mp(n-1,"D"));
            cur += n-1;
        }
        if(cur < k){
            res.pb(mp(k-cur,"U"));
        }
        cur = k;
    }
    ll i = 0;
    while(cur < k && cur + 4*(m-1) <= k && i < n-1){
        // pr("ehre");
        i++;
        string s1 = "RDU";
        res.pb(mp(m-1,s1));
        res.pb(mp(m-1,"L"));
        cur += 4*(m-1);
        if(cur == k) break;
        cur++;
        res.pb(mp(1,"D"));
    }
    if(i == n-1 && cur < k){
        if(cur + (m-1) <= k){
            res.pb(mp(m-1,"R"));
            cur += m-1;
        }else{
            res.pb(mp(k-cur,"R"));
            cur = k;
        }
        if(cur + (m-1) <= k){
            res.pb(mp(m-1,"L"));
            cur += m-1;
        }else if(cur < k){
            res.pb(mp(k-cur,"L"));
            cur = k;
        }
        if(cur < k){
            res.pb(mp(k-cur,"U"));
            cur = k;
        }
    }
    else if(i != n-1 && cur < k){
        if((3*(m-1)) + cur <= k){
            cur += 3*(m-1);
            res.pb(mp(m-1,"RDU"));
        }else{
            ll cnt = (k-cur)/3;
            if(cnt) res.pb(mp(cnt,"RDU"));
            cur += 3*cnt;
            if(k-cur == 1){
                res.pb(mp(1,"R"));
            }else if(k-cur == 2){
                res.pb(mp(1,"RD"));
            }
            cur = k;
        }
        if(cur < k){
            res.pb(mp(k-cur,"L"));
            cur = k;
        }
    }
    YES;
    vector<pair<ll,string> > ans;
    for(auto x: res){
        if(x.ff != 0) ans.pb(x);
    }
    res = ans;
    pr(res.size());
    for(auto x: res){
        cout<<x.ff<<" "<<x.sec<<"\n";
    }
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    // re t;
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
