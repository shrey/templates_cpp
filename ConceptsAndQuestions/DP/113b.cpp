

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
#define LG 20

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

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
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

//code starts here

const ll M = 2010;
ll p1[M] = {0}, p2[M] = {0};
string s,s1,s2;
ll ans = 0;
class Node{
    public:
        char data;
        umap<char,Node*> children;
        ll cnt;

        Node(char d){
            data = d;
            cnt = 0;
        }
};

class Trie{
    Node* root;

    public:
        Trie(){
            root = new Node('\0');
        }
        void insert(ll idx){
            Node* temp = root;
            for(int i = idx; i<s.length(); i++){
                char ch = s[i];
                if(temp->children.count(ch)){
                    temp = temp->children[ch];
                }
                else{
                    Node* n = new Node(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
                if(i - idx + 1 >= max(s1.length(),s2.length()) && temp->cnt == 0 && p2[i]){
                    temp->cnt++;
                    ans++;
                }
            }
        }
};

vector<int> z_function(string &s) {   // replace vector<ll> by string to get string
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve(){
    re s; re s1; re s2;
    ll n = s.length();
    string ts1 = s1 + s;
    string ts2 = s2 + s;
    vl z1 = z_function(ts1);
    vl z2 = z_function(ts2);
    for(ll i = s1.length(); i<z1.size(); i++){
        if(z1[i] >= s1.length()) p1[i-s1.length()]++;
    }
    for(ll i = s2.length(); i<z2.size(); i++){
        if(z2[i] >= s2.length()) p2[i-1]++;
    }
    // fo(n) cout<<p1[i]<<" "; nl;
    // fo(n) cout<<p2[i]<<" "; nl;
    Trie tr;
    for(ll i = 0; i<n; i++){
        if(p1[i]){
            tr.insert(i);
        }
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    // re t;
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
