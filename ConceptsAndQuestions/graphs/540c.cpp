

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

ll n,m,r1,c1,r2,c2;

const ll M = 510;
char mat[M][M];
bool visited[M][M] = {false};

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};

bool ok(ll x, ll y){
    if(x >= 1 && y >= 1 && x <=n && y<= m && mat[x][y] == '.' && !visited[x][y]) return true;
    return false;
}


bool exists(){
    qp q;
    q.push(mp(r1,c1));
    visited[r1][c1] = true;
    while(!q.empty()){
        pll cur = q.front();
        q.pop();
        fo(4){
            ll x = cur.ff + dx[i], y = cur.sec + dy[i];
            if(x == r2 && y == c2) return true;
            if(ok(x,y)){
                q.push(mp(x,y));
                visited[x][y] = true;
            }
        }
    }
    return false;
}

bool is_neighbour(){
    if(abs(r1 - r2) + abs(c1 - c2) == 1) return true;
    return false;
}

void solve(){
    re n; re m;
    forn(i,n){
        forn(j,m){
            re mat[i+1][j+1];
        }
    }
    re r1; re c1; re r2; re c2;
    if(exists()){
        if(mat[r2][c2] == '.'){
            ll cnt = 0;
            fo(4){
                ll x = r2 + dx[i], y = c2 + dy[i];
                if(x >= 1 && y>= 1 && x<=n && y<=m && mat[x][y] == '.') cnt++;
            }
            if(cnt >= 2 || (is_neighbour() && cnt >=1)){
                YES;
            }else{
                NO;
            }
        }
        else{
            YES;
        }
    }
    else NO;
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
