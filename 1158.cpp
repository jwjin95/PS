#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N,K;
queue<int> q;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> K;
    for(int i=1 ; i<=N ; i++) q.push(i);

    int cnt = 0;
    
    while(!q.empty()){
        cnt++;
        int a = q.front();    
        q.pop();
        if(cnt % K == 0){
            ans.push_back(a);
            continue;
        }
        q.push(a);
    }
    cout << '<';
    for(int i=0 ; i<ans.size()-1 ; i++) cout << ans[i] << ", ";
    cout << ans[N-1] <<'>';
}