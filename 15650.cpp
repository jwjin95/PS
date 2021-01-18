#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 10

int n, m;
int ans[MAXN];


void solve(int level, int num){
    if(level == m){
        for(int i=0 ; i<m ; i++) cout << ans[i] << " ";
        cout <<"\n";
        return;
    }
    for(int i=num ; i<=n ; i++){
        ans[level] = i;
        solve(level+1, i+1);


    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    solve(0,1);

}