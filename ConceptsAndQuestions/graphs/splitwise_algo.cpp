



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
#define int long long
#define ld long double

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;


bool f(ld a, ld b)
{
    if (abs(a - b) < 1e-9) {
        return true;
    }
    else {
        return false;
    }
}


int32_t main(){
    int transactions;
    cin>>transactions;
    map<ll,ld> net;
    int x,y;
    ld amt;
    //make 1d array to store net amt each person owes or earns
    fo(transactions){
        cin>>x>>y>>amt;
        string s;
        cin>>s;
        if(s[0] == 'E'){
            amt *= 1.18;
        }else if(s[0] == 'R'){
            amt *= 0.013;
        }
        amt *= 1000000;
        net[x]-=(amt);
        net[y]+=(amt);
    }
    // for(auto x: net){
    //     cout<<x.first<<" = "<<x.second<<"\n";
    // }
    multiset<ll> m;
    for(auto x: net){
        m.insert(x.second);
    }
    //algorithm
    //pop two people from left and right
    int cnt = 0;
    while(!m.empty()){
        auto left = m.begin();
        auto right = prev(m.end());
        ll debit = *left;
        ll credit = *right;
        // cout<<debit<<"()"<<credit<<"()"<<m.size()<<"\n";
        //erase
        m.erase(left);
        m.erase(right);
        //settelment
        ll settelment_amt = min(-debit,credit);
        debit+=settelment_amt;
        credit-=settelment_amt;
        // cout<<debit<<"()"<<credit<<"\n";
        if(abs(debit) > 10){
            m.insert(debit);
        }
        else if(abs(credit) > 10){
            m.insert(credit);
        }
        cnt++;
    }
    cout<<cnt<<endl;

}