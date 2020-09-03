

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

int query(int tree[], int ss, int se, int qs, int qe, int i){ //ss - segment tree start, qs query start
    if(ss >= qs && se <= qe){
        return tree[i];
    }
    if(qe<ss || qs>se){
        return INT_MAX;
    }
    int mid = (ss + se)/2;
    int left = query(tree,ss,mid,qs,qe,2*i);
    int right = query(tree,mid+1,se,qs,qe,2*i+1);
    return min(left,right);
}

void update(int tree[], int ss, int se, int incPos,int incriment, int i){
    if(incPos<ss || incPos>se){
        return;
    }
    if(ss == se && incPos == ss){
        tree[i] += incriment;
        return;
    }
    int mid = (ss + se)/2;
    update(tree,ss,mid,incPos,incriment,2*i);
    update(tree,mid+1,se,incPos,incriment,2*i+1);
    tree[i] = min(tree[2*i], tree[2*i+1]);
    return;
}

void rangeUpdate(int tree[], int ss, int se, int l, int r, int incriment, int i){
    if(l>se || r<ss){
        return;
    }
    if(ss == se){
        tree[i]+=incriment;
        return;
    }
    int mid = (ss+se)/2;
    rangeUpdate(tree,ss,mid,l,r,incriment,2*i);
    rangeUpdate(tree,mid+1,se,l,r,incriment,2*i+1);
    tree[i] = min(tree[2*i],tree[2*i+1]);
    return;
}

int main(){
    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);
    int tree[4*n+1];
    buildTree(a,0,n-1,tree,1);
    // for(int i = 1; i<=13; i++){
    //     cout<<tree[i]<<" ";
    // }
    cout<<query(tree,0,n-1,0,5,1)<<endl;
    update(tree,0,n-1,3,4,1);
    rangeUpdate(tree,0,n-1,0,5,9,1);
    cout<<query(tree,0,n-1,0,5,1)<<endl;

}