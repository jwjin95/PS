#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1520

int N;
long long opt[MAXN][3];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    opt[1][0]=0; opt[1][1]=1; opt[1][2]=1;
    opt[2][0]=2; opt[2][1]=1; opt[2][2]=1;
    for(int i=3 ; i<N ; i++){
        opt[i][0]=(opt[i-1][1]+opt[i-1][2])%1000000007;
        opt[i][1]=(opt[i-1][0]+opt[i-1][2])%1000000007;
        opt[i][2]=(opt[i-1][0]+opt[i-1][1])%1000000007;
    }
    cout << opt[N-1][1];

}