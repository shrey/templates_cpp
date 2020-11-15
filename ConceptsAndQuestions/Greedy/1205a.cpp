

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
#include<math.h>
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
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)

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
    re n;
    ll arr[2*n];
    ll mn = 1, mx = 2*n;
    ll flag = 1;
    for(ll i = 0; i<n; i++){
        if(flag){
            arr[i] = mn;
            arr[n+i] = mn+1;
            mn+=2;
        }else{
            arr[i] = mx;
            arr[i+n] = mx-1;
            mx-=2;
        }
        flag^=1;
    }
    ll op[4*n];
    for(ll i = 0; i<2*n; i++){
        op[i] = arr[i];
        op[2*n+i] = arr[i];
    }
    ll pre[4*n];
    pre[0] = op[0];
    for(ll i = 1; i<4*n; i++){
        pre[i] = pre[i-1] + op[i];
    }
    ll cur = pre[n-1];
    mx = cur; mn =cur;
    ll i = n;
    while(i<4*n){
        ll sm = pre[i] - pre[i-n];
        // cout<<i<<"()"<<sm<<"\n";
        mx = max(sm,mx);
        mn = min(mn,sm);
        i++;
    }
    // cout<<mx<<" "<<mn<<"\n";
    if(mx-mn>1){
        NO;
        return;
    }else{
        YES;
        fo(2*n) cout<<arr[i]<<" ";nl;
    }
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
