

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
#define all(x) x.begin(),x.end()

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

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
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

//code starts here

ll n,k;
string s;

void solve(){
    re n; re k; re s;
    if(n%k){
        pr(-1);
        return;
    }
    ll freq[26] = {0};
    fo(n) freq[s[i]-'a']++;
    bool flag = true;
    fo(26) if(freq[i]%k){
        flag = false;
        break;
    }
    if(flag){
        pr(s);
        return;
    }
    for(ll i = n-1; i>=0; i--){
        freq[s[i]-'a']--;
        ll cur = 0;
        forn(j,26){
            if(freq[j]%k) cur += (k - freq[j]%k);
        }
        // cout<<i<<"()"<<cur<<"\n";
        ll len = n-i-1;
        if(len + 1 == cur){
            for(ll j = s[i]-'a'+1; j<26; j++){
                if(freq[j]%k){
                    freq[j]++;
                    string res = s.substr(0,i);
                    res += ('a'+j);
                    string lft = "";
                    for(ll p = 0; p<26; p++){
                        if(freq[p]%k){
                            forn(l,k-freq[p]%k) lft += 'a'+p;
                        }
                    }
                    sort(all(lft));
                    res += lft;
                    pr(res);
                    return;
                }
            }
        }else if((len+1 > cur) && (len+1-cur)%k == 0){
            if(s[i]-'a' == 25) continue;
            string res = s.substr(0,i);
            res += s[i]+1;
            freq[s[i]-'a'+1]++;
            string lft = "";
            for(ll j = 0; j<26; j++){
                if(freq[j]%k){
                    forn(p,k-freq[j]%k) lft += 'a'+j;
                }
            }
            while(lft.length() < len) lft += 'a';
            sort(all(lft));
            res += lft;
            pr(res);
            return;
        }
    }
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
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
