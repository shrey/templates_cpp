

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
    return (ll) a;
}



//code starts here

ll n,tme;
vp op;
vl res;

ll check(ll num){
    res.clear();
    multiset<pair<pair<ll,ll> ,ll> > m;
    for(ll i = 0; i<op.size(); i++){
        auto p = op[i];
        if(p.ff >= num){
            m.insert(mp(mp(p.sec,p.ff),i));
        }
    }
    if(m.size() < num) return -1;
    ll ans = 0;
    auto cur = *m.begin();
    ll t = 0;
    while(res.size() < num){
        ans++;
        t += cur.ff.ff;
        res.pb(cur.sec+1);
        m.erase(*m.begin());
        cur = *m.begin();
    }
    if(t > tme){
        // cout<<num<<"()\n";
        // cout<<t<<"\n";
        res.clear();
        return -1;
    }
    return ans;
}

void solve(){
    re n; re tme;
    ll s = 0, e = n;
    op.resize(n);
    fo(n){
        re op[i].ff; re op[i].sec;
    }
    ll ans = 0;
    ll score = 0;
    vl fin;
    while(s <= e){
        ll mid = (s+e)>>1;
        // cout<<s<<"()"<<e<<"\n";
        if(check(mid) != -1){
            s = mid+1;
            fin = res;
        }
        else{
            e = mid - 1;
        }
    }
    cout<<fin.size()<<"\n";
    cout<<fin.size()<<"\n";
    for(auto x: fin) cout<<x<<" "; nl;
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
