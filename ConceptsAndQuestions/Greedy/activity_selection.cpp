// You are given n activities with their start and finish times.
// Select the maximum number of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time.


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

struct activity{
    int start;
    int end;
};

bool compare(activity &a, activity &b){
    return (a.end<b.end);
}

int compute(activity a[], int n){
    sort(a,a+n,compare);
    int s = a[0].start;
    int e = a[0].end;
    cout<<"("<<s<<","<<e<<")"<<" ";
    int count = 1;
    for(int i = 1; i<n; i++){
        if(a[i].start>=e){
            s = a[i].start;
            e = a[i].end;
            cout<<"("<<s<<","<<e<<")"<<" ";
            count++;
        }
    }
    return count;
}


int main(){
    activity a[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n = sizeof(a)/sizeof(activity);
    compute(a,n);

}