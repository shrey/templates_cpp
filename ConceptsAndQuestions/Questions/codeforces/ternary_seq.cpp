

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

int main(){
    int t;
    cin>>t;
    int x1,y1,z1,x2,y2,z2;
    while(t--){
        cin>>x1>>y1>>z1;
        cin>>x2>>y2>>z2;
        int ans = 0;
        ans+=min(z1,y2)*2;
        z1-=y2;
        if(z1>0){
            z2-=z1;
        }
        z2-=x1;
        if(z2>0){
            ans-=2*z2;
        }
        cout<<ans<<"\n";
    }
}