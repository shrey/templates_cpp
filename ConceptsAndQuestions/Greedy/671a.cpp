

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
#define pdd pair<ld,ld>
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

pair<ld,ld> a,b,t;
const ll M = 1e5+100;
ll n;
vector<pair<ld,ld> > pos;

ld d(pdd &a1, pdd &b1){
    ld k = (a1.ff-b1.ff)*(a1.ff-b1.ff) + (a1.sec-b1.sec)*(a1.sec-b1.sec);
    return sqrt(k);
}

void solve(){
    re a.ff; re a.sec;
    re b.ff; re b.sec;
    re t.ff; re t.sec;
    re n;
    pos.resize(n);
    fo(n){
        re pos[i].ff; re pos[i].sec;
    }
    ld dist = 0.0;
    fo(n){
        dist += 2*d(pos[i],t);
    }
    vector<pair<ld,ll> > f1;
    vector<pair<ld,ll> > f2;
    umap<ll,ld> op;
    umap<ll,ld> op2;
    fo(n){
        ld cur = d(pos[i],a) - d(pos[i],t);
        op[i] = cur;
        f1.pb(mp(cur,i));
        cur = d(pos[i],b) - d(pos[i],t);
        op2[i] = cur;
        f2.pb(mp(cur,i));
    }
    sort(f1.begin(),f1.end());
    sort(f2.begin(),f2.end());

    // cout<<dist<<"()()\n";
    ld ans = 1e15;
    fo(n){
        ld cur = dist + op[i];
        ans = min(ans,cur);
        if(f2[0].sec == i){
            if(n>1){
                cur += f2[1].ff;
                ans = min(ans,cur);
            }
        }else{
            cur += f2[0].ff;
            ans = min(ans,cur);
        }
        cur = dist + op2[i];
        ans = min(ans,cur);
        if(f1[0].sec == i){
            if(n>1){
                cur += f1[1].ff;
                ans = min(ans,cur);
            }
        }else{
            cur += f1[0].ff;
            ans = min(ans,cur);
        }
    }
    prDouble(ans); nl;
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