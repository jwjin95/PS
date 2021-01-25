#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 5050
#define INF 1235467891
int N,opt[MAXN];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<=N ; i++) opt[i]=INF;
    opt[3] = 1; opt[5]=1; 
    for(int i=6 ; i<=N ; i++){
        int a=INF,b=INF;
        if(opt[i-3] != INF) a=opt[i-3]+1;
        if(opt[i-5] != INF) b=opt[i-5]+1;
        opt[i]=min(a,b);

    }
    if(opt[N]==INF) cout << -1;
    else cout << opt[N];
}