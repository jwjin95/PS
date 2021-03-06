#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 10

int n,m;
bool isUsed[MAXN];
int ans[MAXN];

void solve(int level){
    if(level == m){
        for(int i=0 ; i<m ; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }
    for(int i=1 ; i<=n ; i++){
        if(isUsed[i]) continue;
        ans[level] = i;
        isUsed[i] = true;
        solve(level+1);
        isUsed[i] = false;
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    solve(0);

}