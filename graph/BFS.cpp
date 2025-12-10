#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    //BFS
    void BreathFirstSearch(){
        queue<int> q;
        vector<bool> visited(V,false);
        q.push(0);
        visited[0] = true;

        while(q.size() > 0) {
            int src = q.front();
            q.pop();

            cout<<src<<" ";

            for(int v : l[src]) { //v--->immediate neighbors 
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
   
};
int main(){
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.BreathFirstSearch();
    return 0;
}