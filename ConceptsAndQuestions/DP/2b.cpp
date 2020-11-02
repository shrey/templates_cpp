

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
#define re(x) cin>>x

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
ll n, mat[M][M];
ll dp2[M][M], dp5[M][M], dp[M][M];

ll mx = 1e13;


ll comp(ll num,ll fact){
    ll ans = 0;
    while(num > 0 && num%fact == 0){
        ans++;
        num/=fact;
    }
    return ans;
}


ll recur(ll i, ll j, ll fact){
    if(i>n || j>n){
        return imax;
    }
    // cout<<i<<"()"<<j<<"\n";
    if(dp2[i][j]!=-1){
        return dp2[i][j];
    }
    if(i == n && j == n){
        dp2[i][j] = comp(mat[i][j],fact);
        return dp2[i][j];
    }
    dp2[i][j] = comp(mat[i][j],fact) + min(recur(i+1,j,fact),recur(i,j+1,fact));
    return dp2[i][j];
}

ll recur2(ll i, ll j, ll fact){
    if(i>n || j>n){
        return imax;
    }
    // cout<<i<<"()"<<j<<"\n";
    if(dp5[i][j]!=-1){
        return dp5[i][j];
    }
    if(i == n && j == n){
        dp5[i][j] = comp(mat[i][j],fact);
        return dp5[i][j];
    }
    dp5[i][j] = comp(mat[i][j],fact) + min(recur2(i+1,j,fact),recur2(i,j+1,fact));
    return dp5[i][j];
}

string str = "";

void op(ll i, ll j){
    if(i>n || j>n) return;
    if(i == n && j ==n) return;
    if(i == n){
        str+='R';
        op(i,j+1);
    }
    else if(j == n){
        str+='D';
        op(i+1,j);
    }
    else{
        if(dp[i+1][j]<dp[i][j+1]){
            str+='D';
            op(i+1,j);
        }
        else{
            str+='R';
            op(i,j+1);
        }
    }
}

void solve(){
    memset(dp2,-1,sizeof(dp2));
    memset(dp5,-1,sizeof(dp5));
    recur(1,1,2); recur2(1,1,5);
    ll ans = min(dp2[1][1],dp5[1][1]);
    bool zr = false;
    ll a,b;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1;j <=n; j++){
            if(mat[i][j] == 0){
                a = i, b = j;
                zr = true;
            }
        }
    }
    if(ans>1 && zr){
        pr(1);
        fo(a-1)cout<<"D";
        fo(b-1)cout<<"R";
        fo(n-a)cout<<"D";
        fo(n-b)cout<<"R";
        return;
    }
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n;j++){
            dp[i][j] = min(dp2[i][j],dp5[i][j]);
        }
    }
    pr(ans);
    op(1,1);
    pr(str);
}

int32_t main(){
    KOBE;
    cin>>n;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n; j++){
            cin>>mat[i][j];
        }
    }
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
