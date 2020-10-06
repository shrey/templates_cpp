

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
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll m,n;
const ll M = 200;
ll mat[M][M];

ll calc(ll a, ll b, ll c, ll d, ll t){
    ll ans = abs(t-a) + abs(t-b) + abs(t-c) + abs(t-d);
    return ans;
}

ll calc2(ll a, ll b, ll c, ll d, ll t){
    ll ans = a+b+c+d-4*t;
    return ans;
}

ll comp(ll a, ll b, ll c, ll d){
    ll mint = min(a,min(b,min(c,d)));
    ll maxt = max(a,max(b,max(c,d)));
    ll s = mint, e = maxt;

    ll ans = lmax;
    while(s<=e){
        // cout<<s<<" "<<e<<"\n";
        ll mid = (s+e)/2;
        ll curr = calc2(a,b,c,d,mid);
        ans = min(ans,calc(a,b,c,d,mid));
        if(curr>0){
            //increase mid
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}


void solve(){
    ll ans = 0;
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<m; j++){
            ll cans = comp(mat[i][j],mat[n-i-1][j],mat[i][m-j-1],mat[n-i-1][m-j-1]);
            // cout<<i<<" "<<j<<" "<<cans<<"\n";
            ans+=cans;
        }
    }
    cout<<(ans/4)<<"\n";
}


int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(ll i = 0; i<n; i++){
            for(ll j = 0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        solve();
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
