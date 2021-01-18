#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 20

int n, ans=0;
bool isUsed_col[MAXN]={0,};
bool isUsed_rightup[2*MAXN]={0,};
bool isUsed_rightdown[2*MAXN]={0,};

void solve(int row){
    if(row == n){
        ans++;
        return;
    }
    for(int j=0 ; j<n ; j++){
        if(isUsed_col[j] || isUsed_rightup[row+j] || isUsed_rightdown[row-j+n-1]) continue;
        isUsed_col[j] = true;
        isUsed_rightup[row+j] = true;
        isUsed_rightdown[row-j+n-1] = true;
        solve(row+1);
        isUsed_col[j] = false;
        isUsed_rightup[row+j] = false;
        isUsed_rightdown[row-j+n-1] = false;

    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    solve(0);
    cout << ans;
}