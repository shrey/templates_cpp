

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
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
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


//code starts here

string s,w;
const ll M = 2e5+100;
ll mv[M];


bool subs(string &curr){
    ll i = 0, j = 0;
    while(i<curr.length() && j<w.length()){
        if(curr[i] == w[j]){
            i++; j++;
        }
        else i++;
    }
    if(j == w.length()) return true;
    return false;
}


bool is_subs(ll m){
    string curr = "";
    umap<ll,bool> mark;
    fo(m) mark[mv[i]] = true;
    fo(s.length()){
        if(!mark[i]) curr+=s[i];
    }
    // cout<<curr<<"()\n";
    if(subs(curr)) return true;
    return false;
}

void solve(){
    ll st = 0, en = s.length()-1;
    ll ans = 0;
    while(st<=en){
        ll mid = (st+en)/2;
        // cout<<st<<"()"<<en<<"()"<<mid<<"\n";
        if(is_subs(mid)){
            ans = max(mid,ans);
            st = mid+1;
        }
        else{
            en = mid-1;
        }
    }
    cout<<ans<<"\n";
}


int32_t main(){
    KOBE;
    cin>>s>>w;
    fo(s.length()){
         cin>>mv[i];
         mv[i]--;
    }
    solve();
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