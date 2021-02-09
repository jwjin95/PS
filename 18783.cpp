#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

#define MAXN 100050
ll N,M,K,T[MAXN][31];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M >> K;

    int tmp[N+1];
    for(int i=1 ; i<=N ; i++) tmp[i] = i;
    for(int i=0 ; i<M ; i++){
        int l,r; cin >> l >> r;
        reverse(tmp+l, tmp+r+1);
    }
    
    for(int i=1 ; i<=N ; i++){
        T[i][0] = tmp[i];
    }

    for(int k=1 ; k<31 ; k++){
        for(int i=1 ; i<=N ; i++){
            T[i][k] = T[T[i][k-1]][k-1];
        }
    }
    // for(int i=1 ; i<=N ; i++) cout << T[i][1]; cout << endl;
    // for(int i=1 ; i<=N ; i++) cout << tmp[i]; cout << endl;
    // for(int i=1 ; i<=N ; i++) cout << T[i][0]; 

    int ans[MAXN];
    for(int i=1 ; i<=N ; i++) ans[i] = i;

    for(int k=30 ; k>=0 ; k--){
        if(K >= (1<<k)){
            for(int i=1 ; i<=N ; i++) ans[i] = T[ans[i]][k];
            K -= (1<<k);
        }
    }
    for(int i=1 ; i<=N ; i++){
        cout << ans[i] << '\n';
    }
}