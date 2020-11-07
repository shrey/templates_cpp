

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

const ll M = 1010;
ll n,m,sr,sc;
ll mat[M][M];
bool visited[M][M] = {false};

bool ok(ll i, ll j){
    if(i<n && i>=0 && j<m && j>=0 && mat[i][j] == 1 && !visited[i][j]) return true;
    return false;
}

ll dir[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char direc[4] = {'R', 'D', 'L', 'U'};
pair<pll,char> pre[M][M];
ll len[M][M] = {0};
ll inf = 1e9;
ll len_s[M][M] = {0};


void pathpr(ll x, ll y){
    YES;
    pr(len_s[x][y]);
    pll en = mp(x,y);
    pll st = mp(sr,sc);
    string ans = "";
    while(en!=st){
        ans+=pre[en.ff][en.sec].sec;
        en = pre[en.ff][en.sec].ff;
    }
    reverse(ans.begin(),ans.end());
    pr(ans);
}

void solve(){
    re n; re m;
    qp qm;
    forn(i,M)
        forn(j,M) len[i][j] = inf;
    forn(i,n){
        forn(j,m){
            char ch;
            re ch;
            if(ch == '#') mat[i][j] = 0;
            else if(ch == '.') mat[i][j] = 1;
            else if(ch == 'A'){
                mat[i][j] = 1;
                sr = i; sc = j;
            }
            else if(ch == 'M'){
                mat[i][j] = 1;
                qm.push(mp(i,j));
                len[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    while(!qm.empty()){
        pll cur = qm.front();
        qm.pop();
        fo(4){
            ll x1 = cur.ff + dir[i][0];
            ll y1 = cur.sec + dir[i][1];
            if(ok(x1,y1)){
                visited[x1][y1] = true;
                qm.push(mp(x1,y1));
                len[x1][y1] = len[cur.ff][cur.sec] + 1;
            }
        }
    }
    memset(visited,false,sizeof(visited));
    visited[sr][sc] = true;
    qp q;
    q.push(mp(sr,sc));
    while(!q.empty()){
        pll cur = q.front();
        q.pop();
        fo(4){
            ll x1 = cur.ff + dir[i][0];
            ll y1 = cur.sec + dir[i][1];
            if(ok(x1,y1)){
                visited[x1][y1] = true;
                q.push(mp(x1,y1));
                pre[x1][y1] = mp(cur,direc[i]);
                len_s[x1][y1] = len_s[cur.ff][cur.sec] + 1;
            }
        }
    }

    for(ll i = 0; i<n; i++){
        if(visited[i][m-1] && len_s[i][m-1]<len[i][m-1]){
            //print path
            pathpr(i,m-1);
            return;
        }
        if(visited[i][0] && len_s[i][0]<len[i][0]){
            pathpr(i,0);
            return;
        }
    }
    for(ll j = 0; j<m; j++){
        if(visited[0][j] && len_s[0][j]<len[0][j]){
            pathpr(0,j);
            return;
        }
        if(visited[n-1][j] && len_s[n-1][j]<len[n-1][j]){
            pathpr(n-1,j);
            return;
        }
    }
    // pr(len_s[0][1]);
    // pr(len[0][1]);
    pr("NO");
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
