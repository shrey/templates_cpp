

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
        ll cnt;
        node *left;
        node *right;
        node(){ cnt = 1; left = NULL; right = NULL; }
};

class trie{
    node *root;
    public:
        trie(){
            root = new node();
        }
        void insert(ll num){
            node *temp = root;
            for(ll i = 31; i>=0; i--){
                ll bit = (num>>i)&1;
                // cout<<bit<<"()\n";
                if(bit != 0){
                    if(temp->right != NULL){
                        temp = temp->right;
                        temp->cnt++;
                    }
                    else{
                        temp->right = new node();
                        temp = temp->right;
                    }
                }else{
                    // pr("new");
                    if(temp->left != NULL){
                        temp = temp->left;
                        temp->cnt++;
                    }
                    else{
                        // pr("here");
                        temp->left = new node();
                        temp = temp->left;
                    }

                }
            }
        }
        void del(ll num){
            node *temp = root;
            for(ll i = 31; i>=0; i--){
                ll bit = (num>>i)&1;
                if(bit){
                    if(temp->right->cnt == 1){
                        temp->right = NULL;
                        return;
                    }
                    temp = temp->right;
                    temp->cnt--;
                }else{
                    if(temp->left->cnt == 1){
                        temp->left = NULL;
                        // cout<<num<<i<<"\n";
                        return;
                    }
                    temp = temp->left;
                    temp->cnt--;
                }
            }
        }
        ll maxXor(ll num){
            node *temp = root;
            ll ans = 0;
            for(ll i = 31; i>=0; i--){
                ll bit = (num>>i)&1;
                if(bit){
                    if(temp->left){
                        temp = temp->left;
                        ans ^= (1<<i);
                    }
                    else{
                        temp = temp->right;
                    }
                }else{
                    if(temp->right){
                        temp = temp->right;
                        ans ^= (1<<i);
                    }else{
                        temp = temp->left;
                    }
                }
            }
            return ans;
        }

};

void solve(){
    trie tr;
    ll n;
    re n;
    tr.insert(0);
    while(n--){
        char ch; ll cur;
        re ch; re cur;
        if(ch == '+'){
            tr.insert(cur);
        }else if(ch == '-'){
            tr.del(cur);
        }else{
            pr(tr.maxXor(cur));
        }
    }
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
