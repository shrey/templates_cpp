

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
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
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

ll n;
const ll M = 310;
ll arr[M];
char mat[M][M];
vl gr[M];
umap<ll,bool> visited;
vl cst;
vl nlist;
void dfs(ll src){
    // cout<<"df"<<endl;
    // cout<<src<<"->";
    visited[src] = true;
    cst.pb(src);
    nlist.pb(arr[src]);
    for(auto x: gr[src]){
        if(!visited[x]) dfs(x);
    }
}


int32_t main(){
    KOBE;
    cin>>n;
    fo(n) cin>>arr[i];
    forn(i,n){
        forn(j,n){
            cin>>mat[i][j];
            if(mat[i][j] == '1'){
                gr[i].pb(j);
                gr[j].pb(i);
            }
        }
    }
    for(ll i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            // cout<<"\n";
            sort(nlist.begin(),nlist.end());
            sort(cst.begin(),cst.end());
            fo(cst.size()){
                arr[cst[i]] = nlist[i];
            }
            cst.clear();
            nlist.clear();
        }
    }
    fo(n) cout<<arr[i]<<" ";cout<<"\n";
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
