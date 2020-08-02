

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
#define fo(x,y) for(int i = x; i<y; i++)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

//here, the monotonic search space is 0 to n 🚀

int square_root(int n){
    int s = 0;
    int ans = -1;
    int e = n;
    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid == n){
            return mid;
        }
        if(mid*mid<n){
            if(mid>ans) ans = mid;
            s = mid+1;
        }
        if(mid*mid>n){
            e = mid-1;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    cout<<square_root(n)<<endl;
}