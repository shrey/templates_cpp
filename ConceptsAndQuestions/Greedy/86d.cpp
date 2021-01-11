

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
typedef int ll;
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

struct node{
    ll l, r, ind;
};

bool compare(node &a, node &b){
    if(a.l/1000 == b.l/1000) return a.r < b.r;
    return a.l/1000 < b.l/1000;
}

const ll M = 2e5+100;
const ll MX = 1e6+100;
ll a[M],n,t;
ll freq[MX] = {0};


void solve(){
    re n; re t;
    fo(n) re a[i];
    ll l = 0, r = -1;
    vector<node> q(t);
    fo(t){
        re q[i].l; re q[i].r;
        q[i].ind = i;
    }
    ll ans = 0;
    sort(q.begin(),q.end(),compare);
    ll res[t+1];
    fo(t){
        ll cl = q[i].l, cr = q[i].r;
        cr--; cl--;
        while(r < cr){
            r++;
            ans -= freq[a[r]]*freq[a[r]]*a[r];
            freq[a[r]]++;
            ans += freq[a[r]] * freq[a[r]]*a[r];
        }
        while(l > cl){
            l--;
            ans-=freq[a[l]]*freq[a[l]]*a[l];
            freq[a[l]]++;
            ans += freq[a[l]]*freq[a[l]]*a[l];
        }
        while(l < cl){
            ans-=freq[a[l]]*freq[a[l]]*a[l];
            freq[a[l]]--;
            ans += freq[a[l]]*freq[a[l]]*a[l];
            l++;
        }
        while(r > cr){
            ans -= freq[a[r]]*freq[a[r]]*a[r];
            freq[a[r]]--;
            ans += freq[a[r]] * freq[a[r]]*a[r];
            r--;
        }
        res[q[i].ind] = ans;
    }
    fo(t) cout<<res[i]<<"\n";
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
