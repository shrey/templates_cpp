

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

struct CityPair{
    int a,b;
};

int main(){
    CityPair a[] =  {{8,1},{1,2},{4,3},{3,4},{5,5},{2,6},{6,7},{7,8}};
    int n = sizeof(a)/sizeof(CityPair);
    int lis[n],lds[n];
    fo(n){
        lis[i] = 1; lds[i] = 1;
    }
    int result = 0;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(a[i].a>=a[j].a && a[i].b>=a[j].b){
                lis[i] = max(lis[i],lis[j]+1);
            }
            else if(a[i].a<=a[j].a && a[i].b<=a[j].b){
                lds[i] = max(lds[i],lds[j]+1);
            }
        }
        result = max(result,max(lis[i],lds[i]));
    }
    cout<<result<<endl;
}