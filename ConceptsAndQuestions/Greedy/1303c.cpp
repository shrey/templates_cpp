

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


//code starts here

string str;
const ll M = 27;
vl gr[M];
string ans = "";
vl visited(26,false);

void addEdge(ll a, ll b){
    if(a == b) return;
    if(find(gr[a].begin(),gr[a].end(),b) == gr[a].end()){
        gr[a].pb(b);
        gr[b].pb(a);
    }
}


void dfs(ll cur){
    visited[cur] = true;
    char c = 'a'+cur;
    ans+=c;
    for(auto ch: gr[cur]){
        if(!visited[ch]) dfs(ch);
    }
}

bool spec(){
    if(str.length() == 1) return true;
    for(ll i = 1; i<str.length(); i++){
        if(str[i]!=str[i-1]) return false;
    }
    return true;
}

void solve(){
    cin>>str;
    if(spec()){
        YES;
        visited[str[0]-'a'] = true;
        ans+=(str[0]);
        fo(26){
            if(!visited[i]){
                char c = 'a'+i;
                ans+=c;
            }
        }
        cout<<ans<<"\n";
        return;
    }
    for(ll i = 1; i<str.length(); i++){
        addEdge(str[i]-'a',str[i-1]-'a');
    }

    bool flag = false;
    for(ll i = 0; i<26; i++){
        if(gr[i].size()>2){
            flag = false;
            break;
        }
        if(gr[i].size() == 1){
            flag = true;
        }
    }
    if(!flag){
        NO;
        return;
    }
    for(ll i = 0; i<26; i++){
        if(gr[i].size() == 1 && !visited[i]){
            dfs(i);
        }
    }
    for(ll i = 0; i<26; i++){
        if(!visited[i]){
            char c = 'a'+i;
            ans+=c;
        }
    }
    YES;
    cout<<ans<<"\n";

}


int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        solve();
        fo(27) gr[i].clear();
        fo(26) visited[i] = false;
        ans = "";
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
