

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

ll n;
string s;
const ll M = 2e5+100;


void solve(){
    re n; re s;
    ll arr[M] = {0};
    ll gr = 0, sm = 0;
    for(ll i = n-2; i>=0; i--){
        if(s[i] == '>') gr++;
        else sm++;
        if(i<n-2 && s[i+1] == s[i]){
            arr[i] = arr[i+1] + 1;
        }
        else{
            arr[i] = 1;
        }
    }
    vl s1(n);
    vl s2(n);
    ll cur = n-sm;
    ll tot = n;
    if(s[0] == '>'){
        s1[0] = cur;
        cur--;
    }
    for(ll i = 1; i<n; i++){
        // cout<<i<<"()\n";
        if(s1[i] != 0) continue;
        if(s[i-1] == '>'){
            s1[i] = cur;
            cur--;
        }else{
            if(i == 1){
                s1[i-1] = tot - arr[i-1];
                cur--;
            }
            s1[i] = tot-arr[i-1]+1;
            ll j = i+1;
            while(j<n && s[j-1] == '<'){
                s1[j] = s1[j-1] + 1;
                j++;
            }
            if(i == 1) tot--;
            tot -= arr[i-1];
            i = j-1;
        }
    }
    cur = 1;
    ll last = 0;
    for(ll i = 0; i<n; i++){
        if(s[i] == '<' || i == n-1){
            for(ll j = i; j>=last; j--){
                s2[j] = cur++;
            }
            last = i + 1;
        }
    }
    fo(n) cout<<s1[i]<<" ";nl;
    fo(n) cout<<s2[i]<<" ";nl;
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
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
