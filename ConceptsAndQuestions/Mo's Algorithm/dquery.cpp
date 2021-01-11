

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
// typedef long long int;
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
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(int x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<int>
#define vp vector<pair<int,int> >
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
// #define int long long
#define ql queue<int>
#define qp queue<pair<int,int> >
#define endl "\n"
#define nl cout<<"\n"
#define re cin >>
#define pll pair<int,int>
#define FOR(a,b) for(int i = a; i<=b; i++)
#define all(x) x.begin(),x.end()

// int dx[] = {1,0,-1,0};
// int dy[] = {0,1,0,-1};

int mod = 1e9 + 7;

int cl(ld a){
    if(a>(int) a){
        return (int)a+1;
    }
    else{
        return (int)a;
    }
}

int flr(ld a){
    return (int) a;
}



//code starts here

struct node{
    int l,r,ind;
};

int blx = 555;
const int M = 1e6+100;
int freq[M] = {0};

bool compare(node &a, node &b){
    if(a.l/blx == b.l/blx) return a.r < b.r;
    return a.l/blx < b.l/blx;
}

void solve(){
    int n; re n;
    int a[n]; fo(n) re a[i];
    int t; re t;
    node q[t];
    fo(t){
        re q[i].l; re q[i].r; q[i].ind = i;
        q[i].l--; q[i].r--;
    }
    sort(q,q+t,compare);
    int l = 0, r = -1;
    int ans = 0;
    int res[t+1];
    fo(t){
        int cl = q[i].l, cr = q[i].r;
        while(r < cr){
            r++;
            freq[a[r]]++;
            if(freq[a[r]] == 1) ans++;
        }
        while(l > cl){
            l--;
            freq[a[l]]++;
            if(freq[a[l]] == 1) ans++;
        }
        while(l < cl){
            freq[a[l]]--;
            if(freq[a[l]] == 0) ans--;
            l++;
        }
        while(r > cr){
            freq[a[r]]--;
            if(freq[a[r]] == 0) ans--;
            r--;
        }
        res[q[i].ind] = ans;
    }
    fo(t) cout<<res[i]<<"\n";
}

int32_t main(){
    KOBE;
    int t;
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
