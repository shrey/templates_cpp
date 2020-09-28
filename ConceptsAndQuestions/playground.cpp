#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pr(t) cout<<t<<"\n"

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

ll getAdd(ll x) {
	ll m1 = 10, m2 = 0;
	while(x > 0) {
		ll y = x % 10;
		x /= 10;
		m1 = min(m1, y);
		m2 = max(m2, y);
	}
	return m1 * m2;
}

class idea{
	public:
		idea(ll a, ll b = 5){
			pr(1);
		}
		idea(ll a){
			pr(2);
		}
};

int main()
{
    // string s1, s2;
	// cin>>s1>>s2;
	// if(s1>s2){
	// 	cout<<"s1"<<"\n";
	// }
	// else{
	// 	cout<<"s2"<<"\n";
	// }
	idea a(1,2);

}