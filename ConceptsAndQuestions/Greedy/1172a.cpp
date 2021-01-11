

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

ll n;
const ll M = 2e5+100;
ll a[M],b[M], pres[M] = {0};
ll chance = 0;

bool check(){
    fo(n) pres[a[i]] = 1;

    deque<ll> q;
    fo(n) q.push_back(b[i]);
    while(pres[q.back()+1]){
        a[q.back()+1] = 0; pres[q.front()] = 1;
        q.push_back(q.back() + 1);
        q.pop_front();
        chance++;
    }
    ll cur = 1;
    bool flag = true;
    while(!q.empty()){
        if(q.front() != cur){
            flag = false;
        }
        q.pop_front();
        cur++;
    }
    return flag;
}

void solve(){
    re n; fo(n) re a[i]; fo(n) re b[i];
    if(check()){
        pr(chance); return;
    }
    ll pos[M] = {0};
    for(ll i = 1; i<=n; i++) pos[b[i-1]] = i;
    ll curans = pos[1] + 1;
    for(ll i = 2; i<=n; i++){
        if(pos[i] <= curans) continue;
        if(pos[i] - curans >= i - 1) curans = pos[i] - (i - 1) + 1;
    }
    pr(curans + n - 1);

}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
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
