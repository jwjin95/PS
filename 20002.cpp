#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N,a,pre[305][305],ans=-1234567891;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            cin >> a;
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a;
        }
    }

    for(int i=1 ; i<=N ; i++){
        for(int j=0 ; j<N-i+1 ; j++){
            for(int k=0 ; k<N-i+1 ; k++){
                ans = max(ans, pre[j+i][k+i] - pre[j][k+i] - pre[j+i][k] + pre[j][k]);
            }
        }
    }
    cout << ans;
}