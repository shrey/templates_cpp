

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

ll n,m,k;
const ll M = 2001;
string ans = "";
char mat[M][M];
ll x,y;
ll ox,oy;
ll dist[M][M];
bool vis[M][M] = {0};
ll dx[] = {1,0,0,-1};
ll dy[] = {0,-1,1,0};
char dir[] = {'D','L','R','U'};
//DLRU

bool ok(ll i, ll j){
    if(i>=0 && i<n && j>=0 && j<m && mat[i][j] == '.'){
        return true;
    }
    return false;
}


void bfs(){
    forn(i,M){
        forn(j,M){
            dist[i][j] = lmax;
            vis[i][j] = false;
        }
    }
    queue<pair<ll,ll> > q;
    dist[ox][oy] = 0;
    vis[ox][oy] = true;
    q.push(mp(ox,oy));
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // cout<<cur.ff<<"(=)"<<cur.sec<<"\n";
        for(ll i = 0; i<4; i++){
            ll tx = cur.ff + dx[i];
            ll ty = cur.sec + dy[i];
            if(ok(tx,ty) && !vis[tx][ty]){
                dist[tx][ty] = dist[cur.ff][cur.sec]+1;
                vis[tx][ty] = true;
                q.push(mp(tx,ty));
            }
        }
    }

}

void solve(){
    bfs();
    if(k%2){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    while(k){
        bool flag = false;
        // cout<<x<<"()"<<y<<"\n";
        fo(4){
            ll tx = x+dx[i];
            ll ty = y+dy[i];
            if(ok(tx,ty) && dist[tx][ty]<=k){
                ans+=dir[i];
                x = tx;
                y = ty;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<"IMPOSSIBLE\n";
            return;
        }
        k--;
    }

    cout<<ans<<endl;
}

int32_t main(){
    KOBE;
    cin>>n>>m>>k;
    forn(i,n){
        forn(j,m){
            cin>>mat[i][j];
            if(mat[i][j] == 'X'){
                x = i; y = j;
            }
        }
    }
    mat[x][y] = '.';
    ox = x; oy = y;
    solve();
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