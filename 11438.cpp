#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 100050

int N,M,parent[MAXN][20], depth[MAXN];
vector <int> adj[MAXN];

void dfs(int n, int p, int d){
    parent[n][0] = p;
    depth[n] = d;
    for(auto v: adj[n]){
        if(v == p) continue;
        dfs(v,n,d+1);
    } 

}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a,b);

    for(int k=19 ; k>=0 ; k--){
        if(depth[a] - depth[b] >= (1<<k)) a = parent[a][k];
    }
    if(a == b) return a;

    for(int k=19 ; k>=0 ; k--){
        if(parent[a][k] != parent[b][k]){
            a = parent[a][k];
            b = parent[b][k];
        }
    }

    return parent[a][0];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N-1 ; i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0,0);

    for(int k=1 ; k<20 ; k++){
        for(int i=1 ; i<=N ; i++){
            parent[i][k] = parent[parent[i][k-1]][k-1];
        }
    }

    cin >> M;
    for(int i=0 ; i<M ; i++){
        int a,b; cin >> a >> b;
        cout << lca(a,b) << '\n';
    }    
    
}