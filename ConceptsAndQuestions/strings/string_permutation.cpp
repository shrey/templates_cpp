

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

void permutations(string s, int i){
    if(i == s.length()){
        cout<<s<<endl;
    }

    for(int j = i; j<s.length(); j++){
        swap(s[i],s[j]);
        permutations(s,i+1);
        swap(s[i],s[j]);
    }
}

int main(){
    string s;
    cin>>s;
    permutations(s,0);
}