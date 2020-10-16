

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


//code starts here

ll n,p;
string s;

ll tch(char a, char b){
    ll n1 = abs(a-b);
    return min(n1,26-n1);
}

// ll tp(ll a, ll b){
//     ll n1 = abs(b-a);
//     return min(n,n-n1);
// }

void solve(){
    p--;
    if(p>=n/2){
        reverse(s.begin(),s.end());
        p = (n-p-1);
    }
    ll ans = 0;
    ll r = -1;
    ans+=tch(s[p],s[n-p-1]);
    for(ll i = p+1; i<n/2; i++){
        if(s[i]!=s[n-i-1]){
            r = i;
            ans+=tch(s[i],s[n-i-1]);
        }
    }
    ll l = -1;
    for(ll i = p-1; i>=0; i--){
        if(s[i]!=s[n-i-1]){
            l = i;
            ans+=tch(s[i],s[n-i-1]);
        }
    }
    // cout<<r<<"()"<<l<<"\n";
    l = (l == -1)? p : l;
    r = (r == -1)? p : r;
    ans += (r-p) + (p-l);
    ans+=(min(r-p,p-l));
    cout<<ans<<"\n";
}

int32_t main(){
    KOBE;
    cin>>n>>p;
    cin>>s;
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
