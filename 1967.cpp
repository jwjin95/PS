#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 10050
int n,max=-1,far_node,max_weight=0;
vector<pair<int,int>> adj[MAXN];

void DFS(int p, int u, int cur_weight){
    if(cur_weight > max_weight) {
        max_weight = cur_weight;
        far_node = u;
    }

    for(auto v: adj[u]){
        if(v.first == p) continue;
        DFS(u,v.first,cur_weight+v.second);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    for(int i=0 ; i<n-1 ; i++){
        int p,c,w; cin >> p >> c >> w;
        adj[p].push_back({c,w});
        adj[c].push_back({p,w});
    }

    DFS(0,1,0);
    max_weight = 0;
    DFS(0,far_node,0);
    cout << max_weight;
}