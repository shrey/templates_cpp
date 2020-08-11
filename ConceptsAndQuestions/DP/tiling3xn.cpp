

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

int main(){
    int n;
    cin>>n;
    int A[n+1], B[n+1];
    A[0] = 1;
    B[0] = 0;
    B[1] = 1;
    A[1] = 0;
    for(int i = 2; i<=n; i++){
        A[i] = A[i-2] + 2*B[i-1];
        B[i] = A[i-1] + B[i-2];
    }
    cout<<A[n]<<endl;
}