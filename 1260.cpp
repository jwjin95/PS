#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define MAXN 1050

int N,M,V;
bool checked[MAXN];
vector<int> adj[MAXN];

void DFS(int u){
    checked[u] = true;
    cout << u << " ";

    for(auto v: adj[u]){
        if(checked[v]) continue;
        DFS(v);
    }

}

void BFS(int u){
    queue<int> q;
    q.push(u);
    checked[u] = true;
    while(!q.empty()){
        int top = q.front();
        cout << top << " ";
        q.pop();
        for(auto v: adj[top]){
            if(checked[v]) continue;
            checked[v] = true;
            q.push(v);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M >> V;
    for(int i=0 ; i<M ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1 ; i<=N ; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    DFS(V);
    for(int i=1 ; i<=N ; i++) checked[i] = false;
    cout << '\n';
    BFS(V);

}