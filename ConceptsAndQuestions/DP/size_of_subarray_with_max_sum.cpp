

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
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(int);
    int currSum = 0;
    int maxSum = 0;
    int diff = 0;
    int st = -1;
    for(int i = 0; i<n; i++){
        currSum+=a[i];
        // cout<<currSum<<" ";
        if(currSum<0){
            st = i;
            currSum = 0;
        }
        else{
            if(currSum>maxSum){
                diff = max(diff,(i-st));
                cout<<i<<" "<<st<<endl;
                maxSum = currSum;
            }
        }
    }
    cout<<diff<<endl;

}