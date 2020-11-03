

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
#define re(x) cin>>x
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)

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

ll powmod(ll n, ll k, ll m){
    if(k == 0) return (1%m);
    ll a = powmod(n,k/2,m);
    if(k%2){
        return (n%m * (a*a)%m)%m;
    }
    return (a*a)%m;
}

bool ok(string s){
    if(s[0] == '0') return false;
    return true;
}

void prst(string s){
    ll i = 0;
    while(i<s.length() && s[i] == '0') i++;
    for(ll j = i; j<s.length(); j++){
        cout<<s[j];
    }nl;
}

string num;
ll a,b;
const ll M = 1e6+100;
vl frem(M);
vl revrem(M);
void solve(){
    frem[0] = (num[0]-'0')%a;
    for(ll i = 1; i<num.length(); i++){
        ll cur = num[i]-'0';
        frem[i] = ((10%a)*(frem[i-1]%a) + (cur)%a)%a;
    }
    string numo = num;
    reverse(num.begin(),num.end());
    revrem[0] = (num[0]-'0')%b;
    for(ll i = 1; i<num.length(); i++){
        ll cur = num[i]-'0';
        revrem[i] = (((cur%b * powmod(10,i,b))%b) + (revrem[i-1]%b))%b;
    }

    ll n = num.length();
    // fo(n) cout<<frem[i]<<" ";nl;
    // fo(n) cout<<revrem[i]<<" ";nl;
    for(ll i = 0; i<n-1; i++){
        if(frem[i] == 0 && revrem[n-i-2] == 0){
            string n1 = numo.substr(0,i+1);
            string n2 = numo.substr(i+1,n-i-1);
            if(ok(n1) && ok(n2)){
                YES;
                pr(n1);
                pr(n2);
                return;
            }
        }
    }
    NO;
}

int32_t main(){
    KOBE;
    re(num);
    re(a); re(b);
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
