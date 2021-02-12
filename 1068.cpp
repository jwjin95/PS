#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N,c,par[55],ans=0,root;
vector<int> child[55];

void find(int u){
    if(child[u].size() == 0){
        ans += 1;
        return;
    } 
    for(auto v: child[u]){
        find(v);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> N;
    for(int i=0 ; i<N ; i++){
        int p; cin >> p;
        if(p == -1) {
            root = i;
            continue;
        }
        par[i] = p;
        // cout << i << "par: " << p << endl;
        child[p].push_back(i);
    }

    cin >> c;
    if(c == root){
        cout << 0;
        return 0;
    }
    int parent = par[c];
    // cout << "parent:" << parent << par[4] << endl;
    for(int i=0 ; i<child[parent].size() ; i++){
        if(child[parent][i] == c) {
            child[parent].erase(child[parent].begin()+i);
            break;
        }
    }

    find(root);

    cout << ans;
}