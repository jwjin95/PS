#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int T,N,M,ans;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> T;
    while(T--){
        cin >> N >> M;
        queue<pair<int,int>> q;
        vector<int> imp;
        for(int i=0 ; i<N ; i++){
            int importance; 
            cin >> importance;
            imp.push_back(importance);
            q.push({i,importance});
        }
        sort(imp.begin(), imp.end(), greater<int>());

        int idx=0, cnt = 0;
        while(!q.empty()) {
            if(q.front().second == imp[idx]){
                cnt++; idx++;
                if(q.front().first == M){
                    cout << cnt << '\n';
                    break;
                }
                q.pop();
                
            }else{   
                pair<int,int> a = q.front();
                q.pop();
                q.push(a);

            }
        }


    }
    
}