

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

const ll M = 2e5+1;

ll cnt[M] = {0};
ll len = 0;
ll l,r,a,b;
void build(){
    len = a*b;
    cnt[0] = 0;
    for(ll i = 1; i<=len; i++){
        cnt[i] = cnt[i-1];
        if(((i%a)%b) != ((i%b)%a)){
            cnt[i]++;
        }
    }
}

ll comp(ll pos){
    ll rem = pos%len;
    ll q = pos/len;
    ll ans = q*cnt[len]+cnt[rem];
    return ans;
}

ll qry(ll l, ll r){
    return comp(r) - comp(l-1);
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll q;
        cin>>a>>b>>q;
        build();
        while(q--){
            cin>>l>>r;
            cout<<qry(l,r)<<" ";
        }cout<<"\n";

    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
