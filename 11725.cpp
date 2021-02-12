#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 100050
int N,parent[MAXN];
vector<int> adj[MAXN];

void DFS(int p, int u){
    parent[u] = p;
    for(auto v: adj[u]){
        if(v == p) continue;
        DFS(u,v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N-1 ; i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(0,1);
    for(int i=2 ; i<=N ; i++){
        cout << parent[i] << '\n';
    }

}