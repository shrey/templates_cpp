

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

ll n,m;
const ll mx = 1e7+1;
const ll M = 1e5+100;
ll a[M],b[M];
ll v1[mx] = {0};
ll v2[mx] = {0};
set<ll> f;

bool prime[mx];
vl primes;
void seive(){
    fo(mx) prime[i] = true;
    prime[0] = false, prime[1] = false;
    for(int p = 2; p*p<mx; p++){
        if(prime[p] == true){
            for(int i = p*p; i<mx; i+=p){
                prime[i] = false;
            }
        }
    }
    fo(mx) if(prime[i]) primes.pb(i);
}



void comp(ll num, ll flag){
    for(ll i = 2; i*i <= num; i++){
        if(num % i == 0){
            ll cnt = 0;
            while(num && num % i == 0) num/=i, cnt++;
            if(flag) v1[i] += cnt;
            else v2[i] += cnt;
        }
    }
    if(num > 1){
        if(flag) v1[num]++;
        else v2[num]++;
    }
}

ll pow(ll n, ll k){
    if(k == 0){
        return 1;
    }
    ll a = (pow(n,k/2));
    if(k%2){
        return (a*a*n);
    }
    return (a*a);
}


ll comp2(ll num, ll flag){
    ll ans = 1;
    vp cur;
    for(ll i = 2; i*i <= num; i++){
        if(num % i == 0){
            ll cnt = 0;
            while(num && num % i == 0) num/=i, cnt++;
            cur.pb(mp(i,cnt));
        }
    }
    if(num > 1) cur.pb(mp(num,1));
    for(auto p: cur){
        if(flag){
            if(!v1[p.ff]) continue;
            if(v1[p.ff] >= p.sec){
                ans *= pow(p.ff,p.sec);
                v1[p.ff] -= p.sec;
            }else{
                ans *= pow(p.ff,v1[p.ff]);
                v1[p.ff] = 0;
            }
        }else{
            if(!v2[p.ff]) continue;
            if(v2[p.ff] >= p.sec){
                ans *= pow(p.ff,p.sec);
                v2[p.ff] -= p.sec;
            }else{
                ans *= pow(p.ff,v2[p.ff]);
                v2[p.ff] = 0;
            }
        }
    }
    return ans;
}

void solve(){
    re n; re m;
    fo(n) re a[i]; fo(m) re b[i];
    fo(n){
        comp(a[i],1);
    }
    fo(m){
        comp(b[i],0);
    }
    // for(auto x: f) cout<<v2[x]<<" "; nl;
    for(ll i = 0; i<mx; i++) {
        ll a1 = v1[i], b1 = v2[i];
        // cout<<it<<"()"<<a1<<"()"<<b1<<"\n";
        v1[i] -= min(a1,b1);
        v2[i] -= min(a1,b1);
    }
    // cout<<v1[5]<<"()"<<v2[5]<<"\n";
    vl aa(n); vl bb(m);
    fo(n){
        aa[i] = comp2(a[i],1);
    }
    fo(m){
        bb[i] = comp2(b[i],0);
    }
    cout<<n<<" "<<m<<"\n";
    for(auto x: aa) cout<<x<<" "; nl;
    for(auto x: bb) cout<<x<<" "; nl;
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
