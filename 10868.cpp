#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 100050

int N,M,D[MAXN][20],lg[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;

    for(int i=1 ; i<=N ; i++){
        cin >> D[i][0];
    }

    for(int k=1 ; k<20 ; k++){
        for(int i=1 ; i + (1<<k) -1 <= N ; i++){
            D[i][k] = min(D[i][k-1], D[i+(1<<k-1)][k-1]);
        }
    }

    lg[1]=0;
    for(int i=2 ; i<=N ; i++) lg[i] = lg[i/2] + 1;

    for(int i=0 ; i<M ; i++){
        int l,r; cin >> l >> r;
        int k = lg[r-l+1];
        int ans = min(D[l][k], D[r-(1<<k)+1][k]);
        cout << ans << '\n';
    }

}