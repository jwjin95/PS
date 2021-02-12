#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define MAXN 200050
int N,M,ans[MAXN];
vector<int> adj[MAXN];
bool checked[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=1 ; i<=N ; i++){
        while(1){
            int a; cin >> a;
            if(!a) break;
            adj[i].push_back(a);
        }
    }
    fill_n(ans,N+5, -1);

    queue<pair<int,int>> q;
    cin >> M;
    for(int i=0 ; i<M ; i++){
        int a; cin >> a;
        q.push({a, 0});
        ans[a] = 0;
        checked[a] = true;
    }

    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();

        vector<int> to_check;
        for(auto v: adj[top.first]){
            if(checked[v]) continue;
            if(ans[v] == -1){
                int surr = 0;
                for(int i=0 ; i<adj[v].size() ; i++){
                    if(checked[adj[v][i]] &&ans[adj[v][i]] != -1 && ans[adj[v][i]] <= top.second) surr += 1;
                }
                if(surr >= (adj[v].size()+1)/2){
                    q.push({v, top.second+1});
                    ans[v] = top.second+1;
                    to_check.push_back(v);
                }
            }

            
        }

        for(int i=0 ; i<to_check.size() ; i++){
            checked[to_check[i]] = true;
        }

    }
    for(int i=1 ; i<=N ; i++) cout << ans[i] << " ";
}