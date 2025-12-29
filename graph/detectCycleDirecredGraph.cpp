#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isCycleDirDFS(int curr,vector<bool> &vis, vector<bool> &recursionPath){
        vis[curr] = true;
        recursionPath[curr] = true;

        for(int v : l[curr]) {
            if(!vis[v]) {
                if(isCycleDirDFS(v,vis,recursionPath)) {
                    return true;
                }
            } else if(recursionPath[v]) {
                return true;
            }
        }
        recursionPath[curr] = false;
        return false;
    }

    public:
    Graph(int V) {
        this->V;
        l= new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
    }

    bool isCycle() {
        vector<bool> vis(V,false);
        vector<bool> recpath(V,false);

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(isCycleDirDFS(i,vis,recpath)) {
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph g(4);

    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<g.isCycle();
    return 0;
}