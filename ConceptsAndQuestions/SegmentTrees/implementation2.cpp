

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
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
//range-sum-query tree
const ll M = 1e5+1;

vector<ll> st(M);
vector<ll> lazy(M,0);


ll buildTree(ll a[], ll ss, ll se, ll si){
    if(ss == se){
        st[si] = a[ss];
        return a[ss];
    }
    ll mid = (ss+se)/2;
    st[si] = buildTree(a,ss,mid,2*si+1) + buildTree(a,mid+1,se,2*si+2);
    return st[si];
}

ll query(ll a[], ll ss, ll se, ll qs, ll qe, ll si){
    if(ss>=qs && se<=qe) return st[si];
    if(ss>qe || se<qs) return 0;
    ll mid = (ss+se)/2;
    return (query(a,ss,mid,qs,qe,2*si+1)+query(a,mid+1,se,qs,qe,2*si+2));
}

void update(ll a[], ll ss, ll se, ll si, ll i, ll diff){
    if(i<ss || i>se) return;
    st[si] += diff;
    ll mid = (ss+se)/2;
    if(se == ss) return;
    update(a,ss,mid,2*si+1,i,diff);
    update(a,mid+1,se,2*si+2,i,diff);
}

void rangeUpdate(ll a[], ll ss, ll se, ll si, ll us, ll ue, ll diff){
    if(ss>se || ss>ue || se<us) return;
    ll mid = (ss+se)/2;
    if(se == ss){
        st[si]+=diff;
        return;
    }
    rangeUpdate(a,ss,mid,2*si+1,us,ue,diff);
    rangeUpdate(a,mid+1,se,2*si+2,us,ue,diff);
    st[si] = st[2*si+1] + st[2*si+2];
}

int32_t main(){
    KOBE;
    ll a[] = {1,3,2,-5,6,4};
    ll n = sizeof(a)/sizeof(ll);
    cout<<buildTree(a,0,n-1,0)<<"\n";
    ll l,r;
    update(a,0,n-1,0,3,10);
    rangeUpdate(a,0,n-1,0,4,5,20);
    cin>>l>>r;
    cout<<query(a,0,n-1,l,r,0)<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
