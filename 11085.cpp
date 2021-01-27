#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050

int p,w,c,v,ans,parent[MAXN];
struct edge{
    int src,dst,val;
};
vector<edge> vec;

bool cmp(edge a, edge b){
    return a.val > b.val;
}

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    parent[x] = y;

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> p >> w >> c >> v;

    for(int i=0 ; i<=p ; i++) parent[i]=i;

    for(int i=0 ; i<w ; i++){
        edge e;
        cin >> e.src >> e.dst >> e.val;
        vec.push_back(e);
    }

    sort(vec.begin(), vec.end(), cmp);

    // for(int i=0 ; i<vec.size() ; i++){
    //     cout << vec[i].src << vec[i].dst << " " << vec[i].val << endl;
    // }

    for(int i=0 ; i<w ; i++){
        merge(vec[i].src, vec[i].dst);
        if(find(c) == find(v)){
            ans = vec[i].val;
            break;
        }

    }
    cout << ans;
}