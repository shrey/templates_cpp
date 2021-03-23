

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

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};

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

const ll M = 510;

ll ans = 1e15;
ll n;
ll a[M*M];
ll c[M];
ll r[M];
ll b[M*M];
ll tot;

ll comp(ll bit){
    multiset<pair<ll,pll> > m;
    ll r[n], c[n];
    for(ll i = 0; i<n*n; i+=n){
        ll cnt = 0;
        for(ll j = i; j<i+n; j++){
            if((bit & (1<<j)) == 0) cnt++;
        }
        r[i/n] = cnt;
        if(cnt == 0) continue;
        // if(i/n == 0) cout<<cnt<<"(())\n";
        m.insert(mp(cnt,mp(1,i/n)));
    }
    for(ll i = 0; i<n; i++){
        ll cnt = 0;
        for(ll j = i; j<n*n; j+=n){
            if((bit & (1<<j)) == 0) cnt++;
        }
        c[i] = cnt;
        if(cnt == 0) continue;
        m.insert(mp(cnt,mp(2,i)));
    }
    if(m.empty()){
        return bit;
    }
    auto cur = *m.begin();
    // pr(cur.ff);
    while(!m.empty() && cur.ff == 1){
        m.erase(m.begin());
        if(m.empty()) break;
        ll pos;
        ll s = cur.sec.sec;
        // cout<<cur.sec.ff<<"()"<<cur.sec.sec<<"\n";
        if(cur.sec.ff == 1){
            s *= n;
            for(ll j = s; j<s+n; j++){
                if((bit & (1<<j)) == 0){
                    bit |= (1<<j);
                    r[s/n]--;
                    m.erase(m.find(mp(c[j%n],mp(2,j%n))));
                    c[j%n]--;
                    if(c[j%n]) m.insert(mp(c[j%n],mp(2,j%n)));
                    break;
                }
            }
        }else{
            for(ll j = s; j<n*n; j+=n){
                if((bit & (1<<j)) == 0){
                    bit |= (1<<j);
                    c[s]--;
                    // cout<<j/n<<"()()\n";
                    m.erase(m.find(mp(r[j/n],mp(1,j/n))));
                    r[j/n]--;
                    if(r[j/n]) m.insert(mp(r[j/n],mp(1,j/n)));
                    break;
                }
            }
        }
        // pr("here");
        if(!m.empty()) cur = *m.begin();
    }
    return bit;
}
void recur(ll i, ll bit, ll cur){
    if(i == n*n){
        if(bit == tot){
            // cout<<bit<<"()"<<cur<<"\n";
            ans = min(ans,cur);
        }
        return;
    }
    bit = comp(bit);
    if(bit & (1<<i)){
        recur(i+1,bit,cur);
        return;
    }
    recur(i+1,bit,cur);
    bit |= (1<<i);
    cur += b[i];
    // cout<<i<<"()()"<<cur<<"\n";
    bit = comp(bit);
    recur(i+1,bit,cur);
}

void solve(){
    re n;
    ll cur = 0;
    forn(i,n){
        forn(j,n){
            re a[cur];
            cur++;
        }
    }
    ll bit = 0;
    fo(n*n){
        if(a[i] != -1) bit |= (1<<i);
    }
    cur = 0;
    forn(i,n){
        forn(j,n){
            re b[cur];
            cur++;
        }
    }
    tot = (1<<(n*n))-1;
    bit = comp(bit);
    fo(n) re r[i]; fo(n) re c[i];
    ans = 1e15;
    recur(0,bit,0);
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
    fo(t){
        cout<<"Case #"<<i+1<<": "; solve();
    }
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
