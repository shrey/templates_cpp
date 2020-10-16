

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }

}

const ll M = 2e5+1;
ll ans = INT_MIN;


void maxAns(string &s, char ch, ll k){
    ll l = 0, r = 0;
    ll t = 0;
    ll n = s.length();
    while(r<n && l<n){
       if(s[r]!=ch){
           t++;
       }
       while(t>k && l<=r){
           if(s[l]!=ch){
               t--;
           }
           l++;
       }
       ans = max(ans,r-l+1);
       r++;
    }
}

int main(){
    KOBE;
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    maxAns(s,'a',k);
    maxAns(s,'b',k);
    cout<<ans<<"\n";

}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
