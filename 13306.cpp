#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAXN 200050

int N,Q,parent[MAXN];
struct edge {
    int src,dst;
};
struct query{
    int flag,x,y;
};
vector<query> q;
vector<string> ans;

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

    cin >> N >> Q;
    for(int i=0 ; i<=N ; i++) parent[i] = i;

    int tmp[N+1];
    for(int i=2 ; i<=N ; i++){
        cin >> tmp[i];
    }
    
    for(int i=0 ; i<N-1+Q ; i++){
        query qry;
        cin >> qry.flag;
        if(qry.flag){
            cin >> qry.x >> qry.y;
            q.push_back(qry);
        } else {
            cin >> qry.x;
            q.push_back(qry);
        }
    }
    for(int i=q.size()-1 ; i>=0 ; i--){
        if(q[i].flag){
            if(find(q[i].x)==find(q[i].y)) ans.push_back("YES\n");
            else ans.push_back("NO\n");
        }else {
            merge(q[i].x, tmp[q[i].x]);
        }

    }

    for(int i=ans.size()-1 ; i>=0 ; i--){
        cout << ans[i];
    }


}


  
    // for(int i=0 ; i<N-1+Q ; i++){
    //     int flag;
    //     cin >> flag;
    //     if(flag){
    //         int a,b;
    //         cin >> a >> b;
    //         if(find(a) == find(b)){
    //             cout << "YES\n";
    //         }else cout << "NO\n";

    //     }else {
    //         int e;
    //         cin >> e;
    //         parent[e] = e;
    //     }


    // }