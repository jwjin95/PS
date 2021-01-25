#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 500050

long long N,M;
vector<pair<long long, long long>> range;
long long P[MAXN],X[MAXN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N >> M;

    int l,r;
    for(int i=1 ; i<=N ; i++){
        cin >> l >> r;
        range.push_back({l,r});
    }
    int p,x;
    for(int i=1 ; i<=M ; i++){
        cin >> P[i] >> X[i];
    }

    


}