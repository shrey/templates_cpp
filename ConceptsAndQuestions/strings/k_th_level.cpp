

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

int solve(string s, int k){
    int level = -1;
    int ans = 1;
    fo(s.length()){
        if(s[i] == '('){
            level++;
        }
        else if(s[i] == ')'){
            if(level) level--;
        }
        else{
            if(level == k){
                ans*=(s[i]-'0');
            }
        }
    }
    return ans;
}

int main(){
    string s; int k;
    s = "(8(3(2()())(6(5()())()))(5(10()())(7(13()())())))";
    cin>>k;
    cout<<solve(s,k)<<endl;

}