

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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

ll q(ll x, ll y){
    cout<<"? "<<x<<" "<<y<<endl;
    int ans;
    cin>>ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll x = 1, y = 2;
    umap<int,bool> counted;
    int ans[n+1];
    fo(n+1) ans[i] = 0;
    while(x<=n && y<=n){
        int val1 = q(x,y);
        int val2 = q(y,x);
        if(val1<val2){
            ans[y] = val2;
            counted[val2] = true;
            y++;
        }
        else{
            ans[x] = val1;
            counted[val1] = true;
            x = y;
            y++;
        }
    }
    int l;
    for(int i = 1; i<=n; i++){
        if(!counted[i]){
            l = i;
            break;
        }
    }
    for(int i = 1; i<=n; i++){
        if(ans[i] == 0){
            ans[i] = l;
            break;
        }
    }
    cout<<"! ";
    for(int i = 1; i<=n; i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}
