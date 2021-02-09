#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 40050
int N,M, par[MAXN][17], depth[MAXN], cost[MAXN][17];
vector<pair<int,int>> adj[MAXN];

void dfs(int u, int p, int d, int c){
    par[u][0] = p;
    depth[u] = d;
    cost[u][0] = c;
    for(auto v: adj[u]){
        if(v.first == p) continue;
        dfs(v.first, u, d+1, v.second);
    }
}

int lca(int u, int v){
    int ret = 0;
    if(depth[u] < depth[v]) swap(u,v);
    for(int k=16 ; k>=0 ; k--){
        if(depth[u] - depth[v] >= (1<<k)) {
            ret += cost[u][k];
            u = par[u][k];
            
        }
    }
    
    if(u == v) return ret;

    for(int k=16 ; k>=0 ; k--){
        if(par[u][k] != par[v][k]){
            ret += cost[u][k] + cost[v][k];
            u = par[u][k];
            v = par[v][k];
        }
    }
    ret += cost[u][0] + cost[v][0];

    return ret;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N-1 ; i++){
        int u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    dfs(1,0,0,0);

    for(int k=1 ; k<17 ; k++){
        for(int i=1 ; i<=N ; i++){
            par[i][k] = par[par[i][k-1]][k-1];
            cost[i][k] = cost[i][k-1] + cost[par[i][k-1]][k-1];
        }
    }
    
    cin >> M;
    for(int i=0 ; i<M ; i++){
        int u,v; cin >> u >> v;
        cout << lca(u,v) << '\n';
    }

}