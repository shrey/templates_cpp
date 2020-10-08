

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
#define pr(st) cout<<st<<"\n"
#define int long long
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

const ll M = 1e5+10;
vector<ll> st(4*M,0);


void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        st[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        st[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        st[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2+1, tl, tm, l, min(r, tm), add);
        update(v*2+2, tm+1, tr, max(l, tm+1), r, add);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return st[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return st[v] + get(v*2+1, tl, tm, pos);
    else
        return st[v] + get(v*2+2, tm+1, tr, pos);
}


int32_t main(){
    KOBE;
    ll n,m,c;
    cin>>n>>m>>c;
    ll a[n];
    fo(n) a[i] = c;
    build(a,0,0,n-1);
    while(m--){
        char ch;
        cin>>ch;
        if(ch == 'Q'){
            ll q;
            cin>>q;
            q--;
            cout<<get(0,0,n-1,q)<<"\n";
        }else{
            ll l,r,k;
            cin>>l>>r>>k;
            l--; r--;
            update(0,0,n-1,l,r,k);
        }
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
//don'st be obsessed with binary search
