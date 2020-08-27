

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

int nmb(char ch){
    return (ch-'0');
}

string sumStr(string s1, string s2){
    if(s1.length()>s2.length()){
        swap(s1,s2);
    }
    int n = s1.length();
    int m = s2.length();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    string ans = "";
    int carry = 0;
    for(int i = 0; i<n; i++){
        int num = nmb(s1[i]) + nmb(s2[i]) + carry;
        ans+=to_string(num%10);
        carry = num/=10;
    }
    for(int i = n; i<m; i++){
        int num = (nmb(s2[i]) + carry);
        ans+=to_string(num%10);
        carry = num/10;
    }
    if(carry){
        ans+=to_string(carry);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string multiplyStrings(string s, char ch){
    int dig = nmb(ch);
    string ans = "";
    reverse(s.begin(),s.end());
    int carry = 0;
    for(int i = 0; i<s.length(); i++){
        int num = (carry+(dig*nmb(s[i])));
        ans+=(to_string(num%10));
        carry = num/10;
    }
    if(carry) ans+=to_string(carry);
    reverse(ans.begin(),ans.end());
    return ans;

}

string solve(string s1, string s2){
    if(s1.length()>s2.length()){
        swap(s1,s2);
    }
    int n = s1.length();
    string ans = multiplyStrings(s2,s1[0]);
    ans+='0';
    for(int i = 1; i<n; i++){
        ans = sumStr(ans,multiplyStrings(s2,s1[i]));
        ans+='0';
    }
    ans.pop_back();
    return ans;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<solve(s1,s2)<<endl;

}