

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

string rp;
ll nb,ns,nc,pb,ps,pc,r,b,s,c;

ll check(ll x){
    ll c1 = max((ll)0,(x*c-nc)*pc);
    ll c2 = max((ll)0,(x*b-nb)*pb);
    ll c3 = max((ll)0,(x*s-ns)*ps);
    if(c1+c2+c3<=r) return 1;
    return 0;
}

void solve(){
    b = 0; s = 0; c = 0;
    fo(rp.length()){
        if(rp[i] == 'B') b++;
        else if(rp[i] == 'C') c++;
        else if(rp[i] == 'S') s++;
    }
    ll st = 0, e = 1e13;
    ll ans = 0;
    while(st<=e){
        ll mid = (st+e)/2;
        if(check(mid)){
            ans = mid;
            st = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout<<ans<<"\n";
}


int32_t main(){
    KOBE;
    cin>>rp>>nb>>ns>>nc>>pb>>ps>>pc>>r;
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
