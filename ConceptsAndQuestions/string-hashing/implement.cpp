

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

const ll mod = 1e9 + 9;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll comp_hash(string &s){
    const ll p = 31;
    ll hash_val = 0;
    ll p_pow = 1;
    for(char c: s){
        hash_val = (hash_val+(c-'a'+1)*p_pow)%mod;
        p_pow = (p_pow*p)%mod;
    }
    return hash_val;
}

vector< vector<ll> > group_identical_strings(vector<string> &s){
    ll n = s.size();
    vector<pair<ll,ll> > hashes(n);
    fo(n){
        hashes[i] = mp(comp_hash(s[i]),i);
    }
    sort(hashes.begin(),hashes.end());
    vector<vector<ll> > groups;
    for(ll i = 0; i<n; i++){
        vl curr;
        while(hashes[i].first == hashes[i+1].first && i<n-1){
            curr.pb(hashes[i].second);
            curr.pb(hashes[i+1].second);
            i++;
        }
        groups.pb(curr);
    }
    return groups;
}

int main(){
    KOBE;
    vector<string> s;
    ll n;
    cin>>n;
    fo(n){
        string t;
        cin>>t;
        s.pb(t);
    }
    vector<vector<ll> > groups = group_identical_strings(s);
    for(ll i = 0; i<groups.size(); i++){
        for(auto x: groups[i]){
            cout<<s[x]<<" ";
        }cout<<"\n";
    }

}
/*
6
shrey dubey is a shrey dubey
*/

//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
