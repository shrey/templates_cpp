

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

class node{
    public:
    char data;
    umap<char,node *> children;
    node(char a){
        data = a;
    }
};

class trie{
    node *root;
    public:
    ll cnt;
        trie(){
            root = new node('\0');
            cnt = 0;
        }
        void insert(string &w){
            node *temp = root;
            for(ll i = 0; i<w.length(); i++){
                if(temp->children.count(w[i])){
                    temp = temp->children[w[i]];
                }
                else{
                    temp->children[w[i]] = new node(w[i]);
                    temp = temp->children[w[i]];
                    cnt++;
                }
            }
        }

};

string s;
ll k;
bool good[26];

void solve(){
    re s;
    fo(26){
        char ch; re ch;
        if(ch == '1'){
            good[i] = true;
        }else{
            good[i] = false;
        }
    }
    re k;
    trie tr;
    for(ll i = 0; i<s.length(); i++){
        ll cur = 0;
        ll j = i;
        string op = "";
        while(j < s.length() && cur<=k){
            if(!good[s[j]-'a']) cur++;
            op += s[j];
            j++;
        }
        if(cur>k) op.pop_back();
        // cout<<op<<"\n";
        tr.insert(op);
    }
    pr(tr.cnt);
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
