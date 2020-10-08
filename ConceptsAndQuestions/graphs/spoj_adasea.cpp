

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

ll n,m;
const ll M = 1010;
ll mat[M][M];
ll visited[M][M] = {0};

bool ok(ll i, ll j){
    if(i>=0 && i<n && j>=0 && j<m && mat[i][j] == 1 && !visited[i][j]){
        return true;
    }
    return false;
}

ll dfs(ll i, ll j){
    visited[i][j] = true;
    ll ans = 1;
    if(ok(i+1,j)){
        ans+=dfs(i+1,j);
    }
    if(ok(i-1,j)){
        ans+=dfs(i-1,j);
    }
    if(ok(i,j+1)){
        ans+=dfs(i,j+1);
    }
    if(ok(i,j-1)){
        ans+=dfs(i,j-1);
    }
    return ans;
}

void comp(ll a, ll b){
    if(b%a == 0){
        cout<<b/a<<"\n";
        return;
    }
    for(ll i = 2; i<=min(a,b); i++){
        while(a%i == 0 && b%i == 0){
            a/=i; b/=i;
        }
    }
    cout<<b<<" / "<<a<<"\n";
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll d = n*m;
        ll num = 0;
        forn(i,n){
            forn(j,m){
                char ch;
                cin>>ch;
                if(ch == '~') mat[i][j] = 0;
                else mat[i][j] = 1;
            }
        }
        forn(i,n){
            forn(j,m){
                if(!visited[i][j] && mat[i][j] == 1){
                    ll sz = dfs(i,j);
                    num+=(sz*sz);
                }
            }
        }
        comp(d,num);
        forn(i,M){
            forn(j,M){
                visited[i][j] = 0;
            }
        }
    }
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
