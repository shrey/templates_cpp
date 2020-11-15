

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

string substractString(string s1, string s2){
    if(s1.length()>s2.length()){
        swap(s1,s2);
    }
    else if(s1.length() == s2.length()){
        for(int i = 0; i<s1.length(); i++){
            if(s1[i]>s2[i]){
                swap(s1,s2);
                break;
            }
        }
    }
    int n = s1.length();
    int m = s2.length();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string ans = "";
    int carry;
    for(int i = 0; i<n; i++){
        int n2 = (s2[i]-'0')  - carry;
        int n1 = s1[i]-'0';
        carry = 0;
        if(n1>n2){
            carry = 1;
            n2+=10;
        }
        ans+=to_string(n2-n1);
    }
    for(int i = n; i<m; i++){
        int num = s2[i]-'0';
        num = num-carry;
        ans+=to_string(num);
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<substractString(s1,s2)<<endl;

}