

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
#define nl cout<"\n"

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

void solve(){
    ll n;
    cin>>n;
    ll fact[n];
    fo(n) cin>>fact[i];
    ll f1 = lmax, f2 = 0;
    umap<ll,ll> cnt;
    fo(n){
        f1 = min(f1,fact[i]);
        f2 = max(f2,fact[i]);
        cnt[fact[i]]++;
    }
    ll num = f1*f2;
    // pr(num);
    set<ll> op;
    // umap<ll,bool> mark;
    for(ll i = 2; i*i<=num; i++){
        if(num%i == 0){
            op.insert(i);
            op.insert(num/i);
        }
    }
    // for(auto x: op){
    //     cout<<x<<" ";
    // }cout<<"\n";
    sort(fact,fact+n);
    if(n!=op.size()){
        pr(-1);
        return;
    }
    ll i = 0;
    for(auto x: op){
        if(x!=fact[i]){
            pr(-1);
            return;
        }
        i++;
    }
    pr(num);
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
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
