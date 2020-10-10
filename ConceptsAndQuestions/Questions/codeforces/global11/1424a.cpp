
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

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        string s;
        cin>>n>>k>>s;
        //if k remains after all operations then minimise remaining l
        ll i = 0;
        ll l = 0;
        ll w = 0;
        ll ans = 0;
        if(s[0] == 'W') ans++;
        for(ll i = 1; i<n; i++){
            if(s[i] == 'W'){
                if(s[i-1] == 'W') ans+=2;
                else ans+=1;
            }
        }
        fo(n){
            if(s[i] == 'L') l++;
            else w++;
        }
        if(l<=k){
            cout<<2*n-1<<"\n";
            continue;
        }
        if(w == 0 && k>0){
            cout<<2*k-1<<"\n";
            continue;
        }
        vl cons;
        while(i<n){
            if(s[i] == 'W'){
                ll curr = 0;
                i++;
                while(i<n && s[i]!='W'){
                    i++;
                    curr++;
                }
                if(i<n && curr>0){
                    cons.pb(curr);
                }
            }
            else{
                i++;
            }
        }
        sort(cons.begin(),cons.end());
        for(auto x: cons){
            // cout<<x<<"()\n";
            if(x<=k){
                ans+=(2*x+1);
                k-=x;
            }
            else{
                break;
            }
        }
        if(k>0) ans+=2*k;
        cout<<ans<<"\n";
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
//don't be obsessed with binary search