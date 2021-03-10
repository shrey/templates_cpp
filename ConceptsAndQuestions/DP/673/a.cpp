

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

ll mat[100][100] = {0};

ll dx[] = {1,0,-1,0,1,1,-1,-1};
ll dy[] = {0,1,0,-1,1,-1,1,-1};

bool ok(ll x, ll y){
    if(x > 0 && x <= 8 && y > 0 && y <= 8) return true;
    return false;
}

void solve(){
    string k,n;
    re k; re n;
    ll n1 = n[0] - 'a' + 1, n2 = n[1] - '0';
    ll k1 = k[0] - 'a' + 1, k2 = k[1] - '0';

    bool flag = false;
    mat[n1][n2] = 5, mat[k1][k2] = 5;
    fo(8) if(n1 + dx[i] == k1 && n2 + dy[i] == k2) flag = true;
    fo(8){
        ll x = k1 + dx[i], y = k2 + dy[i];
        mat[x][y] = 1;
        if(flag && mat[n1+dx[i]][n2+dy[i]] == 0) mat[n1 + dx[i]][n2+dy[i]] = 3;
    }

    for(ll i = 1; i<=8; i++){
        if(mat[n1][i] == 0) mat[n1][i] = 2;
        if(mat[i][n2] == 0) mat[i][n2] = 2;
        if(mat[n1+i][n2+i] == 0) mat[n1+i][n2+i] = 2;
        if(n1 >= i && mat[n1-i][n2+i] == 0) mat[n1-i][n2+i] = 2;
        if(n1 >= i && n2 >= i && mat[n1-i][n2-i] == 0) mat[n1-i][n2-i] = 2;
        if(n2 >= i && mat[n1+i][n2-i] == 0) mat[n1+i][n2-i] = 2;
    }
    if(n1+2<10&&n2-1>=0 && mat[n1+2][n2-1] == 0){
        mat[n1+2][n2-1]=2;
    }

    if(n1+2<10&&n2+1<10 && mat[n1+2][n2+1] == 0){
        mat[n1+2][n2+1]=2;
    }

    if(n1-2>=0&&n2-1>=0 && mat[n1-2][n2-1] == 0){
        mat[n1-2][n2-1]=2;
    }

    if(n1-2>=0&&n2+1<10 && mat[n1-2][n2+1] == 0){
        mat[n1-2][n2+1]=2;
    }

    if(n1+1<10&&n2-2>=0 && mat[n1+1][n2-2] == 0){
        mat[n1+1][n2-2]=2;
    }

    if(n1+1<10&&n2+2<10 && mat[n1+1][n2+2] == 0){
        mat[n1+1][n2+2]=2;
    }

    if(n1-1>=0&&n2-2>=0 && mat[n1-1][n2-2] == 0){
        mat[n1-1][n2-2]=2;
    }

    if(n1-1>=0&&n2+2<10 && mat[n1+1][n2+2] == 0){
        mat[n1-1][n2+2]=2;
    }
    ll a = 0, b = 0, c = 0, d = 0;
    for(ll i = 1; i<=8; i++){
        for(ll j = 1; j<=8; j++){
            if(mat[i][j] == 2) b++;
            else if(mat[i][j] == 3) a++;
            else if(mat[i][j] == 0){
                bool f = false;
                forn(k,8){
                    ll x = i + dx[k], y = j + dy[k];
                    if(ok(x,y) && mat[x][y] == 0) {f = true; break;}
                }
                if(f)   d++;
                else    c++;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";

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

//d3 e4

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
