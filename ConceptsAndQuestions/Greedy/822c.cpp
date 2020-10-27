

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

ll n,x;

vector<pair<pair<ll,ll>, pair<ll,ll> > > qr;
const ll M = 2e5+100;
const ll inf = 2e12;
void solve(){
    fo(n){
        ll l,r,c;
        cin>>l>>r>>c;
        qr.pb(mp(mp(l,-1),mp(r,c)));
        qr.pb(mp(mp(r,1),mp(l,c)));
    }
    sort(qr.begin(),qr.end());
    ll bestcost[M];
    fo(M) bestcost[i] = inf;
    ll ans = 2*inf;
    for(ll i = 0; i<qr.size(); i++){
        ll type = qr[i].ff.sec;
        ll curlen = abs(qr[i].ff.ff-qr[i].sec.ff);
        curlen++;
        if(type == -1){
            if(curlen<=x){
                ans = min(ans,qr[i].sec.sec + bestcost[x-curlen]);
            }
        }
        else{
            bestcost[curlen] = min(bestcost[curlen],qr[i].sec.sec);
        }
    }
    if(ans>=inf){
        pr(-1);
        return;
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    cin>>n>>x;
    solve();
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
