

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
ll sp[M], vis[M], a[M];
multiset<ll> s[M];
map<ll,ll> m[M];
ll n,q;

ll pw(ll n, ll k){
    if(k == 0){
        return 1;
    }
    ll a = (pow(n,k/2));
    if(k%2){
        return ((((a*a)%mod)*(n%mod))%mod);
    }
    return ((a*a)%mod);
}

void seive(){
    for(ll i = 2; i<M; i+=2) sp[i] = 2;
    for(ll i = 3; i<M; i+=2){
        if(!vis[i]){
            sp[i] = i;
            for(ll j = i; j*i < M; j+=2){
                sp[j*i] = i, vis[j*i] = true;
            }
        }
    }
}

vl fact(ll num){
    vl p;
    while(num > 1){
        p.pb(sp[num]);
        num /= sp[num];
    }
    return p;
}


void solve(){
    re n; re q;
    fo(n) re a[i];
    fo(n){
        vl cur = fact(a[i]);
        // cout<<i<<"()"; for(auto x: cur) cout<<x<<" ";nl;
        for(auto p: cur) m[i][p]++;
        for(auto x: m[i]) s[x.ff].insert(x.sec);
    }
    ll ans = 1;
    fo(M){
        // if(s[i].size()) cout<<i<<"()"<<s[i].size()<<"\n";
        if(s[i].size() == n){
            ans *= pw(i,*s[i].begin());
            ans %= mod;
        }
    }
    while(q--){
        ll idx, x;
        re idx; re x;
        idx--;
        vl cur = fact(x);
        map<ll,ll> temp;
        for(auto p: cur){
            temp[p]++;
        }
        // cout<<q<<"()"; for(auto x: temp) cout<<x.ff<<" "; nl;
        for(auto p: temp){
            if(s[p.ff].size() == 0){
                m[idx][p.ff] += p.sec;
                s[p.ff].insert(p.sec);
                if(s[p.ff].size() == n) ans *= pw(p.ff,p.sec), ans %= mod;
                continue;
            }
            ll prev = *s[p.ff].begin();
            ll psz = s[p.ff].size();
            if(m[idx][p.ff]) s[p.ff].erase(s[p.ff].find(m[idx][p.ff]));
            m[idx][p.ff] += p.sec;
            s[p.ff].insert(m[idx][p.ff]);
            ll nxt = *s[p.ff].begin();
            if(psz == n && nxt > prev) ans *= pw(p.ff,nxt-prev);
            else if(psz != n && s[p.ff].size() == n) ans *= pw(p.ff,nxt);
            ans %= mod;
        }
        pr(ans);
    }
}

int32_t main(){
    KOBE;
    seive();
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
