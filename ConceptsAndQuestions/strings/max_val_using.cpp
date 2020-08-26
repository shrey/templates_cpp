//https://www.geeksforgeeks.org/calculate-maximum-value-using-sign-two-numbers-string/


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

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int currVal = s[0]-'0';
    for(int i = 1; i<n; i++){
        int num = s[i]-'0';
        currVal = max(currVal+num,currVal*num);
    }
    cout<<currVal<<endl;
}