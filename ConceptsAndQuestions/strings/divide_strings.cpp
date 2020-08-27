

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

string divide(string s, int n){
    string ans = "";
    int rem = 0;
    for(int i = 0; i<s.length(); i++){
        int x = s[i]-'0';
        int curr = rem*10+x;
        ans+=to_string(curr/n);
        rem = curr%n;
    }
    int i = 0;
    while(ans[i] == '0'){
        i++;
    }
    ans = ans.substr(i);
    return ans;

}

int main(){
    string s; int n;
    cin>>s>>n;
    cout<<divide(s,n)<<endl;
}