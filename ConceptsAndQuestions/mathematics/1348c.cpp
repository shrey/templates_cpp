

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


ll d(ll a, ll b){
    if((a%b) == 0) return a/b;
    return a/b+1;
}

//code starts here

ll n,k;
string s;

// bool special(ll freq[]){
//     for(ll i = 1; i<=26; i++){
//         if(freq[i]){
//             if(freq[i]!=k) return false;
//         }
//     }
//     return true;
// }

// bool sing(){
//     for(ll i = 1; i<n; i++){
//         if(s[i]!=s[i-1]) return false;
//     }
//     return true;
// }

void solve(){
    cin>>n>>k>>s;
    sort(s.begin(),s.end());
    if(s[0]!=s[k-1]){
        cout<<s[k-1]<<"\n";
        return;
    }
    cout<<s[0];
    if(s[k]!=s[n-1]){
        for(ll i = k; i<n; i++)
            cout<<s[i];
            cout<<"\n";
            return;
    }
    else{
        for(ll i = 0; i<(n-1)/k; i++){
            cout<<s[n-1];
        }cout<<"\n";
        return;
    }

}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        solve();
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
