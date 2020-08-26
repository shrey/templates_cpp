

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
    int transactions, friends;
    cin>>transactions>>friends;
    int x,y,amt;
    //make 1d array to store net amt each person owes or earns
    int net[100000] = {0};
    fo(transactions){
        cin>>x>>y>>amt;
        net[x]-=amt;
        net[y]+=amt;
    }
    multiset<int> m;
    fo(friends){
        if(net[i]!=0){
            m.insert(net[i]);
        }
    }
    //algorithm
    //pop two people from left and right
    int cnt = 0;
    while(!m.empty()){
        auto left = m.begin();
        auto right = prev(m.end());
        int debit = *left;
        int credit = *right;
        //erase
        m.erase(left);
        m.erase(right);
        //settelment
        int settelment_amt = min(-debit,credit);
        debit+=settelment_amt;
        credit-=settelment_amt;
        if(debit!=0){
            m.insert(debit);
        }
        if(credit!=0){
            m.insert(credit);
        }
        cnt++;
    }
    cout<<cnt<<endl;
}