

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

const ll M = 2e6+100;
vl st(M);
ll n;
ll arr[M],l[M],r[M];
ll ans = 0;
ll buildTree(ll ss, ll se, ll si){
    if(ss>se) return lmax;
    if(ss == se){
        st[si] = l[ss];
        return st[si];
    }
    ll mid = (ss+se)/2;
    ll left = buildTree(ss,mid,2*si+1);
    ll right = buildTree(mid+1,se,2*si+2);
    st[si] = min(left,right);
    return st[si];
}

void qry(ll ss, ll se, ll qs, ll qe, ll si, ll k){
    // cout<<ss<<" "<<se<<"\n";
    if(ss>qe || se<qs || ss>se) return;
    if(ss == se){
        if(l[ss]>k){
            // cout<<ss<<"()\n";
            ans++;
        }
        return;
    }
    if(ss>=qs && se<=qe){
        if(st[si]>k){
            // cout<<se<<"()"<<ss<<"\n";
            ans+=(se-ss+1);
            return;
        }
    }
    ll mid = (ss+se)/2;
    qry(ss,mid,qs,qe,2*si+1,k);
    qry(mid+1,se,qs,qe,2*si+2,k);
}

int32_t main(){
    KOBE;
    cin>>n;
    fo(n) cin>>arr[i];
    map<ll,ll> cnt;
    for(ll i = 0; i<n; i++){
        cnt[arr[i]]++;
        l[i] = cnt[arr[i]];
    }
    cnt.clear();
    for(ll i = n-1; i>=0; i--){
        cnt[arr[i]]++;
        r[i] = cnt[arr[i]];
    }
    buildTree(0,n-1,0);
    ll res = 0;
    for(ll i = n-1; i>=1; i--){
        ans = 0;
        qry(0,n-1,0,i-1,0,r[i]);
        // cout<<ans<<"\n";
        res+=ans;
    }
    cout<<res<<"\n";
    // fo(n) cout<<l[i]<<" ";cout<<"\n";
    // fo(n) cout<<r[i]<<" ";cout<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
