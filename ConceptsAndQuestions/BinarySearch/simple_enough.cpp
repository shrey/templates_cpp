

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

int ans = 0;

int calcRange(int n){
    int t = 0;
    while(n){
        t++;
        n = n>>1;
    }
    return ((1<<t)-2);

}

int compute(int n, int st, int end, int l, int r){
    if(st>end){
        return 0;
    }
    if(st>r || end<l){
        return 0;
    }
    if(n == 0 || n == 1){
        if(n == 1) return 1;
        return 0;
    }
    int mid = (st+end)/2;
    int left = compute(n/2,st,mid-1,l,r);
    int right = compute(n/2,mid+1,end,l,r);
    if(mid>=l && mid<=r && (n%2) == 1){
        return left+right+1;
    }
    return left+right;
}

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    int s = 0, e = calcRange(n);
    cout<<compute(n,s,e,l-1,r-1)<<endl;
}