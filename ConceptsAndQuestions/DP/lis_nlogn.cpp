

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



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
#define ss second
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

ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}


ll binsearch(vl &v, ll l, ll r,ll num){
        ll ans = 0;
        while(l<=r){
            ll mid = (l+r)/2;
            if(v[mid]>num){
                r = mid-1;
            }
            else if(v[mid]<=num){
                ans = mid;
                l = mid+1;
            }
        }
        return ans;

}

ll lis(vl &v, ll n){
    if(v.size() == 0) return 0;
    vl tail(v.size(),0);
    ll len = 1;
    tail[0] = v[0];
    for(ll i = 1; i<n; i++){
        if(v[i]<tail[0]){
            tail[0] = v[i];
        }
        else if(v[i]>tail[len-1]){
            tail[len++] = v[i];
        }
        else{
            tail[binsearch(tail,0,len-1,v[i])] = v[i];
        }
    }
    return len;
}

int main(){
    KOBE;
    vector<ll> v;
    ll arr[] = { 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    ll n = sizeof(arr)/sizeof(int);
    fo(n){
        v.pb(arr[i]);
    }
    cout<<lis(v,n)<<"\n";

}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
