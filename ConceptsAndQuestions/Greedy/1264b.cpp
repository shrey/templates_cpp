

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
#include<cstring>
#include<numeric>
#include<array>


using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
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
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)
#define all(x) x.begin(),x.end()

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

ll a,b,c,d;

void prs(ll a, ll b, ll num){
    bool flag = true;
    while(num--){
        if(flag) cout<<a<<" ";
        else cout<<b<<" ";
        flag = !flag;
    }
}

void solve(){
    re a; re b; re c; re d;
    if(a > b){
        if(a > b+1 || (c || d)){
            NO;
            return;
        }
        else{
            bool flag = true;
            YES;
            fo(2*a-1){
                if(flag) cout<<0<<" ";
                else cout<<1<<" ";
                flag = !flag;
            }
            return;
        }
    }
    if(d > c){
        if(d > c + 1 || (a || b)){
            NO;
            return;
        }
        else{
            YES;
            bool flag = true;
            fo(2 * d -1){
                if(flag) cout<<3<<" ";
                else cout<<2<<" ";
                flag = !flag;
            }
            return;
        }
    }
    vl l1,l2;
    ll diff = abs((b-a) - (c-d));
    // cout<<a<<"()"<<b<<"()"<<c<<"()"<<d<<"\n";
    if(b-a == c-d){
        YES;
        prs(0,1,2*a);
        b-=a;
        c-=d;
        prs(2,1,2*c);
        prs(2,3,2*d);
    }else if(b-a > c-d && (abs((b-a) - (c-d)) == 1)){
        YES;
        prs(1,0,2*a+1);
        b-=(a+1);
        c-=d;
        prs(2,1,2*c);
        prs(2,3,2*d);
    }else if(b-a < c-d && (abs((b-a) - (c-d)) == 1)){
        YES;
        prs(0,1,2*a);
        b-=a;
        c-=d;
        prs(2,1,2*b);
        prs(2,3,2*d+1);
    }else{
        NO;
        return;
    }
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
    while(t--) solve();
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
// try to find repeating pattern in matrices
