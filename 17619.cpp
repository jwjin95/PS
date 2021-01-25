#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 100050

int n,q;
int x1,x2,y;
int parent[MAXN];
struct logs {
    int s,f, idx;
};
vector<logs> v;

bool cmp(logs a, logs b){
    return a.s < b.s;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> q;
    for(int i=1 ; i<=n ; i++) parent[i] = i;

    for(int i=0 ; i<n ; i++){
        cin >> x1 >> x2 >> y;
        v.push_back({x1,x2,i+1});
    }
    sort(v.begin(), v.end(), cmp);

    for(int i=1 ; i<v.size() ; i++){
        if(v[i].s <= v[i-1].f){
            merge(v[i-1].idx, v[i].idx);
            v[i].f = max(v[i-1].f, v[i].f); // 다른 부분
        }

    }

    int q1,q2;
    for(int i=0 ; i<q ; i++){
        cin >> q1 >> q2;
        if(find(q1) == find(q2)) cout << 1 << "\n";
        else cout << 0 << "\n";

    }
    // for(int i=0 ; i<v.size() ; i++){
    //     cout << v[i].s << " " << v[i].f << " "<< v[i].idx << endl;
    // }
    // for(int i=0 ; i<=n ; i++){
    //     cout << parent[i];
    // }
    // cout << endl;

}