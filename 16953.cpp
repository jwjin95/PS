#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

long long A,B;

long long BFS(long long u){
    queue<pair<long long,long long>> q;
    q.push({u,1});
    
    while(!q.empty()){
        pair<long long,long long> top = q.front();
        q.pop();

        if(top.first == B) return top.second;
        if(top.first > B) continue;

        q.push({top.first * 2, top.second+1});
        q.push({top.first*10+1, top.second+1});

    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> A >> B;

    cout << BFS(A);
}