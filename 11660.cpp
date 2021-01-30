#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050

int N,M,arr[MAXN][MAXN],pre[MAXN][MAXN];
int a,b,c,d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;

    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            cin >> arr[i][j];
            pre[i][j] = pre[i-1][j] + pre[i][j-1] + arr[i][j] - pre[i-1][j-1];
        }
    }
    for(int i=0 ; i<M ; i++){
        cin >> a >> b >> c >> d;
        cout << pre[c][d]-pre[c][b-1]-pre[a-1][d]+pre[a-1][b-1] << "\n";
    }
    
}