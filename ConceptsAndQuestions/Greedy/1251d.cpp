

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

const ll M = 2e5+100;
vp a;
ll l,r,n,s;

ll c1(ll num){
    ll cnt1 = 0, cnt2 = 0;
    for(auto x: a){
        if(x.ff > num) cnt1++;
        if(x.sec < num) cnt2++;
    }
    ll mx = (n-1)/2;
    if(cnt1 > mx) return 1;
    if(cnt2 > mx) return -1;
    return 0;
}

bool check(ll num){
    ll s1 = 0, s2 = 0, c1 = 0, c2 = 0;
    // multiset< pll > m;
    // fo(a.size()) m.insert(mp(a[i].ff,a[i].sec));
    // for(auto x: m){
    //     if(x.ff > num){
    //         s1 += x.ff;
    //         c1++; m.erase(m.find(x));
    //     }
    //     else if(x.sec < num){
    //         s2 += x.ff;
    //         c2++; m.erase(m.find(x));
    //     }
    //     if(m.empty()) break;
    // }
    multiset< pll > m;
    for(auto x: a){
        if(x.ff > num){
            c1++;
            s1 += x.ff;
        }else if(x.sec < num){
            c2++;
            s2 += x.ff;
        }else{
            m.insert(x);
        }
    }
    ll ans = s1 + s2 + ((n-1)/2 - c1) * num + num;
    ll rem = (n-1)/2 - c2;
    while(rem--){
        auto p = *m.begin();
        m.erase(m.begin());
        ans += p.ff;
    }
    return (ans <= s);
}

void solve(){
    re n; re s;
    fo(n){
        re l; re r;
        a.pb(mp(l,r));
    }
    ll s = 0, e = 1e9;
    ll ans = 0;
    while(s <= e){
        ll mid = (s+e)>>1;
        // if ranges starting from <= mid are less than (n-1)/2 + 1 then s = mid+1
        // if ranges ending greater than equal to mid are less than (n-1)/2 then e = mid-1
        // cout<<s<<"()"<<e<<"\n";
        ll op = c1(mid);
        if(op!=0){
            if(op == 1){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            continue;
        }
        if(check(mid)){
            ans = max(ans,mid);
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    pr(ans);
    a.clear();
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
