

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
    int ugly[] = {2, 3,5};
    int size = sizeof(ugly)/sizeof(int);
    priority_queue<int,vector<int>,greater<int> > pq;
    fo(size){
        pq.push(ugly[i]);
    }
    int n = 1000;
    int count = 1, curr;
    while(count<n){
        curr = pq.top();
        pq.pop();
        if(curr!=pq.top()){
            count++;
            fo(size){
                pq.push(curr*ugly[i]);
            }
        }
    }
    cout<<curr<<endl;

}
