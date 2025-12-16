// The idea is quite similar to DFS-based cycle detection, but here we use Breadth First Search (BFS)
// instead of recursion. BFS explores the graph level by level, 
// ensuring that each node is visited in the shortest possible way.
//  It also helps avoid deep recursion calls, making it more memory-efficient for large graphs.

// In BFS, we also maintain a visited array to mark nodes that have been explored and a parent tracker
// to remember from which node we reached the current one.
// If during traversal we encounter a node that is already visited and 
// is not the parent of the current node, it means we’ve found a cycle in the graph.

#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
        Graph(int V){
            this->V =V;
            l = new list<int> [V];
        }
        
        void addEdge(int u, int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }

        bool isCycleUndirectedBFS(int src, vector<bool> &visited){
            queue<pair<int , int>> q;

            q.push({src,-1});
            visited[src] =true;

            while(q.size()> 0) {
                int u=q.front().first;
                int ParentU = q.front().second;
                q.pop();

                list<int> neighbors = l[u];
                for(int v: neighbors) {
                    if(!visited[v]) {
                        q.push({v,u});
                        visited[v] = true;
                    }else if(v != ParentU) {
                        return true;
                    }
                }
            }
            return false;
        } 

        bool isCycle() {
            vector<bool> visited(V,false);

            for(int i=0; i<V; i++) {
                if(!visited[i]) {
                    if(isCycleUndirectedBFS(i,visited)) {
                        return true;
                    }
                }
            }
            return false;
        }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    
    cout<<g.isCycle() <<endl;
    return 0;
}