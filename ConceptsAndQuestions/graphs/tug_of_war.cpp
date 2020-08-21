

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

int min_diff = INT_MAX;
vector<int> a;
vector<int> b;

void recur(int arr[], int i, int n, vector<int> &a1, vector<int> &a2, int s1, int s2){



    if(i == n){
            if(abs((int)(a1.size()-a2.size()))<=1){
                if(abs(s1-s2)<min_diff){
                    min_diff = abs(s1-s2);
                    a = a1;
                    b = a2;
                }
            }
        return;
    }

    if(n%2 == 0){
        if(a1.size()>n/2 || a2.size()>n/2){
            return;
        }
    }
    else{
        if(a1.size()>(n+1)/2 || a2.size()>(n+1)/2){
            return;
        }
    }

    a1.pb(arr[i]);
    recur(arr,i+1,n,a1,a2,s1+arr[i],s2);
    a1.pop_back();
    a2.pb(arr[i]);
    recur(arr,i+1,n,a1,a2,s1,s2+arr[i]);
    a2.pop_back();

}

int main(){
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(int);
    vector<int> a1,a2;
    recur(arr,0,n,a1,a2,0,0);
    fo(a.size()){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    fo(b.size()){
        cout<<b[i]<<" ";
    }cout<<endl;
    cout<<min_diff<<endl;
}