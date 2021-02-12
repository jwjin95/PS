#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int tree[1000050][2];

void build(int cur, int node){
    if(cur < node){
        if(tree[node][0] == 0) tree[node][0] = cur;
        else build(cur, tree[node][0]);
    }
    else if(cur > node){
        if(tree[node][1] == 0) tree[node][1] = cur;
        else build(cur, tree[node][1]);
    }

}

void postorder(int u){
    if(tree[u][0] != 0) postorder(tree[u][0]);
    if(tree[u][1] != 0) postorder(tree[u][1]);
    cout << u << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int root; cin >> root;
    while(1){
        int n; cin >> n;
        if(cin.eof() == true) break;
        build(n, root);
    }
    postorder(root);
}