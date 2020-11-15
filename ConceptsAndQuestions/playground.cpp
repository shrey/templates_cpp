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
#include<array>
#include<cstring>

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
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"
#define int long long
#define re cin>>

ll mod = 1e9 + 7;
const ll M = 1e6+100;

int minPatches(vector<int>& nums, int n) {
        if(n==0)
            return 0;
        int ans = 0;
        long curr = 0;
        for(int& u: nums)
        {
            if(curr>=n)
                break;
            while(curr+1<u and curr<n)
            {
                ans++;
                curr += curr + 1;
            }
            curr += u;
        }
        while(curr<n)
        {
            curr += curr+1;
            ans++;
        }
        return ans;
    }

int32_t main(){
   const ll M = 2e6;
   vector<array<ll,2> > e(2);
   cin>>e[0][0];
   cout<<e[0][0]<<"\n";
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