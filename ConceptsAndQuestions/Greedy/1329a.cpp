


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

ll n,m;
const ll M = 1e5;
ll l[M];

void solve(){
    ll sum = 0;
    fo(m) sum+=l[i];
    if(sum<n){
        cout<<"-1\n";
        return;
    }
    // sort(l,l+m);
    for(ll i = 0; i<m; i++){
        if(l[i]>(n-i)){
            cout<<"-1\n";
            return;
        }
    }
    vl ans;
    ll ss[m];
    ss[m-1] = l[m-1];
    for(ll i = m-2; i>=0 ; i--){
        ss[i] = ss[i+1] + l[i];
    }
    // fo(m) cout<<ss[i]<<" ";cout<<"\n";
    ll i = 0;
    ll j = 0;
    while(i<n && j<m){
        i = max(i,n-ss[j]);
        // cout<<i<<" "<<ss[i]<<"()\n";
        ans.pb(i+1);
        i++;
        j++;
    }
    fo(ans.size()) cout<<ans[i]<<" ";cout<<"\n";
    return;
}

int32_t main(){
    KOBE;
    cin>>n>>m;
    fo(m) cin>>l[i];
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
