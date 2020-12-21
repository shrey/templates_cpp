

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

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};
ll cleft[] = {0,0,0,1};
ll cr[] = {0,1,0,0};
ll n,m;
const ll M = 2010;
ll x,y,r,c;
ll mat[M][M];
ll distl[M][M] = {0};
ll distr[M][M] = {0};

bool ok(ll x, ll y){
    return (x >=1 && x <= n && y>=0 && y<=m && mat[x][y] == 1);
}

void solve(){
    re n; re m;
    re r; re c;
    re x; re y;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            char ch; re ch;
            mat[i][j] = (ch == '.')? 1 : 0;
            distl[i][j] = 1e15;
            distr[i][j] = 1e15;
        }
    }
    deque<pair<ll,ll> > q;
    distl[r][c] = 0;
    distr[r][c] = 0;
    q.push_front(mp(r,c));
    while(!q.empty()){
        pll cur = q.front();
        // cout<<cur.ff<<"()"<<cur.sec<<"\n";
        q.pop_front();
        fo(4){
            ll x = cur.ff + dx[i];
            ll y = cur.sec + dy[i];
            if(ok(x,y) && distl[cur.ff][cur.sec] + cleft[i] < distl[x][y]){
                distl[x][y] = distl[cur.ff][cur.sec] + cleft[i];
                distr[x][y] = distr[cur.ff][cur.sec] + cr[i];
                if(cleft[i]) q.push_back(mp(x,y));
                else q.push_front(mp(x,y));
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=m; j++){
            if(distl[i][j] <= x && distr[i][j] <= y) ans ++;
        }
    }
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
