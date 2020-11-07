

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
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)

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

ll nmb(char ch){
    return ch-'0';
}

bool comp(string s1,string s2){
    if(s1.length()<s2.length()){
        return true;
    }
    if(s1.length()>s2.length()){
        return false;
    }
    return (s1<s2);
}

string sumStr(string s1, string s2){
    if(s1.length()>s2.length()){
        swap(s1,s2);
    }
    int n = s1.length();
    int m = s2.length();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    string ans = "";
    int carry = 0;
    for(int i = 0; i<n; i++){
        int num = nmb(s1[i]) + nmb(s2[i]) + carry;
        ans+=('0' + (num%10));
        carry = num/=10;
    }
    for(int i = n; i<m; i++){
        int num = (nmb(s2[i]) + carry);
        ans+= ('0' + (num%10));
        carry = num/10;
    }
    if(carry){
        ans+=('0' + carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string num;
ll n;

void solve(){
    re n;
    re num;
    if(num[n/2]!='0'){
        if(n%2 == 0){
            string ans = sumStr(num.substr(0,n/2),num.substr(n/2,n/2));
            pr(ans);
            return;
        }
        else{
            if(num[n/2+1] == '0'){
                string ans = sumStr(num.substr(0,n/2),num.substr(n/2,n/2));
                pr(ans);
                return;
            }
            else{
                string s1 = sumStr(num.substr(0,n/2),num.substr(n/2,n/2+1));
                string s2 = sumStr(num.substr(0,n/2+1),num.substr(n/2+1,n/2));
                // cout<<s1<<"()"<<s2<<"\n";
                if(comp(s1,s2)){
                    pr(s1);
                    return;
                }
                else{
                    pr(s2);
                    return;
                }
            }
        }
    }
    else{
        string s1,s2;
        ll l = n/2;
        while(l>=0 && num[l] == '0') l--;
        ll r = n/2;
        while(r<n && num[r] == '0') r++;
        if(l == -1){
            string ans = num.substr(r,n-r);
            pr(ans);
            return;
        }
        if(r == n){
            string ans = sumStr(num.substr(l,n-l),num.substr(0,l));
            pr(ans);
            return;
        }
        s1 = sumStr(num.substr(0,r),num.substr(r,n-r));
        s2 = sumStr(num.substr(l,n-l),num.substr(0,l));
        // cout<<s1<<"()"<<s2<<"\n";
        if(comp(s1,s2)){
            pr(s1);
            return;
        }
        else{
            pr(s2);
            return;
        }
    }
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
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
