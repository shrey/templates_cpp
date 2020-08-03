

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


bool is_possible(int n, int m, int x, int y, int curr){
    int total_give = curr*x;
    int total_take = (n-curr)*y + m;
    if(total_take>=total_give){
        return true;
    }
    else{
        return false;
    }
}

int max_people(int n, int m, int x, int y){
    int s = 0;
    int e = n;
    int ans = 0;
    while(s<=e){
        int mid = (s+e)/2;

        if(is_possible(n,m,x,y,mid)){
            // cout<<mid<<endl;
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    cout<<max_people(n,m,x,y)<<endl;
}