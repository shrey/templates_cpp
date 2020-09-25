

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"

ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

const ll m = 2e5+1;

bool recur(ll mat[][2], ll i, ll j, ll n, bool sid){
    if(j<0 || j>1 || i>(n+1)){
        return false;
    }
    if(i == n+1 && j == 1){
        return true;
    }
    bool a = false;
    if(mat[i][j] == 0 && sid){
        a |= recur(mat,i+1,j,n,true);
    }
    else if(mat[i][j] == 1 && sid){
        a |= recur(mat,i,abs(j-1),n,false);
    }
    else if(mat[i][j] == 1 && !sid){
        a |= recur(mat,i+1,j,n,true);
    }
    return a;
}

int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string r1,r2;
        cin>>r1>>r2;
        ll mat[n+1][2];
        for(int i = 1; i<=n; i++){
            if(r1[i-1] == '1' || r1[i-1] == '2'){
                mat[i][0] = 0;
            }
            else{
                mat[i][0] = 1;
            }
            if(r2[i-1] == '1' || r2[i-1] == '2'){
                mat[i][1] = 0;
            }
            else{
                mat[i][1] = 1;
            }
        }
        if(recur(mat,1,0,n,true)){
            YES;
        }else{
            NO;
        }
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
