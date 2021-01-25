#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1000050
int n,INF=1234567891;
int opt[MAXN]={0,};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    
    for(int i=2 ; i<=n ; i++){
        int a=INF,b=INF,c=INF;
        if(i % 3 == 0){
            a = opt[i/3]+1;
        }
        if(i % 2 == 0){
            b = opt[i/2]+1;
        }
        c=opt[i-1]+1;
        opt[i] = min({a,b,c});
    }
    cout << opt[n];
    
}