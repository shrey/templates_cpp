

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

//code starts here

ll n,p;
const ll M = 2e5+100;
vl st;
vl st1;
ll a[M];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

// void update(ll v, ll tl, ll tr, ll pos, ll change){
//     if(tl == tr){
//         st[v] += change; //change here
//         return;
//     }
//     ll tm = (tl + tr)/2;
//     if(pos <= tm) update(2*v,tl,tm,pos,change);
//     else update(2*v + 1,tm+1,tr,pos,change);
//     st[v] = st[2*v] + st[2*v+1]; //change here
// }

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 1e15;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return min(query(2*v,tl,tm,l,r) , query(2*v+1,tm+1,tr,l,r)); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = min(st[2*v] , st[2*v+1]); // change here
}

ll query2(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return st1[v];
    ll tm = (tl + tr)/2;
    return gcd(query2(2*v,tl,tm,l,r) , query2(2*v+1,tm+1,tr,l,r)); // change here
}

void build2(ll v, ll tl, ll tr){
    if(tl == tr){
        st1[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build2(2*v,tl,tm);
    build2(2*v+1,tm+1,tr);
    st1[v] = gcd(st1[2*v] , st1[2*v+1]); // change here
}

pll bs(ll idx){
    ll e = n-1, s = idx;
    ll ans = 0;
    while(s <= e){
        // if(a[idx] == 3) cout<<s<<"()"<<e<<"\n";
        ll mid = (s+e)/2;
        ll g = query2(1,0,n-1,idx,mid);
        ll mn = query(1,0,n-1,idx,mid);
        if(g == mn && mn == a[idx]){
            ans = mid-idx;
            // if(idx == 2) cout<<ans<<"()()\n";
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    s = 0, e = idx;
    ll a2 = 0;
    while(s <= e){
        // if(a[idx] == 3) cout<<s<<"()"<<e<<"\n";
        ll mid = (s+e)/2;
        ll g = query2(1,0,n-1,mid,idx);
        ll mn = query(1,0,n-1,mid,idx);
        if(g == mn && mn == a[idx]){
            a2 = idx-mid;
            // if(idx == 1) cout<<mid<<"()()\n";
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    // if(a[idx] == 3) cout<<ans<<"()()"<<a2<<"\n";
    return mp(ans,a2);
}

void solve(){
    re n; re p;
    st.clear();
    st1.clear();
    st.resize(4*n+1);
    st1.resize(4*n+1);
    fo(n+1) st[i] = 1e15;
    fo(n) re a[i];
    build(1,0,n-1);
    build2(1,0,n-1);
    // pr(query2(1,0,n-1,0,1));
    vp op;
    // pr("here");
    ll i = 0;
    while(i<n){
            // cout<<i<<"()\n";
        if(a[i] < p){
            pll cur = bs(i);
            ll cnt = cur.ff + cur.sec;
            if(cnt) op.pb(mp(a[i],cnt));
            i += cur.ff+1;
        }else{
            i++;
        }
    }
    sort(all(op));
    ll ans = 0;
    ll cnt = 0;
    // for(auto x: op) cout<<x.ff<<"()"<<x.sec<<"\n";
    if(op.size() && op[0].sec == n-1){
        pr(op[0].ff*(n-1));
        // pr("here");
        return;
    }
    for(ll i = 0; i<op.size(); i++){
        // cout<<op[i].ff<<"()"<<op[i].sec<<"\n";
        if(cnt >= (n-1)) break;
        cnt++;
        ans += p;
        ll k = min((n-1-cnt),op[i].sec);
        ans += op[i].ff * k;
        cnt += k;
    }
    // cout<<ans<<"()()\n";
    if(cnt < n-1) ans += (n-1-cnt)*p;
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
    while(t--) solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
