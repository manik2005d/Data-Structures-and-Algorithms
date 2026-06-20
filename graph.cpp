#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *l; // int *arr

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V]; // arr = new int [V]
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void bfs() {
        queue<int> q;
        vector<bool> visited(V, false);
        q.push(0);
        visited[0] = true;
        while(q.size()>0){
            cout << q.front() << " ";
            for (int x : l[q.front()]){
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }
            q.pop();
        }
        cout << endl;
    }

    void dfsHelper(vector<bool> &visited, int i){
        cout << i << " ";
        visited[i] = true;
        for (int x : l[i]){
            if(!visited[x]){
                dfsHelper(visited, x);
            }
        }
    }
    void dfs() {
        vector<bool> visited(V, false);
        dfsHelper(visited, 0);
        cout << endl;
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.bfs();
    g.dfs();
    return 0;
}