#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 500050

int n,m,ans=0;
int parent[MAXN];
int a,b;
vector<pair<int,int>> v;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x); y = find(y);
    parent[x] = y;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    for(int i=0 ; i<n ; i++) parent[i] = i;

    for(int i=0 ; i<m ; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i=0 ; i<m ; i++){
        if(find(v[i].first) == find(v[i].second)){
            ans = i+1;
            break;
        }
        merge(v[i].first, v[i].second);

    }
    if(ans == 1) ans = 0;
    cout << ans;

}