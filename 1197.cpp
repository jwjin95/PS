#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 10050

int parent[MAXN];
int V,E,ans=0;
bool valid;

struct edge{
    int src,dst,val;
};

vector<edge> v;

bool cmp(edge a, edge b){
    return a.val < b.val;
}

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    valid = false;
    x = find(x);
    y = find(y);
    if(x == y){
        return;
    }
    parent[x] = y;
    valid = true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> V >> E;
    for(int i=0 ; i<=V ; i++) parent[i]=i;
    for(int i=0 ; i<E ; i++){
        edge e;
        cin >> e.src >> e.dst >> e.val;
        v.push_back(e);
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=0 ; i<E ; i++){
        merge(v[i].src, v[i].dst);
        if(valid){
            ans += v[i].val;
        }
    }

    cout << ans;   
}