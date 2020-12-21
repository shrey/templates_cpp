

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

const ll M = 4e5+100;
ll pres[M] = {0};
ll suff[M] = {0};
ll pre[M] = {0};

void solve(){
    ll n; re n;
    fo(2*n+1){
        pre[i] = 0;
        suff[i] = 0;
        pres[i] = 0;
    }
    ll a[n]; fo(n) re a[i];
    multiset<ll> m;
    multiset<ll,greater<ll> > m2;
    fo(2*n){
        m.insert(i+1); m2.insert(i+1);
    }
    fo(n){
        m.erase(m.find(a[i])); m2.erase(m2.find(a[i]));
    }
    // pr("here");
    ll ans = 0;

    fo(n) pres[a[i]] = 1;
    for(ll i = 1; i<=2*n; i++){
        if(!pres[i] && !m.empty() && m.find(i) != m.end()){
            m.erase(m.find(i));
        }else if(pres[i]){
            if(!m.empty() && *m.begin() > i){
                // cout<<i<<"()\n";
                m.erase(m.begin());
                pre[i] = 1;
            }
            else{
                break;
            }
        }
    }

    for(ll i = 2*n; i>=1; i--){
        if(!pres[i] && !m2.empty() && m2.find(i) != m2.end()){
            m2.erase(m2.find(i));
        }else if(pres[i]){
            if(!m2.empty() && *m2.begin() < i){
                // cout<<i<<"()\n";
                m2.erase(m2.begin());
                suff[i] = 1;
            }else{
                break;
            }
        }
    }
    for(ll i = 1; i<=2*n; i++){
        // if(suff[i] && pre[i]) cout<<i<<" ";
        ans += (suff[i] && pre[i]);
    }
    // nl;
    pr(ans+1);
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
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
