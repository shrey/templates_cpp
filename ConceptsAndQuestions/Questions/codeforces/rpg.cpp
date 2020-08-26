

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
    int p,f,cntw,cnts,s,w;
    while(t--){
        cin>>p>>f>>cnts>>cntw>>s>>w;
        int p1 = p, f1 = f;
        int max_ans = 0;
        for(int i = 0; i<=cnts; i++){
            p1 = p; f1 = f;
            if((s*i)<=p1){
                p1-=(s*i);
                int j = p1/w;
                if(j>cntw) j = cntw;

                int i1 = 0, j1 = 0;
                if(s<w){
                    i1+=(f1/s);
                    if(i1>(cnts-i)) i1 = cnts-i;
                    f1-=(i1*s);
                    j1+=(f1/w);
                    if(j1>(cntw-j)) j1 = cntw-j;
                    f1-=(j1*w);
                }else{
                    j1+=(f1/w);
                    if(j1>(cntw-j)) j1 = cntw-j;
                    f1-=(j1*w);
                    i1+=(f1/s);
                    if(i1>(cnts-i)) i1 = cnts-i;
                    f1-=(i1*s);
                }
                int ans = i + j + i1 + j1;
                max_ans = max(ans, max_ans);

            }else{
                break;
            }
        }
        cout<<max_ans<<"\n";
    }
}