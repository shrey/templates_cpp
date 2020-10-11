

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
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
#define pr(t) cout<<t<<"\n"
#define int long long
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

ll comp(ll a, ll b){
    if((a+b)%2 == 0) return (a+b)/2;
    return (a+b+1)/2;
}


void solve(){
    ll n;
    string s;
    cin>>n>>s;
    ll ans = 0;
    ll i = 0;
    vl cons;
    ll curr = 0;
    while(i<n){
        ll ind = i;
        curr = 1;
        while(i<n-1 && s[i] == s[i+1]){
            curr++;
            i++;
        }
        cons.pb(curr);
        i++;
    }
    i = 0;
    while(i<cons.size()){
        if(cons[i] == 0){
            i++;
        }
        else if(cons[i]>1){
            ans++;
            i++;
        }
        else{
            if(i<cons.size()-1){
                cons[i+1]--;
                ans++;
                i++;
            }
            else{
                ans++;
                i++;
            }
        }
    }
    cout<<ans<<"\n";
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        solve();
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
