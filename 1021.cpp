#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N,M,ans=0,num[55];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;
    for(int i=1 ; i<=N ; i++) q.push(i);

    for(int i=0 ; i<M ; i++){
        cin >> num[i];
    }
    int idx=0, cnt=0;
    while(M--){
        while(!q.empty() && q.front()!=num[idx]){
            int v = q.front();
            q.pop();
            q.push(v);
            cnt++;
        }
        ans += min(cnt, (int)q.size()-cnt);

        q.pop();
        cnt=0;
        idx++;
    }

    cout << ans;
}