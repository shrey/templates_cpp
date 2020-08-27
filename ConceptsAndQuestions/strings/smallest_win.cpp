//https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/



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

void solve(string s1, string s2){
    umap<char,int> s2map;
    umap<char,int> s1map;
    fo(s2.length()){
        s2map[s2[i]]++;
    }
    fo(s1.length()){
        s1map[s1[i]]++;
    }
    fo(s2.length()){
        if(s2map[s2[i]]>s1map[s2[i]]){
            cout<<"NOT POSSIBLE"<<endl;
            return;
        }
    }
    int fs = 0, fe = s1.length()-1;
    int minLen = INT_MAX;
    for(int i = 0; i<s1.length(); i++){
        int start = i;
        int end = s1.length()-1;
        auto c1map = s1map;
        while(c1map[s1[end]]>s2map[s1[end]] && end>=i){
            c1map[s1[end]]--;
            end--;
        }
        int len = end-start+1;
        if(len<minLen){
            minLen = len;
            fs = start;
            fe = end;
        }
        if(s1map[s1[i]]<=s2map[s1[i]]){
            break;
        }
        s1map[s1[i]]--;
    }
    cout<<fs<<fe<<endl;
    cout<<s1.substr(fs,(fe-fs+1))<<endl;
}

int main(){
    string s1,s2;
    s1 = "this is a test string";
    s2 = "tist";
    solve(s1,s2);



}