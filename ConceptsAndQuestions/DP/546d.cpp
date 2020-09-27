

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

const ll M = 5e6+1;

bool prime[M] = {false};
ll prime_fact_cnt[M] = {0};
ll fact[M] = {0};
void prime_seive(){
    fo(M) prime[i] = true;
    for(int p = 2; p*p<M; p++){
        if(prime[p] == true){
            for(int i = p*p; i<M; i+=p){
                prime[i] = false;
                if(!fact[i]) fact[i] = p;
            }
        }
    }
}

void compute(){
    prime_fact_cnt[1] = 0;
    for(ll i = 2; i<M; i++){
        if(prime[i]){
            prime_fact_cnt[i] = 1;
        }
        else{
            prime_fact_cnt[i] = prime_fact_cnt[i/fact[i]]+1;
        }
    }
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    prime_seive();
    compute();

    fact[1] = 0;
    for(ll i = 2; i<M; i++){
        fact[i] = fact[i-1]+prime_fact_cnt[i];
    }
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<fact[a]-fact[b]<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs