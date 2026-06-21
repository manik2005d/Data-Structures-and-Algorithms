#include <iostream>
#include <list>
#include <vector>
#include <queue>
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
    }

    bool isCycleDFSHelper(int curr, vector<bool> &visited, vector<bool> &recPath){
        visited[curr] = true;
        recPath[curr] = true;

        for (int v : l[curr]){
            if(!visited[v]){
                if(isCycleDFSHelper(v, visited, recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[curr] = false;
        return false;
    }
    bool isCycleDFS(){
        vector<bool> visited(V, false);
        vector<bool> recPath(V, false);
        for (int i=0;i<V;i++){
            if(!visited[i]){
                if(isCycleDFSHelper(0, visited, recPath)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(4);
    g.addedge(1,0);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(3,0);

    cout << g.isCycleDFS() << endl;
}