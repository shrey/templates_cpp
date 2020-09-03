

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

void buildTree(int a[], int s, int e, int tree[], int i){
    if(s == e){
        tree[i] = a[s];
        return;
    }
    int mid = (s+e)/2;
    buildTree(a,s,mid,tree,2*i);
    buildTree(a,mid+1,e,tree,2*i+1);
    tree[i] = min(tree[2*i],tree[2*i+1]);
    return;
}

int main(){
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);
    int tree[4*n+1];
    buildTree(a,0,n-1,tree,1);
    for(int i = 1; i<=13; i++){
        cout<<tree[i]<<" ";
    }cout<<endl;
}