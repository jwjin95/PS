#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050

struct edge{
    int src,dst,val;
};
bool cmp(edge a, edge b){
    return a.val < b.val;
}
vector<edge> v;
int N,M,K,parent[MAXN];
int ans=0;
bool chk;
vector<int> elec;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    chk = false;
    x = find(x);
    y = find(y);
    if(x == y) return;
    parent[x] = y;
    chk = true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    // inputs
    cin >> N >> M >> K;
    for(int i=0 ; i<=N ; i++) parent[i] = i;
    for(int i=0 ; i<K ; i++) {
        int powerplant;
        cin >> powerplant;
        elec.push_back(powerplant);
    }
    for(int i=0 ; i<M ; i++){
        edge e;
        cin >> e.src >> e.dst >> e.val;
        v.push_back(e);
    }

    for(int i=0 ; i<K ; i++){
        parent[elec[i]] = elec[0];
    }

    sort(v.begin(), v.end(), cmp);
    int cnt=0;
    for(int i=0 ; i<M ; i++){
        merge(v[i].src, v[i].dst);
        if(chk) ans += v[i].val;
    }


    cout << ans;
}