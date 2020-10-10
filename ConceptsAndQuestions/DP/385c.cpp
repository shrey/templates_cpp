

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

const ll M = 1e7+1;

const ll maxn = 1e7+1;
ll n,m,l,r,maxe = imin;
ll dp[maxn] = {0};
ll cnt[maxn] = {0};
ll arr[M];

bool prime[M];

void seive(){
    fo(M) prime[i] = true;
    for(int p = 2; p*p<M; p++){
        if(prime[p] == true){
            for(int i = p*p; i<M; i+=p){
                prime[i] = false;
            }
        }
    }
}

ll concat(ll n){
    ll count = 0;
    for(ll i = 1; (n*i)<=maxe; i++){
        if(cnt[n*i]) count+=(cnt[n*i]);
    }
    return count;
}

void compute(){
    for(ll i = 2; i<=maxe; i++){
        dp[i] = dp[i-1];
        if(prime[i]){
            dp[i]+=concat(i);
        }
    }
}

ll solve(){

    if(l>maxe && r>maxe) return 0;
    l = min(maxe,l);
    r = min(maxe,r);
    return dp[r]-dp[l-1];
}



int32_t main(){
    KOBE;
    seive();
    cin>>n;
    fo(n) cin>>arr[i];

    fo(n){
        maxe = max(arr[i],maxe);
        cnt[arr[i]]++;
    }

    compute();
    cin>>m;
    while(m--){
        cin>>l>>r;
        cout<<solve()<<"\n";
    }
    // for(ll i = 2; i<=maxe; i++){
    //     cout<<dp[i]<<" ";
    // }cout<<"\n";
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
