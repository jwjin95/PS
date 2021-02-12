#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N,K;
bool checked[100050];

int BFS(int u){
    queue<pair<int,int>> q;
    q.push({u,0});
    checked[u] = true;

    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();

        if(top.first == K) return top.second;
        if(top.first < 0) continue;

        if(top.first-1 >= 0 && !checked[top.first-1]){
            q.push({top.first-1, top.second+1});
            checked[top.first-1]=true;
        }
        if(top.first+1 <= 100000 && !checked[top.first+1]){
            q.push({top.first+1, top.second+1});
            checked[top.first+1] = true;
        }
        if(top.first*2 <= 100000 && !checked[top.first*2]){
            q.push({top.first*2, top.second+1});
            checked[top.first*2] = true;
        }

    }
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> K;
    cout << BFS(N);
}