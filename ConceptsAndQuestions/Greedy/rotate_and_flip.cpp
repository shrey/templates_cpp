

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

ll n,m,q;
vp pos;

void solve(){
    re n;
    pos.resize(n);
    fo(n){
        re pos[i].ff; re pos[i].sec;
    }
    re m;
    pll x = mp(1,0);
    pll y = mp(1,0);
    vp oper(m);
    fo(m){
        re oper[i].ff;
        if(oper[i].ff == 3 || oper[i].ff == 4){
            re oper[i].sec;
        }
    }
    re q;
    vector<pair<pll,ll> > qry(q);
    fo(q){
        re qry[i].ff.ff; re qry[i].ff.sec;
        qry[i].sec = i;
    }
    sort(qry.begin(),qry.end());
    vp ans(q);
    bool swp = false;
    ll a = 0;
    fo(q){
        ll curop = qry[i].ff.ff;
        ll posn = qry[i].ff.second;
        posn--;
        ll idx = qry[i].sec;
        // cout<<curop<<"()"<<posn<<"\n";
        while(a != curop){
            ll op = oper[a].ff;
            if(op == 1){
                auto temp = x;
                x = y;
                y = temp;
                y.ff *= -1;
                y.sec *= -1;
                swp = !swp;
            }else if(op == 2){
                auto temp = x;
                x = y;
                y = temp;
                x.ff *= -1;
                x.sec *= -1;
                swp = !swp;
            }else if(op == 4){
                ll p = oper[a].sec;
                y.sec = 2*p-y.second;
                y.ff *= -1;
            }else{
                ll p = oper[a].sec;
                x.sec = 2*p-x.sec;
                x.ff *= -1;
            }
            a++;
        }
        ll xp = pos[posn].ff, yp = pos[posn].sec;
        if(swp){
            swap(xp,yp);
        }
        xp *= x.ff; xp += x.sec;
        yp *= y.ff; yp += y.sec;
        ans[idx] = mp(xp,yp);
    }
    for(auto p: ans) cout<<p.ff<<" "<<p.sec<<"\n";
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

/*
1
1 2
4
1
3 3
2
4 2
5
0 1
1 1
2 1
3 1
4 1
*/
