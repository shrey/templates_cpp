

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


bool stcharcomp(string &a, string &b){
    ll cnt = 0;
    fo(a.length()){
        if(a[i]!=b[i]){
            cnt++;
            if(cnt>1) return false;
        }
    }
    return true;
}


bool iterStr(string s[], string t, ll n){
    for(ll i = 1; i<n; i++){
        if(!stcharcomp(s[i],t)){
            return false;
        }
    }
    return true;
}

void compute(string s[], ll n){
    string t = s[0];
    for(ll i = 0; i<t.length(); i++){
        for(ll j = 0; j<26; j++){
            t[i] = 'a'+j;
            if(iterStr(s,t,n)){
                cout<<t<<"\n";
                return;
            }
        }
        t = s[0];
    }
    cout<<-1<<"\n";
    return;
}

int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        string s[n];
        fo(n){
            cin>>s[i];
        }
        compute(s,n);
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
