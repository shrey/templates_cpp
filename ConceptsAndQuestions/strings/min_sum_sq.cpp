//https://www.geeksforgeeks.org/minimum-sum-squares-characters-counts-given-string-removing-k-characters/



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

struct key{
    char c;
};

int main(){
    string s; int k;
    cin>>s>>k;
    int count[26] = {0};
    priority_queue<int> pq;
    for(int i = 0; i<s.length(); i++){
        count[s[i]-'a']++;
    }
    fo(26){
        if(count[i]>0){
            pq.push(count[i]);
        }
    }
    while(k>0 && !pq.empty()){
        int curr = pq.top();
        curr--;
        pq.pop();
        if(curr>0){
            pq.push(curr);
        }
        k--;
    }
    int ans = 0;
    while(!pq.empty()){
        int t = pq.top();
        pq.pop();
        ans+=(t*t);
    }
    cout<<ans<<endl;
}