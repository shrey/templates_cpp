//https://www.geeksforgeeks.org/distinct-strings-odd-even-changes-allowed/



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

#define MAX 26

string encodeString(string s){
    int hashOdd[MAX] = {0};
    int hashEven[MAX] = {0};
    string encoded = "";
    for(int i = 0; i<s.length(); i++){
        if(i%2){
            hashOdd[s[i]-'a']++;
        }else{
            hashEven[s[i]-'b']++;
        }
    }
    for(int i = 0; i<26; i++){
        encoded+=to_string(hashOdd[i]);
        encoded+="-";
        encoded+=to_string(hashEven[i]);
        encoded+="-";
    }
    return encoded;
}

int main(){
    string input[] = {"abcd", "acbd", "adcb", "cdba",
                      "bcda", "badc"};
    int n = sizeof(input)/sizeof(string);
    map<string,bool> encodeds;
    int count = 0;
    for(int i = 0; i<n; i++){
        string cur = encodeString(input[i]);
        if(!encodeds[cur]){
            count++;
            encodeds[cur] = true;
        }
    }
    cout<<count<<endl;

}