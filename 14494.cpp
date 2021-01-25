#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050
long long n,m,opt[MAXN][MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    opt[1][1]=1;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(i==1 && j==1) opt[i][j]=1;
            else opt[i][j] = (opt[i-1][j] + opt[i][j-1] + opt[i-1][j-1])%1000000007;
        }
    }
    cout << opt[n][m];
}