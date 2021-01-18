#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 30

int n, s;
int arr[MAXN];
int ans;

void solve(int idx, int sum) {
    if(idx == n) {
        if(sum == s){
            ans++;
            return;
        } else return;
    }
    solve(idx+1, sum+arr[idx]);
    solve(idx+1, sum);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> s;
    for(int i=0 ; i<n ; i++) cin >> arr[i];

    solve(0, 0);
    if(s == 0) ans -= 1;
    
    cout << ans;

}