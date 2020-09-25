

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

ll k;
string s;

ll solve(){
    ll ans = 0;
    ll p1 = 0, p2 = 0;
    ll n = s.length();

    if(k == 0){
        while(p1<n && p2<n){
            while(p1<n && s[p1]!='0'){
                p1++;
            }
            if(p1 == n) break;
            p2 = p1+1;
            while(p2<n && s[p2] == '0'){
                p2++;
            }
            ll d = p2-p1;
            ans+=(d*(d+1))/2;
            p1 = p2;
        }
        return ans;
    }

    while(s[p1]!='1' && p1<n) p1++;
    if(p1==n) return 0;
    ll curr = 1;
    p2 = p1;
    while(curr<k && p2<n){
        p2++;
        if(s[p2] == '1') curr++;
    }
    if(p2 == n) return 0;
    while(p1<n && p2<n){
        ll l1 = 0, l2 = 0;
        ll i = p1-1, j = p2+1;
        while(i>=0 && s[i] == '0'){
            i--;
        }
        while(j<n && s[j] == '0'){
            j++;
        }
        ans+=(((p1-i)*(j-p2)));
        p1++; p2++;
        while(s[p1]!='1' && p1<n) p1++;
        while(s[p2]!='1' && p2<n) p2++;
    }
    return ans;
}


int main(){
    KOBE;
    cin>>k>>s;
    cout<<solve()<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
