

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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

struct Box{
    int h,w,d;
};

void display(Box arr[], int n){
    fo(n){
        cout<<arr[i].h<<" "<<arr[i].w<<" "<<arr[i].d<<endl;
    }
}

bool compare(Box &a, Box &b){
    return ((a.w*a.d)>(b.w*b.d));
}

int main(){
    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(Box);
    Box rot[3*n];
    for(int i = 0; i<n; i++){
        Box b1 = arr[i];
        Box b2,b3;
        b2.h = b1.w;
        b2.w = b1.h;
        b2.d = b1.d;
        b3.h = b1.d;
        b3.w = b1.h;
        b3.d = b1.w;
        rot[3*i] = b1;
        rot[3*i+1] = b2;
        rot[3*i+2] = b3;
    }
    sort(rot,rot+3*n, compare);
    n*=3;
    int lis[n+1];
    for(int i = 0; i<=n; i++){
        lis[i] = rot[i].h;
    }
    int result = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(rot[i].w<rot[j].w && rot[i].d<rot[j].d){
                lis[i] = max(lis[i],lis[j]+rot[i].h);
            }
        }
        result = max(result,lis[i]);
    }
    cout<<result<<endl;
    // display(arr,n);
    // display(rot,3*n);
}