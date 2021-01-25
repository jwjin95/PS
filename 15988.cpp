#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1000050

long long opt[MAXN], MOD = 1000000009;
long long T,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    opt[1] = 1;
    opt[2] = 2;
    opt[3] = 4;
    cin >> T;
    for(int i=4 ; i<=1000000 ; i++){
        opt[i] = opt[i-1]+opt[i-2]+opt[i-3];
        opt[i] %= MOD;
    }
    for(int i=0 ; i<T ; i++){
        cin >> n;
        cout << opt[n] << "\n";
    }
    
}