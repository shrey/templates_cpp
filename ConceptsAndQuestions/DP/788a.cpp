

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


ll n;
const ll M = 2e5+10;
ll arr[M];

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

ll diff[M];

int32_t main(){
    KOBE;
    cin>>n;
    fo(n) cin>>arr[i];
    for(ll i = 0; i<n-1; i++){
        diff[i] = abs(arr[i]-arr[i+1]);
    }
    ll flag = -1;
    n--;
    ll curr = diff[0];
    // fo(n) cout<<diff[i]<<" ";cout<<"\n";
    ll s = 0, e = 0;
    ll ans = 0;
    ans = max(ans,curr);
    while(s<n || e<n){
        if(e<n && curr>=0){
            e++;
            curr+=(flag*diff[e]);
            ans = max(ans,curr);
            flag*=-1;
        }
        else if(curr<0 || e == n){
            curr-=diff[s];
            s++;
            curr*=-1;
            flag*=-1;
            ans = max(ans,curr);
        }
        ans = max(ans,curr);
    }
    ans = max(ans,curr);
    cout<<ans<<"\n";
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