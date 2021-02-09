#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 200050

int m,D[MAXN][20], lg[500050],Q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> m;
    for(int i=1 ; i<=m ; i++) cin >> D[i][0];

    for(int k=1 ; k<20 ; k++){
        for(int i=1 ; i <= m ; i++){
            D[i][k] = D[D[i][k-1]][k-1];
        }
    }
    lg[1]=0;
    for(int i=2 ; i<500050 ; i++) lg[i] = lg[i/2] + 1;

    cin >> Q;
    for(int i=0 ; i<Q ; i++){
        int n,x; cin >> n >> x;
        int k = lg[n];
        int ans = x;
        for(int j=k ; j>=0 ; j--){
            if(n >= (1<<j)){
                ans = D[ans][j];
                n -= (1<<j);
            }

        }  
        cout << ans << '\n';
    }

}