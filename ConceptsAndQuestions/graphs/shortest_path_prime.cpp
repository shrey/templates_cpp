//https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/



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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

vector<bool> generatePrimes();

class Graph{
    umap<int,list<int> > adjlist;
    public:
        void addEdge(int x, int y){
            adjlist[x].pb(y);
            adjlist[y].pb(x);
        }
        int bfs(int start, int dest){
            umap<int,bool> visited;
            umap<int,int> dist;
            dist[start] = 0;
            queue<int> q;
            q.push(start);
            while(!q.empty()){
                int p = q.front();
                q.pop();
                for(auto it: adjlist[p]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                        dist[it] = dist[p]+1;

                    }
                    if(it == dest){
                        return dist[it];
                    }
                }
            }
            return -1;
        }

};



vector<bool> generatePrimes(){
    int n = 9999;
    vector<bool> prime(10000, true);
    for(int p = 2; p*p<=n; p++){
        if(prime[p]){
            for(int i = (p*p); i<=n; i+=p){
                prime[i] = false;
            }
        }
    }
    return prime;
}


bool isEdge(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    int c = 0;
    if(s1[0] != s2[0]){
        c++;
    }
    if(s1[1] != s2[1]){
        c++;
    }
    if(s1[2] != s2[2]){
        c++;
    }
    if(s1[3] != s2[3]){
        c++;
    }
    if(c == 1){
        return true;
    }
    return false;
}

void solve(int s, int e){
    vector<bool> prime = generatePrimes();
    if(s == e){
        cout<<0<<endl;
        return;
    }
    Graph g;
    for(int i = s; i<e; i++){
        for(int j = i+1; j<=e; j++){
            if(prime[i] && prime[j] && isEdge(i,j)){
                g.addEdge(i,j);
            }
        }
    }
    cout<<g.bfs(s,e)<<endl;
}

int main(){
    int s,e;
    cin>>s>>e;
    solve(s,e);
}