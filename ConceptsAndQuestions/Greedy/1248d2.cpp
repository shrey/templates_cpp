

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
#include<deque>


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
#define vs vector<string>
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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

ll pow(ll n, ll k){
    if(k == 0) return 1;
    ll t = pow(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here

void solve(){
    ll n; re n;
    string s; re s;
    stack<ll> op;
    ll c = 0, o = 0;
    fo(n){
        if(s[i] == '(') c++;
        else o++;
    }
    if(c != o){
        pr(0);
        cout<<"1 1\n";
        return;
    }
    ll mark[n];
    fo(n) mark[i] = -1;
    fo(n){
        if(s[i] == '('){
            op.push(i);
        }else{
            if(!op.empty()){
                mark[op.top()] = i;
                op.pop();
            }
        }
    }
    bool flag = false;
    ll idx[n];
    fo(n) idx[i] = i;
    fo(n){
        if(s[i] == '(' && mark[i] == -1){
            string temp = s.substr(i);
            string fir = s.substr(0,i);

            ll nw[n];
            for(ll j = i; j<n; j++){
                nw[j-i] = j;
            }
            for(ll j = 0; j<i; j++){
                nw[n-i+j] = j;
            }
            s = temp + fir;
            fo(n) idx[i] = nw[i];
            break;
        }
    }
    ll pre[n];
    fo(n){
        pre[i] = 0;
        mark[i] = -1;
    }
    while(!op.empty()) op.pop();
    ll ans = 0;
    ll suff[n];
    fo(n) suff[i] = 0;
    ll pref[n];
    fo(n) pref[i] = 0;
    fo(n){
        if(s[i] == '('){
            op.push(i);
        }
        else{
            if(!op.empty()){
                mark[op.top()] = i;
                op.pop();
                if(!op.empty()) pre[op.top()]++;
            }
            if(op.empty()){
                ans++;
                suff[i]++;
                pref[i]++;
            }
        }
        if(i > 0) pre[i] += pre[i-1];
    }
    for(ll i = n-2; i>=0; i--){
        suff[i] += suff[i+1];
    }
    for(ll i = 1; i<n; i++){
        pref[i] += pref[i-1];
    }
    while(!op.empty()) op.pop();
    ll mx = 0;
    mx = ans;
    pll res = mp(1,1);
    // pr(s);
    // fo(n) cout<<pre[i]<<" "; nl;
    fo(n){
        if(s[i] == '('){
            if(op.size() <= 1){
                // cout<<i<<"()"<<mark[i]<<"\n";
                ll cur = ans + (pre[i]);
                if(op.size() == 0){
                    if(mark[i] != n-1){
                        cur -= suff[mark[i]+1];
                    }
                    if(i != 0){
                        cur -= pref[i-1];
                    }
                }else{
                    cur++;
                }
                if(cur > mx){
                    res = mp(idx[i]+1,idx[mark[i]]+1);
                    mx = cur;
                }
            }
            op.push(i);
        }
        else{
            if(!op.empty()) op.pop();
        }
    }
    // cout<<mx<<"()\n";
    pr(mx);
    cout<<res.ff<<" "<<res.sec<<"\n";
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
// always check for n = 1 condition
// check loop starting and end points :(
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
