#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define MAXN 10050

int n, s, d, opt_value;
vector<int> adj[MAXN];
int weight[MAXN];
int opt[MAXN][2];
vector<int> ans;

void fillTable(int bef, int cur){
    int max_included = 0;
    int max_notincluded = 0;
    for(int node : adj[cur]){
        if(node == bef) continue;
        fillTable(cur, node);
        max_notincluded += max(opt[node][0], opt[node][1]);
        max_included += opt[node][0];
    }
    opt[cur][0] = max_notincluded;
    opt[cur][1] = max_included + weight[cur];
}

void trace(int bef, int cur, int optimal){
    if(opt[cur][1] == optimal){
        ans.push_back(cur);
        for(int node : adj[cur]){
            if(node == bef) continue;
            trace(cur, node, opt[node][0]);
        }
    } else if(opt[cur][0] == optimal){
        for(int node : adj[cur]){
            if(node == bef) continue;
            trace(cur, node, max(opt[node][0], opt[node][1]));
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i=1 ; i<=n ; i++) cin >> weight[i];
    for(int i=0 ; i<n-1 ; i++){
        cin >> s >> d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    fillTable(0,1);


    // for(int i=0 ; i<=7 ; i++){
    //     for(int j=0 ; j<2 ; j++){
    //         cout << opt[i][j];
    //     }
    //     cout << endl;
    // }
    opt_value = max(opt[1][0], opt[1][1]);
    trace(0, 1, opt_value);
    sort(ans.begin(), ans.end());
    
    cout << opt_value << endl;
    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }

}