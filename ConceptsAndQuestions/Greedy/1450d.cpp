

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

const ll M = 3e5+100;
ll n,arr[M];

void solve(){
    re n; fo(n) re arr[i];
    string ans = "";
    fo(n) ans += '0';
    multiset<ll> m;
    set<ll> st;
    fo(n) {
        m.insert(arr[i]);
        st.insert(arr[i]);
    }
    ll s = 0, e = n-1;
    if(st.size() == n) ans[0] = '1';
    bool flag = false;
    fo(n){
        if(arr[i] == 1){
            ans[n-1] = '1';
            if(i != 0 && i != n-1){
                pr(ans);
                return;
            }
            else{
                if(flag){
                    pr(ans); return;
                }
                flag = true;
                if(i == n-1){
                    m.erase(m.find(1));
                    e--;
                }
                else{
                    m.erase(m.find(1));
                    s++;
                }
                ans[n-1] = '1';
            }
        }
    }
    if(!flag){
        pr(ans); return;
    }
    ll cur = 2;
    // cout<<s<<"()"<<e<<"\n";
    while(s<=e){
        if(*m.begin()!=cur){
            pr(ans); return;
        }
        if(arr[s] == cur || arr[e] == cur){
            m.erase(m.find(cur));
            if(arr[s] == cur) s++;
            else e--;
            ans[n-cur] = '1';
            cur++;
        }
        else{
            ans[n-cur] = '1';
            pr(ans); return;
        }
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
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
