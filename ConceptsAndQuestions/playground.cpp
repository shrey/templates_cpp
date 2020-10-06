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
#define fo(n) for(int i = 0; i<n; i++)
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
ll gval = 10;
class idea{
	int len,wid;
	static int stat;
	public:
		idea(){
			cout<<"Def"<<"\n";
		}
		idea(ll a, ll b = 5){
			len = wid = a;
			pr(1);
		}
		idea(ll a){
			pr(2);
		}
		idea(idea &i){
			len+=i.len;
		}
		void disp(){
			cout<<len<<wid<<"\n";
		}
};

void display(const int c1 = 5){
	ll arr[c1];
	fo(c1) arr[i] = 0;
	fo(c1) cout<<arr[i];
}

int main()
{
    // idea i;
	// idea i2(2,3);
	// i = i2;
	// i.disp();
	// i2.disp();
	// int gval = 68;
	// cout<<gval<<::gval<<"\n";
	// {
	// 	cout<<"hery"<<"\n";
	// }
	// display(6);
	// ll n;
	// cin>>n;

	// while(n>0){

	// switch(n){
	// 	default:
	// 		cout<<"exit"<<"\n";
	// 	case 1:
	// 	continue;
	// 	case 2:
	// 	case 3:
	// 	break;
	// }
	// n--;
	// }
	cout<<sqrt(7)<<"\n";

}