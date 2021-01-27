#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 1050

int n,m,k,f,t,parent[MAXN];
char c;
bool chk;

struct edge{
    int src, dst, val;
    char color;
};

vector<edge> v;

bool cmp_less(edge a, edge b){
    return a.val<b.val;
}
bool cmp_greater(edge a, edge b){
    return a.val>b.val;
}

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



    cin >> n >> m >> k;
    while(n){
        int min=0, max=0;
        for(int i=0 ; i<m ; i++){
            edge e;
            cin >> e.color >> e.src >> e.dst;
            v.push_back(e);
        }

        for(int i=0 ; i<v.size() ; i++){
            if(v[i].color == 'B') v[i].val = 1;
            else v[i].val = 0;
        }

        // min
        for(int i=0 ; i<=n ; i++) parent[i]=i;

        sort(v.begin(), v.end(), cmp_less);

        for(int i=0 ; i<m ; i++){
            merge(v[i].src, v[i].dst);
            if(chk) min += v[i].val;

        }
        // max
        for(int i=0 ; i<=n ; i++) parent[i]=i;

        sort(v.begin(), v.end(), cmp_greater);

        for(int i=0 ; i<m ; i++){
            merge(v[i].src, v[i].dst);
            if(chk) max += v[i].val;

        }

        if(min <= k && k <= max) cout << 1 <<'\n';
        else cout << 0 << '\n';

        v.clear();
        cin >> n >> m >> k;
    }
    
}