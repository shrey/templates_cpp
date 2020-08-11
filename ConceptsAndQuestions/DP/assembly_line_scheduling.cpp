


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

#define NUM_LINE 2
#define NUM_STATION 4

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


int carAssembly(int a[][4], int t[][4], int e[], int x[]){
    int T1[4], T2[4];
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];
    for(int i = 1; i<4; i++){
        T1[i] = min(T2[i-1] + t[1][i], T1[i-1]) + a[0][i];
        T2[i] = min(T1[i-1] + t[0][i], T2[i-1]) + a[1][i];
    }
    return min(T2[3]+x[1], T1[3]+x[0]);

}


int main()
{
    int a[][4] = {{4, 5, 3, 2},
                            {2, 10, 1, 4}};
    int t[][4] = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    cout << carAssembly(a, t, e, x);

    return 0;
}