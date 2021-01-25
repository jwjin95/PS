#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050
int N,opt[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    opt[1]=1;
    opt[2]=2;

    for(int i=3 ; i<=N ; i++) opt[i]=(opt[i-1]+opt[i-2])%10007;
    cout << opt[N];

}