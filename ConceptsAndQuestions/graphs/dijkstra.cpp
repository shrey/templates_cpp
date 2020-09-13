

//Shrey Dubey

//Contact Me at wshrey09@gmail.com

//time complexity:- O(VlogE) V->vertices, E->edges

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
#define mp make_pair

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

template<typename T>

class Graph{

    umap<T,list<pair<T,int> > > adjlist;

    public:

    void addedge(T x, T y, int dist, bool bider = true){
        adjlist[x].push_back(mp(y,dist));
        if(bider)
            adjlist[y].push_back(mp(x,dist));
    }

    void printAdjList(){
        for(auto it: adjlist){
            cout<<it.first<<" -> ";
            for(auto it2: it.second){
                cout<<"("<<it2.first<<","<<it2.second<<") ";
            }cout<<endl;
        }
    }

    //to display path, keep a parent hmap and update it when updating distances

    void dijkstraSSSp(T src){
        umap<T,int> dist;
        for(auto it: adjlist){
            dist[it.first] = INT_MAX;
        }
        set<pair<int,T> > s;

        dist[src] = 0;
        s.insert(mp(0,src));
        while(!s.empty()){
            //find the pair at front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            //iterate over neighbours of current node
            for(auto childPair: adjlist[node]){
                if((childPair.second + nodeDist) < dist[childPair.first]){
                    //update the node, we do it by deleteing it from set and inserting new pair
                    T dest = childPair.first;
                    auto f = s.find(mp(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest] = childPair.second + nodeDist;
                    s.insert(mp(dist[dest], dest));
                }
            }
        }
        for(auto it: dist){
            cout<<it.first<< " is located at a distance of "<<it.second<<" from "<<src<<endl;
        }
    }

};

int main(){
    Graph<string> g;
    g.addedge("Amritsar", "Delhi", 1);
    g.addedge("Amritsar", "Jaipur", 4);
    g.addedge("Jaipur", "Delhi", 2);
    g.addedge("Jaipur", "Mumbai", 8);
    g.addedge("Bhopal", "Agra", 2);
    g.addedge("Mumbai", "Bhopal", 3);
    g.addedge("Agra", "Delhi", 1);
    // g.printAdjList();
    g.dijkstraSSSp("Amritsar");
}