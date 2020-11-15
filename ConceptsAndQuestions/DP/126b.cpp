

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


bool findMid(string s, ll st, ll en, string comp){
    ll n = comp.length();

    while((st+n-1)<=en){
        string curr = s.substr(st,n);
        if(curr == comp) return true;
        st++;
    }
}

int main(){
    KOBE;
    string s;
    cin>>s;
    string srev = s;
    reverse(s.begin(),s.end());
    ll n = s.length();
    string fr = "",bck = "";
    for(ll i = 0; i<n; i++){
        fr+=s[i];
        bck+=s[n-i-1];
        string bcr = bck;
        reverse(bcr.begin(),bcr.end());
        if(fr == bcr){
            
        }
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
