

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
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

int32_t main(){
    int tc;
	scanf("%d", &tc);
	forn(_, tc){
		int h, c, t;
		scanf("%d%d%d", &h, &c, &t);
		if (h + c - 2 * t >= 0)
			puts("2");
		else{
			int a = h - t;
			int b = 2 * t - c - h;
			int k = 2 * (a / b) + 1;
			long long val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
			long long val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));
			printf("%d\n", val1 * (k + 2) <= val2 * k ? k : k + 2);
		}
	}
	return 0;
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
