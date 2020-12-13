

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

vl gr[26];
ll n,k,x;
vector<string> page[1010];
string s;
vector<string> tot;
vb cstack(26,false);
umap<ll,bool> visited;
string ans = "";
bool fg = false;

bool check(ll cur){
    cstack[cur] = true;
    visited[cur] = true;
    bool ans = false;
    for(auto x: gr[cur]){
        if(!visited[x] && check(x)){
            fg = true;
            return true;
        }
        if(cstack[x]){
            fg = true;
            return true;
        }
    }
    cstack[cur] = false;
    return false;
}

void dfs(ll cur){
    visited[cur] = true;
    for(auto x: gr[cur]){
        if(!visited[x]) dfs(x);
    }
    ans += ('a' + cur);
}

vb used(26,false);
void solve(){
    re n; re k;
    fo(n){
        re x;
        fo(k){
            re s;
            for(auto ch: s){
                used[ch-'a'] = true;
            }
            page[x].pb(s);
        }
    }
    fo(n){
        for(auto str: page[i]){
            tot.pb(str);
        }
    }
    for(ll i = 0; i<tot.size()-1; i++){
        string s1 = tot[i], s2 = tot[i+1];
        bool flag = false;
        for(ll j = 0; j<min(s1.length(),s2.length()); j++){
            if(s1[j] != s2[j]){
                gr[s1[j]-'a'].pb(s2[j]-'a');
                flag = true;
                break;
            }
        }
        if(!flag){
            if(s1.size()>s2.size()){
                pr("IMPOSSIBLE");
                return;
            }
        }
    }
    for(ll i = 0; i<26; i++){
        if(used[i] && !visited[i]){
            if(check(i) || fg){
                pr("IMPOSSIBLE");
                return;
            }
        }
    }
    if(fg){
        pr("IMPOSSIBLE");
        return;
    }
    visited.clear();
    for(ll i = 0; i<26; i++){
        if(used[i] && !visited[i]){
            dfs(i);
        }
    }
    reverse(all(ans));
    pr(ans);

}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
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
