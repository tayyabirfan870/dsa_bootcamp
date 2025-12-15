// Using Depth First Search - O(V+E) Time and O(V) Space
// The idea is to use Depth First Search (DFS). When we start a DFS from a node, 
// we visit all its connected neighbors one by one. If during this traversal, 
// we reach a node that has already been visited before, it indicates that there might be a cycle,
//  since we’ve come back to a previously explored vertex.
// However, there’s one important catch.
// In an undirected graph, every edge is bidirectional. That means, if there’s an edge from u → v, 
// then there’s also an edge from v → u.
// So, while performing DFS, from u, we go to v. From v, we again see u as one of its neighbors. 
// Since u is already visited, it might look like a cycle — but it’s not.

// To avoid this issue, we keep track of the parent node — the node from which we reached 
// the current node in DFS. When we move from u to v, we mark u as the parent of v. Now,
//  while checking the neighbors of v, If a neighbor is not visited, we continue DFS for that node.
//  If a neighbor is already visited and not equal to the parent, 
//  it means there’s another path that leads back to this node — and hence, a cycle exists.

#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int V;
    list<int> *l;
    bool isCycleHelper(int src, int parent,vector<bool> &visited){
        visited[src] =true;
        list<int> neighbors =l[src];

        for(int v: neighbors){
            if(!visited[v]){
                if(isCycleHelper(v,src,visited)){
                    return true;
                }
            }else if(v != parent){
                return true;
            }
        }
        return false;
    }
public:
    Graph(int V) {
        this->V = V;
        l= new list<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycle(){
        vector<bool> visited(V,false);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(isCycleHelper(i,-1,visited)){
                    return true;
                }
            }
        }
        return false;
    }

};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    // g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(3,4);

    cout<<g.isCycle()<<endl;


    return 0;
}
