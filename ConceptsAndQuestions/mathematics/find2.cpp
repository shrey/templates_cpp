

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

class demo{
    static ll cnt;
    int a;
    public:
        static void st(){
            cout<<cnt<<"\n";
        }
        demo(){
            cout<<"HERE"<<"\n";
        }
        demo(demo &d1){
            cout<<"CPY"<<"\n";
        }
};

ll demo:: cnt = 99;

int32_t main(){
    demo a;
    demo c = a;
    demo d;
    d = a;
    demo e(d);
    ll arr[] = {1,3,1,4,3,5,5,6,7,7};
    ll n = sizeof(arr)/sizeof(ll);
    ll tot = 0;
    fo(n) tot = tot ^ arr[i];
    ll msk = 1;
    while((tot&msk) == 0){
        msk = msk<<1;
    }
    ll n1 = 0;
    fo(n){
        if(arr[i]&msk){
            n1^=arr[i];
        }
    }
    cout<<n1<<" "<<(tot^n1)<<"\n";
    KOBE;
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
