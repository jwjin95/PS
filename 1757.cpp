#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 10000000

int N,M,D[MAXN];
int opt[10050][550][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;
    for(int i=1 ; i<=N ; i++) cin >> D[i];

    for(int i=1 ; i<=N ; i++){
        for(int j=0 ; j<=M ; j++){
            if(j==0){
                opt[i][j][0] = max({opt[i-1][j+1][0],opt[i-1][j+1][1],opt[i-1][j][0]});
            } else if(j==1){
                opt[i][j][0] = max(opt[i-1][j+1][0],opt[i-1][j+1][1]);
                opt[i][j][1] = opt[i-1][j-1][0]+D[i];                  //max(opt[i-1][j-1][0],opt[i-1][j-1][1])+D[i];
            } else {
                opt[i][j][0] = max(opt[i-1][j+1][0],opt[i-1][j+1][1]);
                opt[i][j][1] = opt[i-1][j-1][1]+D[i];
            }


        }
    }


    
    cout << opt[N][0][0];
}