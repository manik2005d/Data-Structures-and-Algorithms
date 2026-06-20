#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public: 
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addedge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool isCycleDFSHelper(vector<bool> &visited, int src, int parent){
        visited[src] = true;
        for (int u : l[src]){
            if(!visited[u]){
                bool temp = isCycleDFSHelper(visited, u, src);
                if(temp){
                    return true;
                }
            }else{
                if(u!=parent){
                    return true;
                }
            }
        }
        return false;

    }
    bool isCycleDFS(){
        vector<bool> visited(V, false);
        for (int i=0;i<V;i++){
            if(!visited[i]){
                return isCycleDFSHelper(visited, i, -1);
            }
        }
        return false;
    }

    bool isCycleBFS(){
        queue<pair<int, int>> q;
        vector<bool> visited(V, false);
        q.push({0,-1});
        visited[0] = true;
        while(q.size()>0){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (int u : l[curr]){
                if(!visited[u]){
                    visited[u] = true;
                    q.push({u, curr});
                }else{
                    if(u!=parent){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(1,2);
    g.addedge(3,4);

    cout << g.isCycleDFS() << endl;
    cout << g.isCycleBFS() << endl;
}