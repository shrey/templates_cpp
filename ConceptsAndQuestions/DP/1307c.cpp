

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

string s;

const ll M = 2e5+1;
ll sing[26] = {0}, doub[26][26] = {0};


int main(){
    KOBE;
    cin>>s;
    ll n = s.length();
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<26; j++){
            doub[j][s[i]-'a'] += sing[j];
        }
        sing[s[i]-'a']++;
    }
    ll ans = INT_MIN;
    fo(26) ans = max(ans,sing[i]);
    forn(i,26){
        forn(j,26){
            ans = max(ans,doub[i][j]);
        }
    }
    cout<<ans<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
