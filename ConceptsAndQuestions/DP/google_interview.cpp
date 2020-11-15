// Given a string A consisting of n characters and a string B consisting of m characters,
//write a function that will return the number of times A must be stated such that B is a substring of the repeated A.
//If B can never be a substring, return -1.



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
    string s1,s2;
    cin>>s1>>s2;
    auto it = s1.find(s2);
    
    cout<<it<<endl;
}