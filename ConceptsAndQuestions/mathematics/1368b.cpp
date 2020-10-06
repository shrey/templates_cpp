

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

ll pow(ll n, ll k){
    if(k == 0){
        return 1;
    }
    ll a = (pow(n,k/2));
    if(k%2){
        return (a*a*n);
    }
    return (a*a);
}


int32_t main(){
    KOBE;
    ll k;
    cin>>k;
    string ans = "codeforces";
    if(k == 1){
        cout<<ans<<"\n";
        return 0;
    }
    ll x = 1;
    ll curr = pow(x,10);
    while(curr<k){
        x++;
        curr = pow(x,10);
    }
    string temp = ans;
    ll chLen = x-2;
    string nans = "";

    curr = pow(x-1,10);
    ll len = 0;
    while(curr<k){
        curr/=(x-1);
        curr*=x;
        len++;
    }
    // cout<<len<<"\n";
    for(ll i = 0; i<ans.length(); i++){
        nans+=ans[i];
        if(i<(10-len)){
            forn(j,chLen) nans+=ans[i];
        }
        else{
            forn(j,chLen+1) nans+=ans[i];
        }
    }
    cout<<nans<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs

//ccccccccooooooooddddddddeeeeeeefffffffooooooorrrrrrrccccccceeeeeeesssssss
//cccccccooooooodddddddeeeeeeefffffffooooooorrrrrrrcccccccceeeeeeeessssssss