

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
int modulo = 1e9 + 7;



vector<ll> gr[27];
ll cnum(char ch){
    return (ch-'a'+1);
}
string finalOrder = "";
ll n;
vector<string> s;
bool possible = true;
vector<bool> visited(100, false);
vector<bool> cstack(100,false);

void dfs(ll curr){
    visited[curr] = true;
    cstack[curr] = true;
    for(auto x: gr[curr]){
        if(!visited[x]){
            dfs(x);
        }
        else if(cstack[x]){
            possible = false;
            return;
        }
    }
    finalOrder+=('a'+curr-1);
    cstack[curr] = false;
}

ll k;
umap<ll,vector<string> > pm;

int main(){
    KOBE;
    cin>>n>>k;
    fo(n){
        ll curr;
        cin>>curr;
        fo(k){
            string cur;
            cin>>cur;
            pm[curr].pb(cur);
        }
    }

    fo(1001){
        for(auto str: pm[i]){
            s.pb(str);
        }
    }
    for(int i = 1; i<n; i++){
        string curr = s[i];
        string prev = s[i-1];
        ll j = 0;
        while(j<min(curr.length(),prev.length()) && curr[j] == prev[j]){
            j++;
        }
        if(j<min(curr.length(),prev.length()))
            gr[cnum(curr[j])].pb(cnum(prev[j]));
        else if(prev.length()>curr.length()){
            possible = false;
        }
    }
    for(int i = 1; i<=26; i++){
        if(!visited[i]) dfs(i);
        if(!possible) break;
    }
    if(possible){
        cout<<finalOrder<<"\n";
    }
    else{
        cout<<"Impossible"<<"\n";
    }
}
