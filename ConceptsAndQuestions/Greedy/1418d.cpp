

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
#define vs vector<string>
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

ll n,q;
const ll M = 1e5+100;
ll a[M];

void solve(){
    re n; re q;
    fo(n) re a[i];
    sort(a,a+n);
    ll num1, num2, res = 1e15,lst,beg;
    lst = a[n-1];
    beg = a[0];
    multiset<ll> m;
    fo(n) m.insert(a[i]);
    //n == 1 case handle
    multiset<ll, greater<ll> > diff;
    multiset<ll> tot;
    for(ll i = 0; i<n-1; i++){
        diff.insert(a[i+1]-a[i]);
    }
    res = lst - beg;
    if(!diff.empty()) res -= *diff.begin();
    pr(res);
    while(q--){
        ll t; re t;
        ll x; re x;
        // cout<<t<<"()"<<x<<"\n";
        if(t == 1){
            if(x < beg){
                if(beg != -1) diff.insert(beg-x);
                else beg = x, lst = x;
                m.insert(x);
                beg = x;
                res = lst-beg;
                if(!diff.empty()) res -= *diff.begin();
            }else if(x >lst){
                if(lst != -1) diff.insert(x-lst);
                else beg = x,lst = x;
                m.insert(x);
                lst = x;
                res = lst-beg;
                if(!diff.empty()) res -= *diff.begin();
                // if(x == 1000000000) cout<<*diff.begin()<<"()()\n";
            }else{
                auto it = m.upper_bound(x);
                auto it2 = it;
                --it2;
                // if(x == 500000000) cout<<*it<<" () () "<<*it2<<"\n";
                diff.erase(diff.find((*it-*it2)));
                diff.insert(x-*it2);
                diff.insert(*it-x);
                m.insert(x);
                res = lst-beg;
                if(!diff.empty()) res -= *diff.begin();
            }
            pr(res);
        }else{
            if(x == beg){
                m.erase(m.find(x));
                if(m.empty()){
                    pr(0);
                    beg = -1, lst = -1;
                    continue;
                }
                beg = *m.begin();
                diff.erase(diff.find(beg-x));
                res = lst-beg;
                if(!diff.empty()) res -= *diff.begin();
            }else if(x == lst){
                m.erase(m.find(x));
                if(m.empty()){
                    pr(0);
                    continue;
                }
                auto it = m.end();
                --it;
                lst = *it;
                diff.erase(diff.find(x-lst));
                res = lst-beg;
                if(!diff.empty()) res -= *diff.begin();
            }else{
                auto it = m.upper_bound(x);
                auto it2 = m.lower_bound(x);
                --it2;
                diff.insert(*it - *it2);
                diff.erase(diff.find(x-*it2));
                diff.erase(diff.find(*it-x));
                m.erase(m.find(x));
                res = lst-beg;
                if(!diff.empty()) res -= *diff.begin();
            }
            pr(res);
        }
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
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
