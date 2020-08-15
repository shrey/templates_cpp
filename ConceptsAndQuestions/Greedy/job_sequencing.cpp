//https://www.geeksforgeeks.org/job-sequencing-problem/

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


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

struct Job{
    char id;
    int dead;
    int profit;
};

bool compare(Job a, Job b){
    return (a.profit>b.profit);
}

void printSeq(Job arr[], int n){
    sort(arr,arr+n,compare);
    umap<int,bool> slots;
    vector<char> taken;
    for(int i = 0; i<n; i++){
        int deadline = arr[i].dead;
        bool possible = false;
        while(deadline>=1 && slots[deadline]){
            deadline--;
        }
        if(deadline>=1){
            slots[deadline] = true;
            taken.pb(arr[i].id);
        }

    }
    for(int i = 0; i<taken.size(); i++){
        cout<<taken[i]<<" , ";
    }cout<<endl;

}

int main(){
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(Job);
    printSeq(arr,n);
}