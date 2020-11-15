
//https://www.geeksforgeeks.org/maximum-subsequence-sum-such-that-no-three-are-consecutive/

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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/sizeof(int);
    if(n == 1){
        return arr[0];
    }
    else if(n == 2){
        return arr[0] + arr[1];
    }
    int one[n], two[n], zero[n];
    one[1] = arr[1];
    two[1] = arr[1]+arr[0];
    zero[1] = arr[0];
    for(int i = 2; i<n; i++){
        zero[i] = max(two[i-1],one[i-1]);
        one[i] = zero[i-1]+arr[i];
        two[i] = one[i-1] + arr[i];
    }
    cout<<max(zero[n-1],max(one[n-1],two[n-1]))<<endl;
}

//this can also be followed if wanted

// sum[i] = max(sum[i-1], sum[i-2] + arr[i],
//              sum[i-3] + arr[i] + arr[i-1])